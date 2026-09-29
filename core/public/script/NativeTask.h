#pragma once

#include <coroutine>
#include <exception>
#include <memory>
#include <optional>
#include <stdexcept>
#include <utility>

// A scheduler resumes the suspended leaf. Call/return uses the language's
// coroutine continuation; there is no VM return stack or program-counter switch.
template <class Result> class SferaCoroutine
{
    struct ResumeState
    {
        std::coroutine_handle<> leaf{};
    };

public:
    struct promise_type;
    using Handle = std::coroutine_handle<promise_type>;

    struct promise_type
    {
        ResumeState *scheduler = nullptr;
        std::coroutine_handle<> caller = std::noop_coroutine();
        std::optional<Result> result;
        std::exception_ptr error;

        SferaCoroutine get_return_object() noexcept { return SferaCoroutine(Handle::from_promise(*this)); }
        std::suspend_always initial_suspend() const noexcept { return {}; }
        void unhandled_exception() noexcept { error = std::current_exception(); }
        void return_value(Result value) { result.emplace(std::move(value)); }

        struct FinalAwaiter
        {
            bool await_ready() const noexcept { return false; }
            std::coroutine_handle<> await_suspend(Handle current) const noexcept
            {
                auto &promise = current.promise();
                if (promise.scheduler != nullptr)
                    promise.scheduler->leaf = promise.caller;
                return promise.caller;
            }
            void await_resume() const noexcept {}
        };
        FinalAwaiter final_suspend() const noexcept { return {}; }
    };

    struct Suspend
    {
        bool await_ready() const noexcept { return false; }
        void await_suspend(Handle current) const
        {
            auto *scheduler = current.promise().scheduler;
            if (scheduler == nullptr)
                throw std::logic_error("Coroutine has no scheduler");
            scheduler->leaf = current;
        }
        void await_resume() const noexcept {}
    };

    SferaCoroutine() noexcept = default;
    SferaCoroutine(const SferaCoroutine &) = delete;
    SferaCoroutine &operator=(const SferaCoroutine &) = delete;
    SferaCoroutine(SferaCoroutine &&other) noexcept
        : handle(std::exchange(other.handle, {})), scheduler(std::move(other.scheduler)) {}
    SferaCoroutine &operator=(SferaCoroutine &&other) noexcept
    {
        if (this != &other)
        {
            reset();
            handle = std::exchange(other.handle, {});
            scheduler = std::move(other.scheduler);
        }
        return *this;
    }
    ~SferaCoroutine() { reset(); }

    explicit operator bool() const noexcept { return static_cast<bool>(handle); }
    bool done() const noexcept { return !handle || handle.done(); }
    void reset() noexcept
    {
        if (auto owned = std::exchange(handle, {}))
            owned.destroy();
        scheduler.reset();
    }
    bool resume()
    {
        if (!handle)
            throw std::logic_error("Cannot resume an empty coroutine");
        if (!handle.done())
        {
            if (!scheduler)
            {
                scheduler = std::make_unique<ResumeState>();
                scheduler->leaf = handle;
                handle.promise().scheduler = scheduler.get();
            }
            scheduler->leaf.resume();
        }
        rethrow();
        return !handle.done();
    }
    const Result &result() const
    {
        if (!handle || !handle.done())
            throw std::logic_error("Coroutine has not completed");
        rethrow();
        return *handle.promise().result;
    }

    class Awaiter
    {
    public:
        explicit Awaiter(Handle value) noexcept : child(value) {}
        Awaiter(const Awaiter &) = delete;
        ~Awaiter() { if (child) child.destroy(); }
        bool await_ready() const noexcept { return !child || child.done(); }
        std::coroutine_handle<> await_suspend(Handle parent)
        {
            if (!child || child.promise().scheduler != nullptr)
                throw std::logic_error("Coroutine is already scheduled");
            child.promise().caller = parent;
            child.promise().scheduler = parent.promise().scheduler;
            if (child.promise().scheduler == nullptr)
                throw std::logic_error("Parent coroutine has no scheduler");
            child.promise().scheduler->leaf = child;
            return child;
        }
        Result await_resume()
        {
            if (!child)
                throw std::logic_error("Cannot await an empty coroutine");
            if (child.promise().error)
                std::rethrow_exception(child.promise().error);
            return std::move(*child.promise().result);
        }
    private:
        Handle child;
    };

    Awaiter operator co_await() &&
    {
        if (scheduler)
            throw std::logic_error("Cannot await an independently scheduled coroutine");
        return Awaiter(std::exchange(handle, {}));
    }

private:
    explicit SferaCoroutine(Handle value) noexcept : handle(value) {}
    void rethrow() const
    {
        if (handle && handle.promise().error)
            std::rethrow_exception(handle.promise().error);
    }
    Handle handle{};
    std::unique_ptr<ResumeState> scheduler;
};
