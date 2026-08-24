#pragma once

struct LiftCpu;

class BloodEffListener {
public:
    BloodEffListener() = default;
    virtual void onEffectAttached(LiftCpu* cpu);
    virtual void onEffectDetached(LiftCpu* cpu);
    virtual void onEffectChanged(LiftCpu* cpu);
};

class IEffectManager {
public:
    IEffectManager() = default;
    virtual void initializeEffect(LiftCpu* cpu);
    virtual void updateEffect(LiftCpu* cpu);
    virtual void queryEffectState(LiftCpu* cpu);
    virtual void activateEffect(LiftCpu* cpu);
    virtual void deactivateEffect(LiftCpu* cpu);
    virtual void renderEffect(LiftCpu* cpu);
    virtual void createEffectResources(LiftCpu* cpu);
    virtual void setParameter(LiftCpu* cpu);
    virtual void resetEffect(LiftCpu* cpu);
    virtual void releaseEffect(LiftCpu* cpu);
    virtual void isEffectComplete(LiftCpu* cpu);
    virtual void destroyEffect(LiftCpu* cpu);
};

class CScriptedEffect : public IEffectManager {
public:
    CScriptedEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void queryEffectState(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void releaseEffect(LiftCpu* cpu) override;
    void isEffectComplete(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class CSpiralEffect : public IEffectManager {
public:
    CSpiralEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class CMolEffect : public IEffectManager {
public:
    CMolEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class CBladeEffect : public IEffectManager {
public:
    CBladeEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class CGazerLakeEffect : public IEffectManager {
public:
    CGazerLakeEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class CRainEffect : public IEffectManager {
public:
    CRainEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class CLightEffect : public IEffectManager {
public:
    CLightEffect() = default;
    void initializeEffect(LiftCpu* cpu) override;
    void updateEffect(LiftCpu* cpu) override;
    void activateEffect(LiftCpu* cpu) override;
    void deactivateEffect(LiftCpu* cpu) override;
    void renderEffect(LiftCpu* cpu) override;
    void createEffectResources(LiftCpu* cpu) override;
    void setParameter(LiftCpu* cpu) override;
    void destroyEffect(LiftCpu* cpu) override;
};

class IOutputDevice {
public:
    IOutputDevice() = default;
    virtual void write(LiftCpu* cpu);
};

class COutputLogDevice : public IOutputDevice {
public:
    COutputLogDevice() = default;
    void write(LiftCpu* cpu) override;
};

class CSphereError : public IOutputDevice {
public:
    CSphereError() = default;
    void write(LiftCpu* cpu) override;
};

class GrassMapMngr {
public:
    GrassMapMngr() = default;
    virtual void loadGrassMap(LiftCpu* cpu);
};

class HyperTextElement {
public:
    HyperTextElement() = default;
    virtual void elementType(LiftCpu* cpu);
};

class HyperTextElement_WordWrap : public HyperTextElement {
public:
    HyperTextElement_WordWrap() = default;
};

class HyperTextElementWithParameters : public HyperTextElement {
public:
    HyperTextElementWithParameters() = default;
};

class HyperTextElement_PlainText : public HyperTextElement {
public:
    HyperTextElement_PlainText() = default;
};

class HyperTextElement_Link : public HyperTextElementWithParameters {
public:
    HyperTextElement_Link() = default;
};

class CItem {
public:
    CItem() = default;
    virtual void resetItem(LiftCpu* cpu);
    virtual void releaseItem(LiftCpu* cpu);
};

class CCommonItem : public CItem {
public:
    CCommonItem() = default;
};

class CItemListCommonItem : public CItem {
public:
    CItemListCommonItem() = default;
    void resetItem(LiftCpu* cpu) override;
};

class CBaseManagerCommonItem : public CItemListCommonItem {
public:
    CBaseManagerCommonItem() = default;
    virtual void handleInsert(LiftCpu* cpu);
    virtual void handleRemove(LiftCpu* cpu);
    virtual void findItem(LiftCpu* cpu);
};

class NatureRainListener {
public:
    NatureRainListener() = default;
    virtual void onNatureChanged(LiftCpu* cpu);
    virtual void onRainChanged(LiftCpu* cpu);
    virtual void onEffectChanged(LiftCpu* cpu);
};

class LightingListener {
public:
    LightingListener() = default;
    virtual void onLightingChanged(LiftCpu* cpu);
    virtual void onLightEnabled(LiftCpu* cpu);
    virtual void onLightDisabled(LiftCpu* cpu);
};

class CSoundFX {
public:
    CSoundFX() = default;
    virtual void play(LiftCpu* cpu);
    virtual void stop(LiftCpu* cpu);
    virtual void rewind(LiftCpu* cpu);
};

class CCursor {
public:
    CCursor() = default;
    virtual void destroy(LiftCpu* cpu);
    virtual void copyStateFrom(LiftCpu* cpu);
    virtual void activate(LiftCpu* cpu);
    virtual void deactivate(LiftCpu* cpu);
    virtual void apply(LiftCpu* cpu);
    virtual void setVisible(LiftCpu* cpu);
    virtual void getPosition(LiftCpu* cpu);
    virtual void setPosition(LiftCpu* cpu);
    virtual void show(LiftCpu* cpu);
    virtual void isInsideViewport(LiftCpu* cpu);
    virtual void isSystemCursorVisible(LiftCpu* cpu);
    virtual void setSystemCursorVisible(LiftCpu* cpu);
    virtual void cursorKind(LiftCpu* cpu);
    virtual void setCursorKind(LiftCpu* cpu);
};

class CHardwareCursor : public CCursor {
public:
    CHardwareCursor() = default;
    void destroy(LiftCpu* cpu) override;
    void copyStateFrom(LiftCpu* cpu) override;
    void activate(LiftCpu* cpu) override;
    void deactivate(LiftCpu* cpu) override;
    void apply(LiftCpu* cpu) override;
    void setVisible(LiftCpu* cpu) override;
    void getPosition(LiftCpu* cpu) override;
    void setPosition(LiftCpu* cpu) override;
    void show(LiftCpu* cpu) override;
    void isInsideViewport(LiftCpu* cpu) override;
    void isSystemCursorVisible(LiftCpu* cpu) override;
    void setSystemCursorVisible(LiftCpu* cpu) override;
    void cursorKind(LiftCpu* cpu) override;
    void setCursorKind(LiftCpu* cpu) override;
};

class CSoftwareCursor : public CCursor {
public:
    CSoftwareCursor() = default;
    void destroy(LiftCpu* cpu) override;
    void copyStateFrom(LiftCpu* cpu) override;
    void activate(LiftCpu* cpu) override;
    void deactivate(LiftCpu* cpu) override;
    void apply(LiftCpu* cpu) override;
    void setVisible(LiftCpu* cpu) override;
    void getPosition(LiftCpu* cpu) override;
    void setPosition(LiftCpu* cpu) override;
    void show(LiftCpu* cpu) override;
    void isInsideViewport(LiftCpu* cpu) override;
    void isSystemCursorVisible(LiftCpu* cpu) override;
    void setSystemCursorVisible(LiftCpu* cpu) override;
    void cursorKind(LiftCpu* cpu) override;
    void setCursorKind(LiftCpu* cpu) override;
};

class UnmanagedResourceBase {
public:
    UnmanagedResourceBase() = default;
    virtual void restoreResource(LiftCpu* cpu);
    virtual void releaseResource(LiftCpu* cpu);
};

class UnmanagedResourceVB : public UnmanagedResourceBase {
public:
    UnmanagedResourceVB() = default;
    void restoreResource(LiftCpu* cpu) override;
};

class UnmanagedResourceIB : public UnmanagedResourceBase {
public:
    UnmanagedResourceIB() = default;
    void restoreResource(LiftCpu* cpu) override;
};

class UnmanagedResourceTexture : public UnmanagedResourceBase {
public:
    UnmanagedResourceTexture() = default;
    void restoreResource(LiftCpu* cpu) override;
};

class UnmanagedResourceVector {
public:
    UnmanagedResourceVector() = default;
    virtual void reserve(LiftCpu* cpu);
};

class StdAllocator {
public:
    StdAllocator() = default;
    virtual void allocate(LiftCpu* cpu);
    virtual void reallocate(LiftCpu* cpu);
    virtual void deallocate(LiftCpu* cpu);
};

namespace SphereUI {

class Window {
public:
    Window() = default;
    virtual void loadUi(LiftCpu* cpu);
    virtual void clone(LiftCpu* cpu);
    virtual void handleMessage(LiftCpu* cpu);
    virtual void setPosition(LiftCpu* cpu);
    virtual void draw(LiftCpu* cpu);
    virtual void handleInput(LiftCpu* cpu);
    virtual void setOpacity(LiftCpu* cpu);
    virtual void hitTest(LiftCpu* cpu);
    virtual void dispatchMessage(LiftCpu* cpu);
    virtual void setFont(LiftCpu* cpu);
    virtual void getFont(LiftCpu* cpu);
    virtual void destroy(LiftCpu* cpu);
};

class ButtonCtrl : public Window {
public:
    ButtonCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class CheckBox : public Window {
public:
    CheckBox() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    virtual void playClickSound(LiftCpu* cpu);
};

class CDescriptionWindow : public Window {
public:
    CDescriptionWindow() = default;
    void draw(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class EditCtrl : public Window {
public:
    EditCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ListCtrl : public Window {
public:
    ListCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class FilterListCtrl : public ListCtrl {
public:
    FilterListCtrl() = default;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class FontPicker : public Window {
public:
    FontPicker() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setFont(LiftCpu* cpu) override;
    void getFont(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class HyperTextChatListControl : public Window {
public:
    HyperTextChatListControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setFont(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class HyperTextCtrl : public Window {
public:
    HyperTextCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class HyperTextEditControl : public Window {
public:
    HyperTextEditControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ImageCtrl : public Window {
public:
    ImageCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setOpacity(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ListItemCtrl : public Window {
public:
    ListItemCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void setOpacity(LiftCpu* cpu) override;
    void hitTest(LiftCpu* cpu) override;
    void dispatchMessage(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class CMenuListControl : public Window {
public:
    CMenuListControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ToolTipCtrl : public Window {
public:
    ToolTipCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class MiniHelpCtrl : public ToolTipCtrl {
public:
    MiniHelpCtrl() = default;
    void clone(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
};

class CMinimapControl : public Window {
public:
    CMinimapControl() = default;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ProgressBar : public Window {
public:
    ProgressBar() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
};

class RadioButtonCtrl : public CheckBox {
public:
    RadioButtonCtrl() = default;
    void clone(LiftCpu* cpu) override;
    void playClickSound(LiftCpu* cpu) override;
};

class RichEditCtrl : public Window {
public:
    RichEditCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class ScrollBar : public Window {
public:
    ScrollBar() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
    virtual void updateControlState(LiftCpu* cpu);
    virtual void loadControlParameters(LiftCpu* cpu);
};

class SliderCtrl : public ScrollBar {
public:
    SliderCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void updateControlState(LiftCpu* cpu) override;
    void loadControlParameters(LiftCpu* cpu) override;
};

class SlotCtrl : public Window {
public:
    SlotCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void hitTest(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

class SpinButton : public Window {
public:
    SpinButton() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
    virtual void updateStatus(LiftCpu* cpu);
};

class TextCtrl : public Window {
public:
    TextCtrl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
};

class CWebBrowserControl : public Window {
public:
    CWebBrowserControl() = default;
    void loadUi(LiftCpu* cpu) override;
    void clone(LiftCpu* cpu) override;
    void handleMessage(LiftCpu* cpu) override;
    void draw(LiftCpu* cpu) override;
    void handleInput(LiftCpu* cpu) override;
    void destroy(LiftCpu* cpu) override;
};

}
