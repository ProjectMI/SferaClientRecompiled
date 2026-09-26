#pragma once

#include <type_traits>
#include <utility>

template <class T> class SferaRestore
{
  public:
    explicit SferaRestore(T &target) : target_(target), saved_(target)
    {
    }
    ~SferaRestore() noexcept
    {
        restore();
    }
    void restore() noexcept
    {
        if (std::exchange(active_, false))
            target_ = std::move(saved_);
    }
    SferaRestore(const SferaRestore &) = delete;
    SferaRestore &operator=(const SferaRestore &) = delete;

  private:
    static_assert(std::is_nothrow_move_assignable_v<T>);
    T &target_;
    T saved_;
    bool active_ = true;
};

// Scoped restoration of CPU-side render state, independent of D3D state-blocks.
