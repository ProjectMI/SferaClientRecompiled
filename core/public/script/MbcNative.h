#pragma once

#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <coroutine>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <exception>
#include <functional>
#include <format>
#include <limits>
#include <memory>
#include <optional>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include "numeric/Numeric.h"
#include "script/MbcCommands.h"

namespace SphereScripts
{
using Builtin = SferaMbcRuntimeBuiltin;

template <int Type> struct Reference
{
    static constexpr int type = Type;
    std::uint32_t base{};
    std::uint32_t begin{};
    std::uint32_t end{};
    friend bool operator==(const Reference &, const Reference &) = default;
};
using String = Reference<1>;
using StringRef = Reference<2>;
using IntRef = Reference<17>;
using IntRefRef = Reference<18>;
using FloatRef = Reference<33>;
using FloatRefRef = Reference<34>;
using Address = Reference<48>;
using AddressRef = Reference<49>;

template <class T> struct IsReference : std::false_type {};
template <int Type> struct IsReference<Reference<Type>> : std::true_type {};
template <class T> concept ReferenceType = IsReference<std::remove_cvref_t<T>>::value;

template <ReferenceType To, ReferenceType From> constexpr To referenceCast(From value) noexcept
{
    return {value.base, value.begin, value.end};
}

// Type erasure is restricted to engine APIs and genuinely dynamic calls. Native
// method bodies use ordinary scalars, typed references and native member arrays.
struct Value
{
    int type = 16;
    Address bits{};
    bool present = false;

    Value() = default;
    Value(std::int32_t value) : type(16), bits{std::bit_cast<std::uint32_t>(value), 0, 0}, present(true) {}
    Value(std::uint32_t value) : type(16), bits{value, 0, 0}, present(true) {}
    Value(std::int8_t value) : Value(std::int32_t{value}) {}
    Value(std::uint8_t value) : Value(std::int32_t{value}) {}
    Value(bool value) : Value(std::int32_t{value}) {}
    Value(float value) : type(32), bits{std::bit_cast<std::uint32_t>(value), 0, 0}, present(true) {}
    template <ReferenceType T> Value(T value) : type(T::type), bits(referenceCast<Address>(value)), present(true) {}
};

inline std::uint32_t word(Value value) noexcept { return value.bits.base; }
inline std::uint32_t word(std::int32_t value) noexcept { return std::bit_cast<std::uint32_t>(value); }
inline std::uint32_t word(std::uint32_t value) noexcept { return value; }
inline std::uint32_t word(float value) noexcept { return std::bit_cast<std::uint32_t>(value); }
inline std::uint32_t word(std::int8_t value) noexcept { return word(std::int32_t{value}); }
inline std::uint32_t word(bool value) noexcept { return value ? 1u : 0u; }
template <ReferenceType T> std::uint32_t word(T value) noexcept { return value.base; }
template <class T> std::int32_t integerBits(T value) noexcept { return std::bit_cast<std::int32_t>(word(value)); }
template <class T> float realBits(T value) noexcept { return std::bit_cast<float>(word(value)); }
template <class T> bool truth(T value) noexcept { return word(value) != 0; }

inline std::int32_t integer(Value value) noexcept
{
    return value.type == 32 ? SferaNumeric::truncateInt(realBits(value)) : integerBits(value);
}
inline std::int32_t integer(float value) noexcept { return SferaNumeric::truncateInt(value); }
template <class T> std::int32_t integer(T value) noexcept { return integerBits(value); }
inline float real(Value value) noexcept { return value.type == 32 ? realBits(value) : SferaNumeric::real32(integerBits(value)); }
inline float real(float value) noexcept { return value; }
template <class T> float real(T value) noexcept { return SferaNumeric::real32(integerBits(value)); }

inline Address payload(Value value) noexcept { return value.bits; }
template <ReferenceType T> Address payload(T value) noexcept { return referenceCast<Address>(value); }
template <class T> requires (!ReferenceType<T> && !std::is_same_v<T, Value>) Address payload(T value) noexcept { return {word(value), 0, 0}; }
inline Address pointer(Value value) noexcept { return value.type % 16 ? value.bits : Address{value.bits.base, 0, 0}; }
template <ReferenceType T> Address pointer(T value) noexcept
{
    return T::type % 16 ? referenceCast<Address>(value) : Address{value.base, 0, 0};
}
template <class T> requires (!ReferenceType<T> && !std::is_same_v<T, Value>) Address pointer(T value) noexcept { return {word(value), 0, 0}; }

template <class To, class From> To argumentValue(From source)
{
    if constexpr (std::is_same_v<To, Value>)
        return Value(source);
    else if constexpr (std::is_same_v<To, float>)
        return real(source);
    else if constexpr (std::is_same_v<To, std::int32_t>)
        return integer(source);
    else if constexpr (std::is_same_v<To, std::int8_t>)
        return std::bit_cast<std::int8_t>(std::uint8_t(word(integer(source))));
    else if constexpr (ReferenceType<To>)
    {
        const Value value(source);
        const auto bits = value.type == 0 || value.type == 16 || value.type == 32 ? Address{word(integer(value)), 0, 0} : value.bits;
        return referenceCast<To>(bits);
    }
}

template <class To, class From> To storedValue(From source)
{
    if constexpr (std::is_same_v<To, Value>)
        return Value(source);
    else if constexpr (std::is_same_v<To, float>)
        return realBits(source);
    else if constexpr (std::is_same_v<To, std::int32_t>)
        return integerBits(source);
    else if constexpr (std::is_same_v<To, std::int8_t>)
        return std::bit_cast<std::int8_t>(std::uint8_t(word(source)));
    else if constexpr (std::is_same_v<To, std::uint8_t>)
        return std::uint8_t(word(source));
    else if constexpr (ReferenceType<To>)
        return referenceCast<To>(payload(source));
}

template <class Left, class Right> std::int32_t add32(Left left, Right right) noexcept { return integerBits(word(left) + word(right)); }
template <class Left, class Right> std::int32_t subtract32(Left left, Right right) noexcept { return integerBits(word(left) - word(right)); }
template <class Left, class Right> std::int32_t multiply32(Left left, Right right) noexcept { return integerBits(word(left) * word(right)); }
template <class Left, class Right> std::int32_t divide32(Left left, Right right)
{
    const auto divisor = integerBits(right);
    if (!divisor)
        throw std::domain_error("Division by zero");
    const std::int64_t dividend = integerBits(left);
    return integerBits(SferaNumeric::lowWord(dividend / divisor));
}
template <class Left, class Right> std::int32_t remainder32(Left left, Right right)
{
    const auto divisor = integerBits(right);
    if (!divisor)
        throw std::domain_error("Division by zero");
    const std::int64_t dividend = integerBits(left);
    return integerBits(SferaNumeric::lowWord(dividend % divisor));
}
template <class T> std::int32_t negate32(T value) noexcept { return integerBits(0u - word(value)); }
template <class T> std::int32_t storedByte(T value) noexcept { return std::uint8_t(word(value)); }

struct Argument
{
    Value value;
    Address source{};
    Argument() = default;
    Argument(Value value, Address source = {}) : value(value), source(source) {}
    template <class T> Argument(T value) : value(value) {}
};
template <class T> Argument byReference(T value, Address source) { return {Value(value), source}; }

class Module;
class Host;
template <class T> class Task;
struct Context
{
    Module *module{};
    std::string_view function;
};
struct NativeCall
{
    Context caller;
    Module *callee{};
    std::string_view program;
    std::uint32_t depth{};
    int programIndex = -1;
};
struct Execution
{
    std::coroutine_handle<> suspended{};
    Context context{};
    std::uint64_t work{};
    bool yielded{};
    bool finished{};
    bool cancelled{};
    Module *rootModule{};
    std::string rootProgram;
    int rootProgramIndex = -1;
    std::uint32_t depth{};
    std::vector<NativeCall> calls;
};
void activate(Context context, Execution *execution);
std::shared_ptr<Module> retain(Module &module);

struct PromiseBase
{
    std::shared_ptr<Module> owner;
    Context context;
    Context parentContext;
    Execution *execution{};
    std::coroutine_handle<> continuation{};
    std::exception_ptr error;
    std::suspend_always initial_suspend() const noexcept { return {}; }
    void unhandled_exception() noexcept { error = std::current_exception(); }
    struct Final
    {
        bool await_ready() const noexcept { return false; }
        template <class Promise> void await_suspend(std::coroutine_handle<Promise> handle) const noexcept
        {
            auto &promise = handle.promise();
            if (promise.continuation)
            {
                try { activate(promise.parentContext, promise.execution); }
                catch (...) { promise.error = std::current_exception(); }
                if (promise.execution)
                {
                    promise.execution->suspended = promise.continuation;
                    promise.execution->yielded = false;
                }
                return;
            }
            if (promise.execution)
            {
                promise.execution->suspended = {};
                promise.execution->yielded = false;
            }
        }
        void await_resume() const noexcept {}
    };
    Final final_suspend() const noexcept { return {}; }
};
template <class T> struct PromiseResult : PromiseBase
{
    std::optional<T> result;
    template <class U> void return_value(U &&value) { result.emplace(std::forward<U>(value)); }
};
template <> struct PromiseResult<void> : PromiseBase
{
    void return_void() const noexcept {}
};

template <class T> class Task
{
  public:
    using value_type = T;
    struct promise_type : PromiseResult<T>
    {
        Task get_return_object() { return Task(std::coroutine_handle<promise_type>::from_promise(*this)); }
    };
    using Handle = std::coroutine_handle<promise_type>;
    Task() = default;
    explicit Task(Handle handle) : handle_(handle) {}
    Task(const Task &) = delete;
    Task &operator=(const Task &) = delete;
    Task(Task &&other) noexcept : handle_(std::exchange(other.handle_, {})) {}
    Task &operator=(Task &&other) noexcept
    {
        if (this != &other)
        {
            reset();
            handle_ = std::exchange(other.handle_, {});
        }
        return *this;
    }
    ~Task() { reset(); }
    void reset() noexcept
    {
        if (handle_)
            std::exchange(handle_, {}).destroy();
    }
    bool valid() const noexcept { return bool(handle_); }
    bool done() const noexcept { return !handle_ || handle_.done(); }
    Task &&in(Module &module, std::string_view function = {}) &&
    {
        auto &context = handle_.promise().context;
        context.module = &module;
        if (!function.empty())
            context.function = function;
        handle_.promise().owner = retain(module);
        return std::move(*this);
    }
    void start(Execution &execution)
    {
        if (!handle_)
            throw std::logic_error("Starting an empty native script continuation");
        handle_.promise().execution = &execution;
        execution.suspended = handle_;
        execution.context = handle_.promise().context;
        execution.yielded = false;
        execution.finished = false;
    }
    T result()
    {
        auto &promise = handle_.promise();
        if (!handle_.done())
            throw std::logic_error("Native script continuation has not completed");
        if (promise.error)
            std::rethrow_exception(promise.error);
        if constexpr (!std::is_void_v<T>)
        {
            if (!promise.result)
                throw std::logic_error("Native script function returned without a value");
            return std::move(*promise.result);
        }
    }
    struct Awaiter
    {
        Handle child;
        explicit Awaiter(Handle value) : child(value) {}
        Awaiter(Awaiter &&other) noexcept : child(std::exchange(other.child, {})) {}
        Awaiter(const Awaiter &) = delete;
        ~Awaiter() { if (child) child.destroy(); }
        bool await_ready() const noexcept { return false; }
        template <class Promise> void await_suspend(std::coroutine_handle<Promise> parent)
        {
            auto &promise = child.promise();
            promise.continuation = parent;
            promise.parentContext = parent.promise().context;
            promise.execution = parent.promise().execution;
            if (!promise.context.module)
                promise.context = promise.parentContext;
            activate(promise.context, promise.execution);
            if (!promise.execution)
                throw std::logic_error("Awaiting a native script outside its scheduler");
            promise.execution->suspended = child;
            promise.execution->yielded = false;
        }
        T await_resume()
        {
            if (child.promise().error)
                std::rethrow_exception(child.promise().error);
            if constexpr (!std::is_void_v<T>)
            {
                if (!child.promise().result)
                    throw std::logic_error("Native script function returned without a value");
                return std::move(*child.promise().result);
            }
        }
    };
    Awaiter operator co_await() && { return Awaiter(std::exchange(handle_, {})); }

  private:
    Handle handle_{};
};

inline void resume(Execution &execution)
{
    execution.yielded = false;
    while (execution.suspended && !execution.yielded && !execution.finished)
    {
        auto current = std::exchange(execution.suspended, {});
        current.resume();
        if (!execution.suspended && !current.done() && !execution.finished)
            throw std::logic_error("Native coroutine suspended without a continuation");
    }
}

struct Continuation
{
    Execution execution;
    Task<Value> task;
    bool running{};
};

template <class T> struct IsTask : std::false_type {};
template <class T> struct IsTask<Task<T>> : std::true_type {};
struct Suspend
{
    bool await_ready() const noexcept { return false; }
    template <class Promise> void await_suspend(std::coroutine_handle<Promise> handle) const
    {
        auto &promise = handle.promise();
        if (!promise.execution)
            throw std::logic_error("Suspending a script outside its scheduler");
        promise.execution->suspended = handle;
        promise.execution->context = promise.context;
        promise.execution->yielded = true;
    }
    void await_resume() const noexcept {}
};

enum class ProgramAction { Start, StartChild, Stop, Pause, Resume };
struct Method;
// EndProgram terminates the scheduled invocation, including nested source calls.
// The scheduler owns and destroys the suspended frame chain; no C++ exception is
// used for this ordinary control-flow operation.
struct Finish
{
    bool await_ready() const noexcept { return false; }
    template <class Promise> void await_suspend(std::coroutine_handle<Promise> handle) const
    {
        auto *execution = handle.promise().execution;
        if (!execution)
            throw std::logic_error("Finishing a script outside its scheduler");
        execution->suspended = {};
        execution->yielded = false;
        execution->finished = true;
    }
    [[noreturn]] void await_resume() const
    {
        throw std::logic_error("Resuming a completed native script program");
    }
};
enum class Entry : std::uint16_t;
std::string_view entryName(Entry entry) noexcept;
Entry entryNamed(std::string_view name) noexcept;
struct RegionDefinition
{
    std::uint8_t index{};
    std::int8_t flags{};
    Entry program{};
    std::span<const std::int8_t> format;
};
struct Program
{
    Entry name{};
    std::int8_t initialState{};
    std::uint8_t priority{};
    Entry cleanup{};
};
class Host
{
  public:
    virtual ~Host() = default;
    Context current;
    Execution *execution{};
    virtual Module &selectModule(Module &caller, bool (*accepts)(Module &)) = 0;
    virtual Value invokeEngine(Builtin command, std::span<const Argument> arguments) = 0;
    virtual Task<Value> callProcess(Module &caller, bool mainProcess, std::vector<Argument> arguments) = 0;
    virtual Address mapObject(void *address, std::size_t size, const void *owner) = 0;
    virtual void forgetObject(const void *owner) noexcept = 0;
    virtual std::span<std::byte> memory(Address address, std::size_t size) = 0;
    virtual void programAction(Module &module, std::string_view program, ProgramAction action) = 0;
    virtual bool alive(const Module &module) const noexcept = 0;
    virtual void warning(std::string_view message) = 0;
    virtual void selectContext(Context context)
    {
        if (context.module && !alive(*context.module))
            throw std::runtime_error("Native script process no longer exists");
        current = context;
    }
    virtual void halt() = 0;
    [[noreturn]] void missingEngineResult(Builtin command, std::span<const Argument> arguments) const;
    template <class R, class... Args> R invoke(Builtin command, Args &&...args)
    {
        const std::array<Argument, sizeof...(Args)> arguments{Argument(std::forward<Args>(args))...};
        const auto value = invokeEngine(command, arguments);
        if constexpr (!std::is_void_v<R>)
        {
            if (!value.present)
                missingEngineResult(command, arguments);
            // A VM result is already in the engine's declared type. Do not
            // introduce an implicit numeric conversion by assigning the C++ type.
            return storedValue<R>(value);
        }
    }
    template <class... Args> Task<Value> call(Module &caller, bool mainProcess, Args &&...args)
    {
        return callProcess(caller, mainProcess, std::vector<Argument>{Argument(std::forward<Args>(args))...});
    }
    void checkpoint(std::uint32_t work = 1);
    void validate(Address &address, std::size_t width, bool allowNull = false)
    {
        const bool pointerFits = allowNull || (address.base >= 4 && address.base < UINT32_MAX - 3u);
        const bool rangeFits = !address.begin || (address.base >= address.begin && address.base <= address.end &&
                              (!width || width - 1u <= address.end - address.base));
        if (pointerFits && rangeFits)
            return;
        warning("Native script slice boundary error");
        if (!address.base || !address.begin || (address.base >= address.begin && address.base <= address.end))
            return;
        if (integerBits(address.base) < integerBits(address.begin))
            address.begin = address.base;
        else if (integerBits(address.base + SferaNumeric::lowWord(width) - 1u) > integerBits(address.end))
            address.end = address.base + SferaNumeric::lowWord(width) - 1u;
    }
    template <class T> T read(Address address)
    {
        T value;
        const auto bytes = memory(address, sizeof(T));
        std::memcpy(&value, bytes.data(), sizeof(T));
        return value;
    }
    template <class T> void write(Address address, const T &value, std::size_t sourceWidth = sizeof(T))
    {
        validate(address, sourceWidth);
        const auto bytes = memory(address, sizeof(T));
        std::memcpy(bytes.data(), &value, sizeof(T));
    }
    Address element(Address base, std::int32_t index, std::uint32_t stride, std::int32_t count,
                    bool absolute, std::uint32_t sourceWidth, bool bounded)
    {
        if (bounded)
        {
            const auto size = count < 0 ? 0u - word(count) : word(count);
            if (index < 0 || word(index) >= size)
            {
                warning("Array boundary error in native script");
                const auto last = integerBits(size - 1u);
                index = absolute ? (index < 0 ? 0 : last) : (index >= 0 && last < 0 ? 0 : last);
            }
        }
        base.base += stride * word(index);
        if (absolute)
            base = {base.base, base.base, base.base + sourceWidth - 1u};
        else if (!bounded)
            validate(base, 1, true);
        return base;
    }
    Address indirect(Address value)
    {
        validate(value, 1, true);
        return value;
    }
    Address field(Address base, std::uint32_t offset, std::uint32_t width)
    {
        base.base += offset;
        validate(base, 1, true);
        return {base.base, base.base, base.base + width - 1u};
    }
};

class FunctionScope
{
    Host &host_;
    Context previous_;
    Execution *execution_;
  public:
    FunctionScope(Module &module, std::string_view name);
    ~FunctionScope() noexcept
    {
        if (execution_)
            --execution_->depth;
        if (host_.execution == execution_)
        {
            try { host_.selectContext(previous_); }
            catch (...) { host_.current = previous_; }
        }
    }
};

struct Method
{
    Module *owner{};
    Entry key{};
    std::string_view name;
    std::string_view program;
    Task<Value> (*execute)(const Method &, std::vector<Argument>){};
    bool reentrant{};
    int parameterCapacity{};
    bool external{};
    Value (*invokeSync)(const Method &, std::span<const Argument>){};
    std::shared_ptr<const void> binding;

    explicit operator bool() const noexcept { return owner != nullptr && execute != nullptr; }
    void validate(std::size_t count) const
    {
        if (!*this)
            throw std::runtime_error("Native script entry is unavailable");
        const auto capacity = std::size_t(parameterCapacity < 0 ? -parameterCapacity : parameterCapacity);
        if (count > capacity || (parameterCapacity >= 0 && count != capacity))
            throw std::invalid_argument("Wrong number of native script parameters");
    }
    Value invoke(std::span<const Argument> arguments) const
    {
        validate(arguments.size());
        if (!invokeSync)
            throw std::logic_error("Synchronous call to a suspending native function");
        return invokeSync(*this, arguments);
    }
    Task<Value> start(std::vector<Argument> arguments) const;
};

class Module : public std::enable_shared_from_this<Module>
{
    Host &host_;
    std::string_view name_;
    std::uint32_t tag_;
    std::vector<Method> methods_;
    bool methodsSealed_{};
    std::vector<std::pair<std::size_t, const Method *>> callbacks_;
    std::span<const std::span<const Program>> programs_;
    std::span<const std::span<const Entry>> names_;
    std::span<const RegionDefinition> regions_;
  public:
    std::uint32_t processId = UINT32_MAX;
    std::uint64_t lifetime{};
    Module(Host &host, std::string_view name, std::uint32_t tag) : host_(host), name_(name), tag_(tag) {}
    Module(const Module &) = delete;
    Module &operator=(const Module &) = delete;
    virtual ~Module() { host_.forgetObject(this); }
    Host &host() const noexcept { return host_; }
    std::string_view moduleName() const noexcept { return name_; }
    std::uint32_t tag() const noexcept { return tag_; }
    const Method *method(Entry key, bool external = false) const noexcept
    {
        const auto found = std::lower_bound(methods_.begin(), methods_.end(), key,
                                           [](const Method &method, Entry value) { return method.key < value; });
        return found != methods_.end() && found->key == key && (!external || found->external) ? std::addressof(*found) : nullptr;
    }
    virtual Method entry(Entry key, bool external = false)
    {
        const auto found = method(key, external);
        return found ? *found : Method{};
    }
    Method localMethod(std::string_view name, bool external = false) { return entry(entryNamed(name), external); }
    void define(Method method)
    {
        if (methodsSealed_)
            throw std::logic_error("Cannot change bound entries after module initialization");
        if (method.owner != this || !method)
            throw std::logic_error("Native entry belongs to a different module");
        methods_.push_back(std::move(method));
    }
    void bindPrograms(std::span<const std::span<const Program>> programs,
                      std::span<const std::span<const Entry>> names, std::span<const RegionDefinition> regions)
    {
        std::sort(methods_.begin(), methods_.end(), [](const Method &left, const Method &right) { return left.key < right.key; });
        if (std::adjacent_find(methods_.begin(), methods_.end(), [](const Method &left, const Method &right) { return left.key == right.key; }) != methods_.end())
            throw std::logic_error("Duplicate native entry in a module");
        methodsSealed_ = true;
        programs_ = programs;
        names_ = names;
        regions_ = regions;
    }
    void bindCallback(std::size_t index, Entry key)
    {
        if (!methodsSealed_)
            throw std::logic_error("Callbacks require initialized native entries");
        callbacks_.emplace_back(index, method(key, true));
    }
    std::span<const std::span<const Program>> programs() const noexcept { return programs_; }
    std::span<const std::pair<std::size_t, const Method *>> callbacks() const noexcept { return callbacks_; }
    std::span<const RegionDefinition> regions() const noexcept { return regions_; }
    virtual Address position() { return {}; }
    virtual void initializeMembers() = 0;
    std::size_t functionCount() const noexcept
    {
        std::size_t count = 0;
        for (const auto segment : names_)
            count += segment.size();
        return count;
    }
    std::string_view functionNameAt(std::size_t index) const noexcept
    {
        for (const auto segment : names_)
        {
            if (index < segment.size())
                return entryName(segment[index]);
            index -= segment.size();
        }
        return {};
    }
    template <class T> Address address(T &object, std::size_t offset = 0, std::size_t width = sizeof(T))
    {
        if (offset > sizeof(T) || width > sizeof(T) - offset)
            throw std::out_of_range("Native member view is outside its object");
        auto result = host_.mapObject(std::addressof(object), sizeof(T), this);
        result.base += SferaNumeric::lowWord(offset);
        result.begin = result.base;
        result.end = result.base + SferaNumeric::lowWord(width) - 1u;
        return result;
    }
    template <class T, std::size_t Extent> Address address(std::span<T, Extent> object, std::size_t offset = 0, std::size_t width = 0)
    {
        const auto bytes = object.size_bytes();
        if (offset > bytes)
            throw std::out_of_range("Native span offset is outside its object");
        if (width == 0)
            width = bytes - offset;
        if (width > bytes - offset)
            throw std::out_of_range("Native span view is outside its object");
        auto result = host_.mapObject(object.data(), bytes, this);
        result.base += SferaNumeric::lowWord(offset);
        result.begin = result.base;
        result.end = result.base + SferaNumeric::lowWord(width) - 1u;
        return result;
    }
    template <ReferenceType R, class T> R reference(T &object, std::size_t offset = 0, std::size_t width = sizeof(T))
    {
        return referenceCast<R>(address(object, offset, width));
    }
    void control(std::string_view name, ProgramAction action) { host_.programAction(*this, name, action); }
};

inline void Host::checkpoint(std::uint32_t work)
{
    if (!execution)
        return;
    constexpr std::uint64_t limit = 3500000;
    if (!execution->cancelled && (execution->work += work) <= limit)
        return;
    // Capture context before coroutine exception propagation restores its caller.
    const auto reason = execution->cancelled ? "Native script process was cancelled" : "Endless native script cycle";
    throw std::runtime_error(std::format("{}; module={}; process={}; function={}; root={}; work={}; limit={}",
        reason, current.module ? current.module->moduleName() : std::string_view{},
        current.module ? current.module->processId : UINT32_MAX, current.function,
        execution->rootProgram, execution->work, limit));
}

[[noreturn]] inline void Host::missingEngineResult(Builtin command, std::span<const Argument> arguments) const
{
    std::string message = "Engine call did not produce its required result; builtin=";
    switch (command)
    {
    case Builtin::Window: message += "Window"; break;
    case Builtin::Text: message += "Text"; break;
    case Builtin::CloseFile: message += "CloseFile"; break;
    case Builtin::RebaseSlice: message += "RebaseSlice"; break;
    case Builtin::System: message += "System"; break;
    case Builtin::Configuration: message += "Configuration"; break;
    case Builtin::ContainerCommand: message += "ContainerCommand"; break;
    case Builtin::ContainerManagement: message += "ContainerManagement"; break;
    case Builtin::ParseText: message += "ParseText"; break;
    default: message += "Engine"; break;
    }
    message += "(" + std::to_string(SferaNumeric::enumBits(command)) + ")";
    if (!arguments.empty() && (command == Builtin::Window || command == Builtin::System || command == Builtin::Configuration))
        message += "; selector=" + std::to_string(integer(arguments.front().value));
    message += "; argc=" + std::to_string(arguments.size());
    if (current.module)
    {
        message += "; module=";
        message += current.module->moduleName();
        message += "; process=" + std::to_string(current.module->processId);
    }
    message += "; function=";
    message += current.function;
    if (execution && !execution->rootProgram.empty())
        message += "; root=" + execution->rootProgram;
    message += "; args=[";
    for (std::size_t index = 0; index < std::min<std::size_t>(arguments.size(), 8); ++index)
    {
        if (index)
            message += ", ";
        const auto &value = arguments[index].value;
        message += std::to_string(value.type) + ":" + std::to_string(value.bits.base);
    }
    if (arguments.size() > 8)
        message += ", ...";
    message += "]";
    throw std::runtime_error(message);
}

inline std::shared_ptr<Module> retain(Module &module)
{
    return module.shared_from_this();
}
inline FunctionScope::FunctionScope(Module &module, std::string_view name) : host_(module.host()), previous_(host_.current), execution_(host_.execution)
{
    host_.selectContext({&module, name});
    if (execution_)
    {
        const auto baseline = execution_->calls.empty() ? 0u : execution_->calls.back().depth;
        if (execution_->depth - baseline >= 21)
        {
            host_.selectContext(previous_);
            throw std::runtime_error("Native script local call depth exhausted");
        }
        ++execution_->depth;
    }
}
inline void activate(Context context, Execution *execution)
{
    if (!context.module)
        throw std::logic_error("Native continuation has no module owner");
    auto &host = context.module->host();
    host.execution = execution;
    host.selectContext(context);
}
// One deferred entry frame serves every binding. Per-function thunks remain
// ordinary functions instead of instantiating a coroutine for each owner.
inline Task<Value> executeMethod(Method method, std::vector<Argument> arguments)
{
    co_return co_await method.execute(method, std::move(arguments));
}
inline Task<Value> Method::start(std::vector<Argument> arguments) const
{
    validate(arguments.size());
    return executeMethod(*this, std::move(arguments)).in(*owner, program);
}
inline Task<Value> completedValue(Value value)
{
    co_return value;
}
template <class T> Task<Value> taskValue(Task<T> task)
{
    if constexpr (std::is_void_v<T>)
    {
        co_await std::move(task);
        co_return Value{};
    }
    else
        co_return co_await std::move(task);
}

template <class T> T nativeArgument(std::span<const Argument> arguments, std::size_t index)
{
    return argumentValue<T>(index < arguments.size() ? arguments[index].value : Value(std::int32_t{}));
}
template <class T = void> T invalidArguments()
{
    throw std::invalid_argument("Wrong number of native script parameters");
}

template <Entry Key> bool provides(Module &module)
{
    return module.method(Key, true) != nullptr;
}

template <class T> struct NativeResult
{
    using Type = T;
    static constexpr bool asynchronous = false;
};
template <class T> struct NativeResult<Task<T>>
{
    using Type = T;
    static constexpr bool asynchronous = true;
};
template <class T> struct NativeSignature;
template <class R, class... Args> struct NativeSignature<R (*)(Args...)> : NativeResult<R>
{
    using Arguments = std::tuple<Args...>;
    using Owner = std::remove_reference_t<std::tuple_element_t<0, Arguments>>;
    static constexpr std::size_t implicitOwner = 1;
    static R apply(R (*function)(Args...), Args... arguments)
    {
        return function(std::forward<Args>(arguments)...);
    }
};
template <class R, class Class, class... Args> struct NativeSignature<R (Class::*)(Args...)> : NativeResult<R>
{
    using Arguments = std::tuple<Args...>;
    using Owner = Class;
    static constexpr std::size_t implicitOwner = 0;
    static R apply(R (Class::*function)(Args...), Class &owner, Args... arguments)
    {
        return (owner.*function)(std::forward<Args>(arguments)...);
    }
};

// The boundary adapter is shared by a C++ signature, not instantiated again
// for every module or literal configuration. Its references belong to one
// module instance; ordinary source calls bypass this adapter entirely.
template <class Function, std::size_t Arity, class Fields, class Settings> struct NativeBinding;
template <class Function, std::size_t Arity, std::size_t... Fields, std::size_t... Settings>
struct NativeBinding<Function, Arity, std::index_sequence<Fields...>, std::index_sequence<Settings...>>
{
    using Signature = NativeSignature<Function>;
    template <std::size_t Index> using Formal = std::tuple_element_t<Signature::implicitOwner + Index, typename Signature::Arguments>;
    template <std::size_t Index> using Parameter = std::remove_cvref_t<Formal<sizeof...(Fields) + Index>>;
    using State = std::tuple<Formal<Fields>...>;
    Function function;
    State state;
    std::array<std::uint32_t, sizeof...(Settings)> settings;

    NativeBinding(Function target, State capturedState, std::array<std::uint32_t, sizeof...(Settings)> literalSettings)
        : function(target), state(capturedState), settings(literalSettings) {}

    template <std::size_t... Arguments>
    decltype(auto) call(Module &module, std::span<const Argument> arguments, std::index_sequence<Arguments...>) const
    {
        return Signature::apply(function, static_cast<typename Signature::Owner &>(module), std::get<Fields>(state)...,
            nativeArgument<Parameter<Arguments>>(arguments, Arguments)...,
            storedValue<Parameter<Arity + Settings>>(settings[Settings])...);
    }
    static Value invoke(const Method &method, std::span<const Argument> arguments)
    {
        const auto &binding = *static_cast<const NativeBinding *>(method.binding.get());
        if constexpr (std::is_void_v<typename Signature::Type>)
        {
            binding.call(*method.owner, arguments, std::make_index_sequence<Arity>{});
            return {};
        }
        else
            return binding.call(*method.owner, arguments, std::make_index_sequence<Arity>{});
    }
    static Task<Value> execute(const Method &method, std::vector<Argument> arguments)
    {
        if constexpr (Signature::asynchronous)
        {
            const auto &binding = *static_cast<const NativeBinding *>(method.binding.get());
            return taskValue(binding.call(*method.owner, arguments, std::make_index_sequence<Arity>{}));
        }
        else
            return completedValue(invoke(method, arguments));
    }
};

template <class Function, class State> consteval bool packedNativeState()
{
    using Signature = NativeSignature<Function>;
    if constexpr (std::tuple_size_v<typename Signature::Arguments> > Signature::implicitOwner)
        return std::is_same_v<std::tuple_element_t<Signature::implicitOwner, typename Signature::Arguments>, State>;
    else
        return false;
}
template <class Function, class State> consteval std::size_t nativeStateCount()
{
    return packedNativeState<Function, State>() ? 1 : std::tuple_size_v<State>;
}

// The target and literal configuration are values. Instantiating this factory
// for a new module class or constant value cannot duplicate its implementation.
template <class Function, class... Fields, std::size_t SettingCount = 0>
void bindNative(Module &owner, Entry key, Function function, std::tuple<Fields...> fields = {},
                bool external = false,
                int capacity = std::tuple_size_v<typename NativeSignature<Function>::Arguments> -
                               NativeSignature<Function>::implicitOwner - nativeStateCount<Function, std::tuple<Fields...>>() - SettingCount,
                bool reentrant = false, std::string_view program = {}, std::array<std::uint32_t, SettingCount> settings = {})
{
    using Signature = NativeSignature<Function>;
    using Captured = std::tuple<Fields...>;
    constexpr auto stateCount = nativeStateCount<Function, Captured>();
    constexpr auto arity = std::tuple_size_v<typename Signature::Arguments> - Signature::implicitOwner - stateCount - SettingCount;
    using Binding = NativeBinding<Function, arity, std::make_index_sequence<stateCount>, std::make_index_sequence<SettingCount>>;
    const auto name = entryName(key);
    Method result{&owner, key, name, program.empty() ? name : program, &Binding::execute, reentrant, capacity, external};
    typename Binding::State state = [&]
    {
        if constexpr (packedNativeState<Function, Captured>())
            return std::make_tuple(fields);
        else
            return fields;
    }();
    result.binding = std::make_shared<const Binding>(function, state, settings);
    if constexpr (!Signature::asynchronous)
        result.invokeSync = &Binding::invoke;
    owner.define(std::move(result));
}

// Small layout operations for addressable game records. Ordinary scalar fields
// are assigned directly by generated C++; these functions handle unaligned views.
template <class T, class Element, std::size_t Extent> T memberView(std::span<Element, Extent> buffer, std::size_t offset)
{
    if (offset > buffer.size_bytes() || sizeof(T) > buffer.size_bytes() - offset)
        throw std::out_of_range("Native member view crosses its owning span");
    T result;
    std::memcpy(&result, reinterpret_cast<const std::byte *>(buffer.data()) + offset, sizeof(T));
    return result;
}
template <class Element, std::size_t Extent, class T> void setMemberView(std::span<Element, Extent> buffer, std::size_t offset, const T &value)
{
    if (offset > buffer.size_bytes() || sizeof(T) > buffer.size_bytes() - offset)
        throw std::out_of_range("Native member write crosses its owning span");
    std::memcpy(reinterpret_cast<std::byte *>(buffer.data()) + offset, &value, sizeof(T));
}
template <class T, class Buffer> T memberView(const Buffer &buffer, std::size_t offset)
{
    if (offset > sizeof(Buffer) || sizeof(T) > sizeof(Buffer) - offset)
        throw std::out_of_range("Native member view crosses its owning object");
    T result;
    std::memcpy(&result, reinterpret_cast<const std::byte *>(std::addressof(buffer)) + offset, sizeof(T));
    return result;
}
template <class T, class Buffer> void setMemberView(Buffer &buffer, std::size_t offset, const T &value)
{
    if (offset > sizeof(Buffer) || sizeof(T) > sizeof(Buffer) - offset)
        throw std::out_of_range("Native member view crosses its owning object");
    std::memcpy(reinterpret_cast<std::byte *>(std::addressof(buffer)) + offset, &value, sizeof(T));
}
template <class T, class U> T shifted(T base, U displacement)
{
    if constexpr (ReferenceType<T>)
    {
        base.base += word(displacement);
        return base;
    }
    else if constexpr (std::is_same_v<T, Value>)
    {
        base.bits.base += word(displacement);
        return base;
    }
    else
        return storedValue<T>(word(base) + word(displacement));
}

// Initializers contain only the bytes of individual native member objects.
template <class T, std::size_t Size> T initialMember(const char (&source)[Size])
{
    if (Size - 1 > sizeof(T))
        throw std::out_of_range("Initial member data exceeds its native object");
    T result{};
    std::memcpy(std::addressof(result), source, Size - 1);
    return result;
}
inline bool moduleNameEqual(std::string_view left, std::string_view right) noexcept
{
    if (left.size() != right.size())
        return false;
    for (std::size_t index = 0; index < left.size(); ++index)
    {
        const auto fold = [](unsigned char value) { return value >= 'A' && value <= 'Z' ? value + ('a' - 'A') : value; };
        if (fold(static_cast<unsigned char>(left[index])) != fold(static_cast<unsigned char>(right[index])))
            return false;
    }
    return true;
}
}
