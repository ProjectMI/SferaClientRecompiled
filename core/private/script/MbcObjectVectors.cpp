#include "script/MbcRuntime.h"
#include "diagnostics/ClientDiagnostics.h"
#include "render/CharacterRenderer.h"
#include "world/WorldObjects.h"

void SferaMbcRuntime::scriptObjectVector(bool position, bool basis)
{
    const auto handle = nextInteger();
    if (handle < 0)
    {
        return;
    }
    auto *object = g_sfera_mbc_runtime.current_object = g_sfera_world_objects.object(handle, "GetObjectPointer");
    if (object == nullptr)
    {
        active_tag = UINT32_MAX;
        return;
    }
    if (position)
    {
        auto &destination = nextSliceReference();
        if (execution_failed)
        {
            return;
        }
        if (!destination.contains(sizeof(SferaVec3F)))
        {
            destination.diagnoseRange(sizeof(SferaVec3F));
        }
        writeMemory(destination.base, object->position);
    }
    else
    {
        if (basis && native_call->arguments[native_call->cursor].type != SferaMbcValueTypeRealPointer)
        {
            WorldDiagnostics::warning("g_norm: wrong type of parameter (must be float pointer)\n");
            execution_failed = true;
        }
        const auto destination = nextInteger();
        if (execution_failed)
        {
            return;
        }
        if (basis)
        {
            const auto *extended = SphereRenderCharacterModels::checkedExtended(object);
            g_sfera_world_objects.recalculateBasis(handle);
            if (destination == 0)
            {
                WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_norm\n");
            }
            writeMemory(destination, extended->orientation_basis[0]);
        }
        else
        {
            if (destination == 0)
            {
                WorldDiagnostics::warning("NULL-pointer dereferencing: ffg_abg\n");
            }
            writeMemory(destination, object->rotation);
        }
    }
}

