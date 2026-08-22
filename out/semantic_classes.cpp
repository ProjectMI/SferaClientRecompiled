#include "semantic_classes.h"
#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <cstdint>

void BloodEffListener::onEffectAttached(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0041A090, LIFT_CALLBACK_SENTINEL);
}

void BloodEffListener::onEffectDetached(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0041A070, LIFT_CALLBACK_SENTINEL);
}

void BloodEffListener::onEffectChanged(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0041A9F0, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::queryEffectState(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::resetEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::releaseEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00425F60, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::isEffectComplete(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00425F90, LIFT_CALLBACK_SENTINEL);
}

void IEffectManager::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00427590, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004294E0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00426640, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::queryEffectState(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00429280, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004266B0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00427750, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004266D0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004278E0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::releaseEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004276A0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::isEffectComplete(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004261A0, LIFT_CALLBACK_SENTINEL);
}

void CScriptedEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00429A10, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B800, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B710, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0A0, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0B0, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B130, LIFT_CALLBACK_SENTINEL);
}

void CSpiralEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7E0, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042BAD0, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B200, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B710, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0A0, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B260, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B300, LIFT_CALLBACK_SENTINEL);
}

void CMolEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042BA50, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042C050, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B710, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0A0, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3E0, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B480, LIFT_CALLBACK_SENTINEL);
}

void CBladeEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042C020, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B530, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B710, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0A0, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042C6B0, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CGazerLakeEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042C690, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042C800, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B710, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0A0, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042CFC0, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CRainEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042C770, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::initializeEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B230, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::updateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B3D0, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::activateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B340, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::deactivateEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B380, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::renderEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B3B0, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::createEffectResources(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B3C0, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::setParameter(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B440, LIFT_CALLBACK_SENTINEL);
}

void CLightEffect::destroyEffect(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0044B510, LIFT_CALLBACK_SENTINEL);
}

void IOutputDevice::write(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void COutputLogDevice::write(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042E3F0, LIFT_CALLBACK_SENTINEL);
}

void CSphereError::write(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042E430, LIFT_CALLBACK_SENTINEL);
}

void GrassMapMngr::loadGrassMap(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00430AC0, LIFT_CALLBACK_SENTINEL);
}

void HyperTextElement::elementType(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0041FBB0, LIFT_CALLBACK_SENTINEL);
}

void CItem::resetItem(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CItem::releaseItem(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CItemListCommonItem::resetItem(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_00447DD0, LIFT_CALLBACK_SENTINEL);
}

void CBaseManagerCommonItem::handleInsert(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0043B130, LIFT_CALLBACK_SENTINEL);
}

void CBaseManagerCommonItem::handleRemove(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0043B130, LIFT_CALLBACK_SENTINEL);
}

void CBaseManagerCommonItem::findItem(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004219F0, LIFT_CALLBACK_SENTINEL);
}

void NatureRainListener::onNatureChanged(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0047FA50, LIFT_CALLBACK_SENTINEL);
}

void NatureRainListener::onRainChanged(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0047F7B0, LIFT_CALLBACK_SENTINEL);
}

void NatureRainListener::onEffectChanged(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0041A080, LIFT_CALLBACK_SENTINEL);
}

void LightingListener::onLightingChanged(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0047F820, LIFT_CALLBACK_SENTINEL);
}

void LightingListener::onLightEnabled(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0047F5A0, LIFT_CALLBACK_SENTINEL);
}

void LightingListener::onLightDisabled(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0047F5C0, LIFT_CALLBACK_SENTINEL);
}

void CSoundFX::play(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EE7F2, LIFT_CALLBACK_SENTINEL);
}

void CSoundFX::stop(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EE7F8, LIFT_CALLBACK_SENTINEL);
}

void CSoundFX::rewind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EE7FE, LIFT_CALLBACK_SENTINEL);
}

void CCursor::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::copyStateFrom(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::activate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::deactivate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::apply(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::setVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::getPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::setPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::show(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::isInsideViewport(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::isSystemCursorVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::setSystemCursorVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::cursorKind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CCursor::setCursorKind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004EEB22, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8340, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::copyStateFrom(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7C50, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::activate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7CB0, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::deactivate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7CF0, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::apply(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7D00, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::setVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::getPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7D10, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::setPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7D60, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::show(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7DA0, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::isInsideViewport(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7DD0, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::isSystemCursorVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7E10, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::setSystemCursorVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7E30, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::cursorKind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7E50, LIFT_CALLBACK_SENTINEL);
}

void CHardwareCursor::setCursorKind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7E60, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8340, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::copyStateFrom(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D7FB0, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::activate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8030, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::deactivate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D80A0, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::apply(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::setVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8100, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::getPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8140, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::setPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8160, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::show(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8180, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::isInsideViewport(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D82D0, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::isSystemCursorVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D82E0, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::setSystemCursorVisible(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D82F0, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::cursorKind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8300, LIFT_CALLBACK_SENTINEL);
}

void CSoftwareCursor::setCursorKind(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D8310, LIFT_CALLBACK_SENTINEL);
}

void UnmanagedResourceBase::restoreResource(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B7D0, LIFT_CALLBACK_SENTINEL);
}

void UnmanagedResourceBase::releaseResource(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D9820, LIFT_CALLBACK_SENTINEL);
}

void UnmanagedResourceVB::restoreResource(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D9740, LIFT_CALLBACK_SENTINEL);
}

void UnmanagedResourceIB::restoreResource(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D97B0, LIFT_CALLBACK_SENTINEL);
}

void UnmanagedResourceTexture::restoreResource(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D9840, LIFT_CALLBACK_SENTINEL);
}

void UnmanagedResourceVector::reserve(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004DA510, LIFT_CALLBACK_SENTINEL);
}

void StdAllocator::allocate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004ED770, LIFT_CALLBACK_SENTINEL);
}

void StdAllocator::reallocate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004ED790, LIFT_CALLBACK_SENTINEL);
}

void StdAllocator::deallocate(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004ED7B0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D47B0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D5510, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D2DD0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::setPosition(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D19E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D25E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D28B0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::setOpacity(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D2A40, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::hitTest(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D2B80, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::dispatchMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D2AE0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::setFont(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D1AC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::getFont(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D1B00, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::Window::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A13C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ButtonCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0049EDE0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ButtonCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A0DB0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ButtonCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0049F5A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ButtonCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0049F230, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ButtonCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0049F7A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ButtonCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0049F1A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CheckBox::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A0ED0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CheckBox::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A1740, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CheckBox::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A12C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CheckBox::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A13E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CheckBox::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A1200, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CheckBox::playClickSound(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A1350, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CDescriptionWindow::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A2280, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CDescriptionWindow::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A1DF0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::EditCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A3000, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::EditCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A3C50, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::EditCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A3990, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::EditCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A2810, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::EditCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A3400, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::EditCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A2FE0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C0D80, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C04C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C08C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BF210, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BEEF0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BFE80, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FilterListCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A49E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FilterListCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A48A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FilterListCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A44D0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A5800, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A5B70, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A57A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A56E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A5600, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::setFont(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A5990, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::getFont(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A59F0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::FontPicker::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A5A50, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004A9CC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AD590, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004ACE10, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AB430, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AB7C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::setFont(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AA0D0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextChatListControl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AAB30, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AEEA0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B1210, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B08B0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004AF040, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B0590, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B0250, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextEditControl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B6410, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextEditControl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B7720, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextEditControl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B45C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextEditControl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B47D0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextEditControl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B6F30, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::HyperTextEditControl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B6F10, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B77F0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B80A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B7DC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B7970, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B7AF0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::setOpacity(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B7F10, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ImageCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004B7F90, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BE3E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BE8C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BE170, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BD000, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BD340, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::setOpacity(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BD880, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::hitTest(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BD970, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::dispatchMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BDA30, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ListItemCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004BE3C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMenuListControl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C1B30, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMenuListControl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C2FB0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMenuListControl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C2A40, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMenuListControl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C1A40, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMenuListControl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C1660, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMenuListControl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C2A20, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ToolTipCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0230, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ToolTipCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CFF20, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ToolTipCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0130, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ToolTipCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CFA00, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ToolTipCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CF7C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ToolTipCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3270, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::MiniHelpCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3520, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::MiniHelpCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3060, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMinimapControl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3670, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMinimapControl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3710, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMinimapControl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3750, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CMinimapControl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3720, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ProgressBar::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3FC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ProgressBar::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C42B0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ProgressBar::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3EB0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ProgressBar::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C3C00, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ProgressBar::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_0042B0A0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RadioButtonCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C43C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RadioButtonCtrl::playClickSound(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C4360, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RichEditCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C4480, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RichEditCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C5E10, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RichEditCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C6370, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RichEditCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C4D90, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RichEditCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C6810, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::RichEditCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C5990, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C6B80, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C7F20, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C7AB0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C6EC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C7120, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C7DC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::updateControlState(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C7880, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::ScrollBar::loadControlParameters(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C7CF0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SliderCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C80C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SliderCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C8450, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SliderCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C82E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SliderCtrl::updateControlState(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C8270, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SliderCtrl::loadControlParameters(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C8060, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C95F0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C99D0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C9250, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C85E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C8D00, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::hitTest(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C8570, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SlotCtrl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004C9150, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CD550, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CDE00, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CDA30, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CD760, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CD820, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CDA10, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::SpinButton::updateStatus(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CDBF0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::TextCtrl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CF3E0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::TextCtrl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CF670, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::TextCtrl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CF4C0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::TextCtrl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004CF310, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CWebBrowserControl::loadUi(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0E10, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CWebBrowserControl::clone(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0BB0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CWebBrowserControl::handleMessage(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0EC0, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CWebBrowserControl::draw(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0520, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CWebBrowserControl::handleInput(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D0670, LIFT_CALLBACK_SENTINEL);
}

void SphereUI::CWebBrowserControl::destroy(LiftCpu* cpu) {
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this));
    LIFT_CALL(sfera_sub_004D09D0, LIFT_CALLBACK_SENTINEL);
}
