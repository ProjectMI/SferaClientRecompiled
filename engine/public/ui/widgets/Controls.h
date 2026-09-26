#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

#include "ui/Window.h"

struct SphereUIUiSprite;

class ButtonStyle;
struct SferaParserRange;
class SferaSimpleParser;
class SphereUIButtonCtrl;
struct SphereUIWindowCloneContext;

class ButtonStyle
{
  public:
    static constexpr std::uint32_t stateImages = 1u << 0u;
    static constexpr std::uint32_t releaseOutside = 1u << 1u;
    static constexpr std::uint32_t repeatWhilePressed = 1u << 2u;
    static constexpr std::uint32_t sendClose = 1u << 3u;
    static constexpr std::uint32_t centerText = 1u << 4u;
    static constexpr std::uint32_t showHelp = 1u << 5u;
};

class SphereUIButtonCtrl : public SphereUIWindow
{
  public:
    SphereUIButtonCtrl *asButtonCtrl() noexcept override
    {
        return this;
    }
    const SphereUIButtonCtrl *asButtonCtrl() const noexcept override
    {
        return this;
    }
    std::uint32_t visual_state{};
    std::shared_ptr<const SphereUIUiSprite> idle_image{};
    std::shared_ptr<const SphereUIUiSprite> pressed_image{};
    std::shared_ptr<const SphereUIUiSprite> hover_image{};
    std::uint32_t button_flags{};
    std::uint32_t hotkey{};
    std::uint64_t repeat_started_at{};
    bool pressed{};

    float repeat_interval{};
    std::uint32_t hover_color{};
    std::shared_ptr<const SphereUIUiSprite> disabled_image{};
    SphereUIButtonCtrl();

    void click();
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;

  private:
    static void copyCloneState(SphereUIButtonCtrl &target, const SphereUIButtonCtrl &source, SphereUIWindowCloneContext &);

  private:
    static std::uint32_t keyCode(std::string_view name);
};

class SphereUICheckBox;
class SphereUIRadioButtonCtrl;

class SphereUICheckBox : public SphereUIWindow
{
  public:
    SphereUICheckBox *asCheckBox() noexcept override
    {
        return this;
    }
    const SphereUICheckBox *asCheckBox() const noexcept override
    {
        return this;
    }
    std::shared_ptr<const SphereUIUiSprite> unchecked_image{};
    std::shared_ptr<const SphereUIUiSprite> unchecked_hover_image{};
    std::shared_ptr<const SphereUIUiSprite> checked_image{};
    std::shared_ptr<const SphereUIUiSprite> checked_hover_image{};
    bool checked{};
    bool hovered{};

    int image_x{};
    int image_y{};
    std::uint32_t button_flags{};
    int label_x{};
    int label_y{};
    std::uint32_t hover_color{};
    void copyCheckState(const SphereUICheckBox &source);
    SphereUICheckBox();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    virtual void playClickSound();

  private:
    static void copyCloneState(SphereUICheckBox &target, const SphereUICheckBox &source, SphereUIWindowCloneContext &)
    {
        target.copyCheckState(source);
    }
};

class SphereUIRadioButtonCtrl : public SphereUICheckBox
{
  public:
    SphereUIRadioButtonCtrl();

    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    void playClickSound() override;

  private:
    static void copyCloneState(SphereUIRadioButtonCtrl &target, const SphereUIRadioButtonCtrl &source, SphereUIWindowCloneContext &)
    {
        target.copyCheckState(source);
    }
};

class SphereUIImageCtrl;
struct SphereUIImageDescription;

class SphereUIImageCtrl : public SphereUIWindow
{
  public:
    SphereUIImageCtrl *asImageCtrl() noexcept override
    {
        return this;
    }
    const SphereUIImageCtrl *asImageCtrl() const noexcept override
    {
        return this;
    }
    std::uint32_t image_style{};
    bool interaction_active{};
    std::shared_ptr<const SphereUIUiSprite> fallback_image{};
    bool rotated{};
    float rotation_radians{};
    std::uint32_t base_alpha{};
    float opacity{};
    SphereUIImageCtrl();

    void setImage(const struct SphereUIImageDescription *description);
    void setImageName(std::string_view name);
    void setRotationDegrees(float degrees)
    {
        rotated = degrees != 0.0f;
        rotation_radians = degrees / 180.0f * 3.1415929794311523f;
    }
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    void setOpacity(float opacity) override;

  private:
    static void copyCloneState(SphereUIImageCtrl &target, const SphereUIImageCtrl &source, SphereUIWindowCloneContext &);
};

class SphereUIProgressBar;

class SphereUIProgressBar : public SphereUIWindow
{
  public:
    SphereUIProgressBar *asProgressBar() noexcept override
    {
        return this;
    }
    const SphereUIProgressBar *asProgressBar() const noexcept override
    {
        return this;
    }
    int minimum{};
    int maximum{};
    int current{};
    float progress_ratio{};
    std::uint32_t display_mode{};
    std::string status_text;
    int status_x{};
    int status_y{};
    SphereUIProgressBar();

    void initializeProgressState();
    void setProgressValue(int value);
    void setProgressRange(int new_minimum, int new_maximum);
    void refreshProgressDisplay();
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &) override
    {
    }

  private:
    static void copyCloneState(SphereUIProgressBar &target, const SphereUIProgressBar &source, SphereUIWindowCloneContext &);
};

class ScrollField;
class SphereUIScrollBar;
struct SphereUIScrollParameters;

class ScrollField
{
  public:
    static constexpr std::uint32_t range = 1u << 0u;
    static constexpr std::uint32_t page = 1u << 1u;
    static constexpr std::uint32_t position = 1u << 2u;
    static constexpr std::uint32_t step = 1u << 4u;
    static constexpr std::uint32_t all = range | page | position | step;
};

struct SphereUIScrollParameters
{
    static constexpr std::uint32_t wire_size = 28u;
    std::uint32_t size = wire_size;
    std::uint32_t mask{};
    int minimum;
    int maximum;
    int page_step;
    int current;
    int step;
};

class SphereUIScrollBar : public SphereUIWindow
{
  public:
    SphereUIScrollBar *asScrollBar() noexcept override
    {
        return this;
    }
    const SphereUIScrollBar *asScrollBar() const noexcept override
    {
        return this;
    }
    std::shared_ptr<const SphereUIUiSprite> scroll_resource{};
    int thumb_width{};
    int thumb_height{};
    int thumb_x{};
    int thumb_y{};
    std::uint32_t orientation_flags{};
    std::unique_ptr<SphereUIButtonCtrl> decrease_button;
    std::unique_ptr<SphereUIButtonCtrl> increase_button;
    float normalized_position{};
    int minimum{};
    int maximum{};
    int current{};
    int step{};
    int page_step{};
    bool dragging_thumb{};
    bool explicit_step{};
    bool notify_changes{};

    std::uint64_t repeat_started_at{};
    int track_left{};
    int track_top{};
    int track_right{};
    int track_bottom{};
    bool page_click_active{};

    SphereUIScrollBar();

    void setParameters(const struct SphereUIScrollParameters &parameters);
    void getParameters(struct SphereUIScrollParameters &parameters) const;
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    virtual void updateControlState();
    virtual void loadControlParameters();

  private:
    static bool moveScroll(SphereUIScrollBar &control, bool increase, int amount);
    static void enableNavigationButtons(SphereUIScrollBar &control);

  private:
    static void playScrollSound(bool page);
};

class SphereUISliderCtrl;

class SphereUISliderCtrl : public SphereUIScrollBar
{
  public:
    std::string value_text;
    std::uint32_t display_mode{};
    int status_x{};
    int status_y{};
    SphereUISliderCtrl();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    void draw() override;
    void updateControlState() override;
    void loadControlParameters() override;

  private:
    static void copyCloneState(SphereUISliderCtrl &destination, const SphereUISliderCtrl &source, SphereUIWindowCloneContext &context);
};

class SphereUISpinButton;

class SphereUISpinButton : public SphereUIWindow
{
  public:
    SphereUISpinButton *asSpinButton() noexcept override
    {
        return this;
    }
    const SphereUISpinButton *asSpinButton() const noexcept override
    {
        return this;
    }
    std::unique_ptr<SphereUIButtonCtrl> decrease_button;
    std::unique_ptr<SphereUIButtonCtrl> increase_button;
    int minimum{};
    int maximum{};
    int current{};
    int previous{};
    int step{};
    std::uint32_t body_index{};
    bool status_valid{};
    bool notify_changes{};
    bool update_enabled{};
    SphereUISpinButton();

    void setRange(int minimum, int maximum);
    void setCurrentValue(int value);
    void setStep(int new_step)
    {
        step = new_step;
    }
    int currentValue() const
    {
        return current;
    }
    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    virtual void updateStatus();

  private:
    static void copySpinFields(SphereUISpinButton &destination, const SphereUISpinButton &source, SphereUIWindowCloneContext &context);
};

class SphereUITextCtrl;
struct SphereUIWindowInput;

class SphereUITextCtrl : public SphereUIWindow
{
  public:
    std::uint32_t text_style{};
    SphereUITextCtrl();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;

  private:
    static void copyCloneState(SphereUITextCtrl &target, const SphereUITextCtrl &source, SphereUIWindowCloneContext &)
    {
        target.text_style = source.text_style;
    }
};

class SphereUIFontPicker;

class SphereUIFontPicker : public SphereUIWindow
{
  public:
    SphereUIFontPicker *asFontPicker() noexcept override
    {
        return this;
    }
    const SphereUIFontPicker *asFontPicker() const noexcept override
    {
        return this;
    }
    std::unique_ptr<SphereUISpinButton> selector;
    std::unique_ptr<SphereUIWindow> preview;
    SphereUIFontPicker();

    bool loadUi(const std::string &filename, SferaSimpleParser &parser, const SferaParserRange &range) override;
    std::unique_ptr<SphereUIWindow> cloneInto(SphereUIWindowCloneContext &context) const override;
    std::uint32_t handleMessage(SphereUIUiMessage message, std::uint32_t first, std::uint32_t second) override;
    void draw() override;
    void handleInput(const SphereUIWindowInput &input) override;
    void setFont(int font_id) override;
    int getFont() const override;

  private:
    static void copyCloneState(SphereUIFontPicker &destination, const SphereUIFontPicker &source, SphereUIWindowCloneContext &context);
};
