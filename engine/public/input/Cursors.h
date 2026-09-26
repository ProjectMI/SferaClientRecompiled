#pragma once

#include <windows.h>
#include <cstdint>
#include <memory>
#include <string_view>
#include <type_traits>

class CCursor;
struct SferaCursorPosition;
struct SphereUICursorGeometry;

struct SferaCursorPosition
{
    int x;
    int y;
};

class CCursor
{
  public:
    CCursor() = default;
    virtual ~CCursor() = default;
    virtual void copyStateFrom(const CCursor *previous) = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void apply() = 0;
    virtual void updatePosition() = 0;
    virtual SferaCursorPosition *getPosition(SferaCursorPosition *output) const = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void show() = 0;
    virtual bool isInsideViewport() const = 0;
    virtual bool isSystemCursorVisible() const = 0;
    virtual void setSystemCursorVisible(bool visible) = 0;
    virtual std::uint32_t cursorKind() const = 0;
    virtual void setCursorKind(std::uint32_t kind) = 0;
};

struct SphereUICursorGeometry
{
    int x;
    int y;
    int width;
    int height;
    bool centered;
};

class CHardwareCursor;
struct CHardwareCursorCursorDeleter;
struct SphereUIBitmapDeleter;

struct CHardwareCursorCursorDeleter
{
    void operator()(HCURSOR cursor) const noexcept
    {
        if (cursor)
            ::DestroyCursor(cursor);
    }
};

using CHardwareCursorCursorOwner = std::unique_ptr<std::remove_pointer_t<HCURSOR>, CHardwareCursorCursorDeleter>;

class CHardwareCursor : public CCursor
{
  public:
    int texture_width = 0;
    int texture_height = 0;

    CHardwareCursorCursorOwner cursor_handle;
    bool clip_enabled = false;
    bool saved_system_visible = 0u;
    std::uint32_t kind = 255u;
    int saved_x = 0;
    int saved_y = 0;
    CHardwareCursor();
    ~CHardwareCursor();
    void copyStateFrom(const CCursor *previous) override;
    void activate() override;
    void deactivate() override;
    void apply() override;
    void updatePosition() override
    {
    }
    SferaCursorPosition *getPosition(SferaCursorPosition *output) const override;
    void setPosition(int x, int y) override;
    void show() override;
    bool isInsideViewport() const override;
    bool isSystemCursorVisible() const override;
    void setSystemCursorVisible(bool visible) override;
    std::uint32_t cursorKind() const override
    {
        return kind;
    }
    void setCursorKind(std::uint32_t kind) override;

  private:
    friend struct CHardwareCursorCursorDeleter;
};

struct SphereUIBitmapDeleter
{
    void operator()(HBITMAP bitmap) const noexcept;
};
using SphereUIBitmapOwner = std::unique_ptr<std::remove_pointer_t<HBITMAP>, SphereUIBitmapDeleter>;

class CSoftwareCursor;

class CSoftwareCursor : public CCursor
{
  public:
    int texture_width = 0;
    int texture_height = 0;
    int x = 0;
    int y = 0;
    bool active = 0u;
    bool saved_system_visible = 0u;
    std::uint32_t saved_kind = 255u;
    int saved_x = 0;
    int saved_y = 0;
    CSoftwareCursor();
    void copyStateFrom(const CCursor *previous) override;
    void activate() override;
    void deactivate() override;
    void apply() override
    {
    }
    void updatePosition() override;
    SferaCursorPosition *getPosition(SferaCursorPosition *output) const override;
    void setPosition(int new_x, int new_y) override
    {
        x = new_x;
        y = new_y;
    }
    void show() override;
    bool isInsideViewport() const override
    {
        return active;
    }
    bool isSystemCursorVisible() const override;
    void setSystemCursorVisible(bool visible) override;
    std::uint32_t cursorKind() const override;
    void setCursorKind(std::uint32_t kind) override;
};

class CCursorManager;

class CCursorManager
{
  public:
    static CCursorManager &instance();
    static bool hasActiveCursor() noexcept
    {
        return initialized != nullptr && initialized->active != nullptr;
    }
    static void focusChanged(bool focused) noexcept;
    static void shutdown() noexcept;
    CCursor *currentCursor() const noexcept
    {
        return active;
    }
    CCursor *activeCursor() const;
    SferaCursorPosition position() const;
    SphereUICursorGeometry geometry() const;
    void select(std::uint32_t mode);
    bool usesSoftwareCursor() const noexcept
    {
        return active == &software;
    }

  private:
    CCursorManager() = default;
    ~CCursorManager();
    CCursorManager(const CCursorManager &) = delete;
    CCursorManager &operator=(const CCursorManager &) = delete;
    CSoftwareCursor software;
    CHardwareCursor hardware;
    CCursor *active = nullptr;
    static CCursorManager *initialized;
};

class SphereUICursorSupport;

class SphereUICursorSupport
{
  public:
    static bool cursor_uses_center_clip(std::uint32_t kind);
};

class SferaCursorTextureHelper;

class SferaCursorTextureHelper
{
  public:
    static std::string_view name(std::uint32_t slot);
};
