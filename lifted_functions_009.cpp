#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint32_t sfera_window_class_name() { return (uintptr_t)"SphereWclName"; }
__declspec(noinline) bool sfera_sub_00457E80(LiftCpu* cpu, uint32_t stop_address, double& result) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36, value_37, value_38, value_39, value_40, value_41, value_42, value_43, value_44, value_45, value_46, value_47, value_48, value_49, value_50, value_51, value_52, value_53, value_54, value_55, value_56, value_57, value_58, value_59, value_60, value_61, value_62, value_63, value_64, value_65, value_66, value_67, value_68, value_69, value_70, value_71, value_72, value_73, value_74, value_75, value_76, value_77, value_78, value_79, value_80, value_81, value_82, value_83, value_84, value_85, value_86, value_87, value_88, value_89, value_90, value_91, value_92, value_93, value_94, value_95, value_96, value_97, value_98, value_99, value_100, value_101, value_102, value_103, value_104, value_105, value_106, value_107, value_108, value_109, value_110, value_111, value_112, value_113, value_114, value_115, value_116, value_117, value_118, value_119, value_120, value_121, value_122, value_123, value_124, value_125, value_126, value_127, value_128, value_129, value_130, value_131, value_132, value_133, value_134, value_135, value_136, value_137, value_138, value_139, value_140, value_141, value_142, value_143, value_144, value_145, value_146, value_147, value_148, value_149, value_150, value_151, value_152, value_153, value_154, value_155, value_156, value_157, value_158, value_159, value_160, value_161, value_162, value_163, value_164, value_165, value_166, value_167, value_168, value_169, value_170, value_171, value_172, value_173, value_174, value_175, value_176, value_177, value_178, value_179, value_180, value_181, value_182, value_183, value_184, value_185, value_186, value_187, value_188, value_189, value_190, value_191, value_192, value_193, value_194, value_195, value_196, value_197, value_198, value_199, value_200, value_201, value_202, value_203, value_204, value_205, value_206, value_207, value_208, value_209, value_210, value_211, value_212, value_213, value_214, value_215, value_216, value_217, value_218, value_219, value_220, value_221, value_222;
 bool sub_pred[3]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5, x87_p6, x87_p7;
    bool lift_cmp[13];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x18Cu;
    cpu->eax = g_sfera_view_motion_runtime.update_serial;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((((cpu->eax & 0xFFu)) & (1u)) != 0u) goto label_00057EAE;
    cpu->eax |= 1u;
    g_sfera_view_motion_runtime.update_serial = cpu->eax;
label_00057EAE:
    if ((((cpu->eax & 0xFFu)) & (2u)) != 0u) goto label_00057EBA;
    cpu->eax |= 2u;
    g_sfera_view_motion_runtime.update_serial = cpu->eax;
label_00057EBA:
    if ((((cpu->eax & 0xFFu)) & (4u)) != 0u) goto label_00057EC6;
    cpu->eax |= 4u;
    g_sfera_view_motion_runtime.update_serial = cpu->eax;
label_00057EC6:
    cpu->eax = g_sfera_main_render_runtime.secondary_render_pass;
    if (cpu->eax != 0u) goto label_00057EEF;
    g_sfera_recovered_static_runtime.ui_cell_width = ((((double)(((int32_t)(g_sfera_graphics_runtime.display_width))))) / (10.0));
    x87_p0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    x87_p0 = (x87_p0) * (0.125);
     value_93 = x87_p0; value_0 = value_93; goto label_00057F01;
label_00057EEF:
    g_sfera_recovered_static_runtime.ui_cell_width = (double)25.600000381469727f;
    x87_p0 = (double)32.0f;
     value_94 = x87_p0;  value_0 = value_94;
label_00057F01:
    g_sfera_main_ui_state_runtime.scene_factor = value_0; 
    value_95 = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_p0 = 0.5;
    value_96 = (value_95) * (x87_p0);
    value_215 = x87_p0; x87_p0 = value_96;
    g_sfera_static_render_lookup_runtime.projection_scale = x87_p0; 
    x87_p0 = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    x87_p0 = (x87_p0) * (value_215);
    g_sfera_main_view_state_runtime.projection_scale = x87_p0; 
    x87_p0 = 0.10000000149011612;
    x87_p1 = 0.0;
     value_112 = x87_p1; value_113 = x87_p0; if (cpu->eax != 0u) goto label_00058919;
    value_118 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x); x87_p1 = x87_p0;
    value_124 = value_118 - x87_p1; 
    value_216 = x87_p0; x87_p0 = value_124;
    *(float*)(cpu->esp + 0xF8u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y);
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0xFCu) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z);
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x100u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xF8u);
    x87_p2 = (x87_p2) * (value_215);
    *(float*)(cpu->esp + 0x28u) = x87_p2; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    x87_p2 = (double)*(float*)(cpu->esp + 0xFCu);
    *(uint32_t*)(cpu->esp + 0x11Cu) = cpu->eax;
    x87_p2 = (x87_p2) * (value_215);
    *(float*)(cpu->esp + 0x2Cu) = x87_p2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_p2 = (double)*(float*)(cpu->esp + 0x100u);
    *(uint32_t*)(cpu->esp + 0x120u) = cpu->ecx;
    x87_p2 = (x87_p2) * (value_215);
    *(float*)(cpu->esp + 0x30u) = x87_p2; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x);
    *(uint32_t*)(cpu->esp + 0x124u) = cpu->edx;
    x87_p2 = (x87_p2) - (value_216);
    *(float*)(cpu->esp + 0xF8u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y);
    x87_p2 = (x87_p2) - (x87_p0);
    *(float*)(cpu->esp + 0xFCu) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z);
    x87_p2 = (x87_p2) - (x87_p1);
    *(float*)(cpu->esp + 0x100u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xF8u);
    x87_p2 = (x87_p2) * (value_215);
    *(float*)(cpu->esp + 0x104u) = x87_p2; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x104u);
    x87_p2 = (double)*(float*)(cpu->esp + 0xFCu);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->eax;
    x87_p2 = (x87_p2) * (value_215);
    *(float*)(cpu->esp + 0x108u) = x87_p2; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x108u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x100u);
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->ecx;
    value_211 = value_215 * x87_p2; 
    value_222 = x87_p1; x87_p1 = value_211;
    *(float*)(cpu->esp + 0x10Cu) = x87_p1; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x104u);
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->edx;
    x87_p2 = (double)*(float*)(cpu->esp + 0x28u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 + x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xF8u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p3 = x87_p2;
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->esp + 0x108u)));
    *(float*)(cpu->esp + 0xFCu) = x87_p3; 
    *(float*)(cpu->esp + 0x100u) = ((((double)*(float*)(cpu->esp + 0x10Cu))) + (((double)*(float*)(cpu->esp + 0x30u))));
    x87_p3 = (double)*(float*)(cpu->esp + 0xF8u);
    value_81 = value_216 + x87_p3; 
    value_212 = x87_p2; x87_p2 = value_81;
    *(float*)(cpu->esp + 0x18u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xFCu);
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x100u);
    value_82 = value_222 + x87_p1; 
    value_213 = x87_p0; x87_p0 = value_82;
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0xF8u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xFCu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    std::swap(x87_p3, x87_p2);
    *(float*)(cpu->esp + 0x100u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0xF8u);
    x87_p3 = (x87_p3) * (value_113);
    *(float*)(cpu->esp + 0x104u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0xFCu);
    x87_p3 = (x87_p3) * (value_113);
    *(float*)(cpu->esp + 0x108u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x100u);
    value_83 = value_113 * x87_p3; 
    value_214 = x87_p2; x87_p2 = value_83;
    *(float*)(cpu->esp + 0x10Cu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x104u);
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x104u) = cpu->eax;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x108u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10Cu);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ecx;
    value_84 = value_214 + x87_p0; 
    *(float*)(cpu->esp + 0x20u) = value_84; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    value_85 = 0.009999999776482582;
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->edx;
    value_86 = (value_213) * (value_85);
    *(float*)(cpu->esp + 0xF8u) = value_86; 
    value_87 = (value_212) * (value_85);
    *(float*)(cpu->esp + 0xFCu) = value_87; 
    value_88 = (value_85) * (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x100u) = value_88; 
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->esp + 0xF8u))) + (((double)*(float*)(cpu->esp + 0x18u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    value_89 = (double)*(float*)(cpu->esp + 0xFCu);
    *(uint32_t*)(cpu->esp + 0xF8u) = cpu->eax;
    value_90 = (value_89) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    cpu->eax = cpu->esp + 0x11Cu;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x30u) = value_90; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    value_91 = (double)*(float*)(cpu->esp + 0x104u);
    *(uint32_t*)(cpu->esp + 0x100u) = cpu->ecx;
    value_92 = (value_91) + (((double)*(float*)(cpu->esp + 0x24u)));
    cpu->ecx = cpu->esp + 0x108u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    *(float*)(cpu->esp + 0x38u) = value_92; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458212u)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x458212u));
    cpu->edx = cpu->esp + 0x110u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0xFCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45822Cu)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x45822Cu));
    cpu->ecx = cpu->esp + 0x128u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_view_motion_runtime.projected_b.x.u32);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458243u)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x458243u));
    cpu->edx = cpu->esp + 0x134u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_view_motion_runtime.projected_a.x.u32);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45825Cu)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x45825Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x104u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x108u);
    g_sfera_view_motion_runtime.projected_b.x.u32 = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10Cu);
    *(uint32_t*)((uintptr_t)&g_sfera_view_motion_runtime.projected_b.y.u32) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xF8u);
    *(uint32_t*)((uintptr_t)&g_sfera_view_motion_runtime.projected_b.z.u32) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xFCu);
    g_sfera_view_motion_runtime.projected_a.x.u32 = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x100u);
    *(uint32_t*)((uintptr_t)&g_sfera_view_motion_runtime.projected_a.y.u32) = cpu->ecx;
    *(uint32_t*)((uintptr_t)&g_sfera_view_motion_runtime.projected_a.z.u32) = cpu->edx;
     if (cpu->esi != 1u) goto label_00058876;
    if (cpu->eax != cpu->esi) goto label_00058876;
    x87_p0 = 0.0;
    std::memmove((void*)(cpu->esp + 0xB8u),(void*)((uintptr_t)&g_sfera_model_transform_scratch_matrix),64u);
    *(float*)(cpu->esp + 0xC4u) = x87_p0;
    *(float*)(cpu->esp + 0xD4u) = x87_p0;
    *(float*)(cpu->esp + 0xE4u) = x87_p0; 
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x))) - (((double)g_sfera_view_motion_runtime.reference_point.x.f32)));
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y);
    x87_p0 = (x87_p0) - (((double)g_sfera_view_motion_runtime.reference_point.y.f32));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    x87_p0 = (x87_p0) - (((double)g_sfera_view_motion_runtime.reference_point.z.f32));
    cpu->ecx = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].y);
    g_sfera_view_motion_runtime.reference_point.y.u32 = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].x);
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    cpu->edx = sfera_f32_bits(g_sfera_view_geometry_runtime.reference_points[0].z);
    cpu->edi = cpu->esp + 0x150u;
    cpu->edi &= 0xFFFFFFF0u;
    g_sfera_view_motion_runtime.reference_point.z.u32 = cpu->edx;
    g_sfera_view_motion_runtime.reference_point.x.u32 = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x140u) = cpu->edi;
    cpu->esi = cpu->esp + 0xB8u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u;
    cpu->edx = cpu->esp + 0x28u;
    cpu->ecx = cpu->esp + 0x140u;
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->ecx))->inverseTransformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esp + 0x104u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esp + 0x108u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esp + 0x10Cu))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.z))) * (0.5));
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = std::tan(x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x10u))) * (((double)*(float*)(cpu->esp + 0x24u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 / x87_p2; 
    x87_p2 = (double)g_sfera_static_render_lookup_runtime.projection_scale;
    x87_p0 = x87_p0 * x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p1; 
    x87_p0 = (((double)*(float*)(cpu->esp + 0x2Cu))) / (x87_p0);
    x87_p0 = (x87_p0) * (((double)(*(float*)(void*)&g_sfera_main_view_state_runtime.projection_scale)));
    x87_p0 = (x87_p0) * (1.3333300352096558);
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x128u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0x11Cu)));
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x10u)));
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32);
    x87_p1 = (x87_p1) + (x87_p0);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x12Cu);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->esp + 0x120u)));
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->esp + 0x24u)));
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
    x87_p2 = (x87_p2) + (x87_p1);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32) = x87_p2; 
    x87_p2 = (double)g_sfera_main_input_state_runtime.camera_step;
    x87_p2 = (x87_p2) + (x87_p0);
    g_sfera_main_input_state_runtime.camera_step = x87_p2; 
    x87_p2 = (double)g_sfera_recovered_static_runtime.cursor_accumulator;
    x87_p2 = (x87_p2) + (x87_p1);
    g_sfera_recovered_static_runtime.cursor_accumulator = x87_p2; 
    *(float*)(cpu->esp + 0x10u) = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_p2 = x87_p0;
    x87_p3 = 256.0;
    x87_p2 = (x87_p2) * (x87_p3);
    x87_p4 = (double)*(float*)(cpu->esp + 0x10u); x87_p5 = x87_p4;
    x87_p2 = x87_p2 / x87_p5; 
    x87_p5 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32);
    x87_p2 = x87_p2 + x87_p5; 
    std::swap(x87_p4, x87_p2);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32) = x87_p4; 
    x87_p4 = x87_p1;
    x87_p3 = x87_p3 * x87_p4; 
    x87_p2 = x87_p3 / x87_p2; 
    x87_p2 = (((double)g_sfera_view_motion_runtime.motion_terms[1].f32)) - (x87_p2);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32) = x87_p2; 
    x87_p2 = 0.00390625; x87_p3 = x87_p2;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p2; 
    x87_p0 = x87_p0 * x87_p1; 
    *(float*)(cpu->esp + 0x3Cu) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    x87_p0 = std::cos(x87_p0);
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    x87_p0 = std::sin(x87_p0);
    *(float*)(cpu->esp + 0x38u) = x87_p0; 
    x87_p0 = (double)g_sfera_static_render_lookup_runtime.view_phase;
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u); x87_p2 = x87_p1;
    x87_p3 = (double)*(float*)(cpu->esp + 0x24u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0x3Cu); x87_p5 = x87_p4;
    x87_p6 = (double)*(float*)(cpu->esp + 0x38u); x87_p7 = x87_p6;
    x87_p5 = x87_p5 * x87_p7; 
    std::swap(x87_p6, x87_p2);
    x87_p5 = x87_p6 - x87_p5; 
    *(float*)(cpu->esp + 0x10u) = x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = x87_p0 - x87_p5; 
    std::swap(x87_p4, x87_p0);
    g_sfera_static_render_lookup_runtime.view_phase = x87_p4; 
    x87_p4 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32);
    std::swap(x87_p4, x87_p1);
    x87_p2 = x87_p2 * x87_p4; 
    x87_p0 = x87_p0 * x87_p3; 
    x87_p0 = x87_p0 + x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p1; 
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    *(double*)(cpu->esp + 0x28u) = x87_p0;
     x87_p0 = (double)*(float*)(cpu->esp + 0x138u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0x12Cu)));
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esp + 0x134u))) - (((double)*(float*)(cpu->esp + 0x128u))));
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32) = ((*(double*)(cpu->esp + 0x28u)) - (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32);
    lift_cmp[0]=x87_p1<x87_p0;
    x87_p2 = (double)g_sfera_recovered_static_runtime.ui_cell_width;
     value_97 = x87_p2; value_98 = x87_p1; value_99 = x87_p0; if (!lift_cmp[0]) { value_2 = value_98; goto label_000585E2; } value_1 = value_98;
label_000585C5:
    x87_p0 = value_97;
    value_100 = value_1 + x87_p0; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32) = value_100; 
    value_101 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32);
    lift_cmp[1]=value_101<value_99;
    if (lift_cmp[1]) { value_1 = value_101; goto label_000585C5; } value_2 = value_101;
label_000585E2:
    x87_p0 = value_97;
     value_102 = x87_p0; { const double lift_left=value_102; const double lift_right=value_2; if (lift_left<=lift_right) { value_3 = value_2; goto label_000585F3; } }
     value_4 = value_2; goto label_00058610;
label_000585F1:
     value_3 = value_104;
label_000585F3:
    x87_p0 = value_97;
    value_103 = value_3 - x87_p0; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32) = value_103; 
    value_104 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32);
    if ((value_104)>=(value_102)) goto label_000585F1;
      value_4 = value_104;
label_00058610:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
    lift_cmp[2]=x87_p0<value_99;
    x87_p1 = (double)g_sfera_main_ui_state_runtime.scene_factor;
     value_105 = x87_p1; value_106 = x87_p0; if (!lift_cmp[2]) { value_7 = value_106; value_8 = value_4; goto label_00058642; } value_5 = value_106; value_6 = value_4;
label_00058625:
    x87_p0 = value_105;
    value_107 = value_5 + x87_p0; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32) = value_107; 
    value_108 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
    lift_cmp[3]=value_108<value_99;
    if (lift_cmp[3]) { value_5 = value_108; goto label_00058625; } value_7 = value_108; value_8 = value_6;
label_00058642:
    x87_p0 = value_105;
     value_109 = x87_p0; { const double lift_left=value_109; const double lift_right=value_7; if (lift_left<=lift_right) { value_9 = value_7; value_10 = value_8; goto label_00058653; } }
     value_11 = value_8; goto label_00058670;
label_00058651:
     value_9 = value_111;
label_00058653:
    x87_p0 = value_105;
    value_110 = value_9 - x87_p0; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32) = value_110; 
    value_111 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
    if ((value_111)>=(value_109)) goto label_00058651;
      value_11 = value_10;
label_00058670:
    value_114 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32);
    lift_cmp[4]=value_114<value_99;
    x87_p0 = 25.600000381469727;
     value_115 = x87_p0; if (!lift_cmp[4]) { value_14 = value_114; value_15 = value_11; goto label_000586A2; } value_12 = value_114; value_13 = value_11;
label_00058687:
    value_116 = (value_12) + (value_115);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32) = value_116; 
    value_117 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32);
    lift_cmp[5]=value_117<value_99;
    if (lift_cmp[5]) { value_12 = value_117; goto label_00058687; } value_14 = value_117; value_15 = value_13;
label_000586A2:
    { const double lift_left=value_115; const double lift_right=value_14; if (lift_left<=lift_right) { value_16 = value_14; value_17 = value_15; goto label_000586B1; } }
     value_18 = value_15; goto label_000586CC;
label_000586AF:
     value_16 = value_120;
label_000586B1:
    value_119 = (value_16) - (value_115);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32) = value_119; 
    value_120 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32);
    if ((value_120)>=(value_115)) goto label_000586AF;
      value_18 = value_17;
label_000586CC:
    value_121 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32);
    lift_cmp[6]=value_121<value_99;
    x87_p0 = 32.0;
     value_122 = x87_p0; if (!lift_cmp[6]) { value_21 = value_121; value_22 = value_18; goto label_000586FE; } value_19 = value_121; value_20 = value_18;
label_000586E3:
    value_123 = (value_19) + (value_122);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32) = value_123; 
    value_125 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32);
    lift_cmp[7]=value_125<value_99;
    if (lift_cmp[7]) { value_19 = value_125; goto label_000586E3; } value_21 = value_125; value_22 = value_20;
label_000586FE:
    x87_p0 = (double)32.0f;
     value_126 = x87_p0; { const double lift_left=value_126; const double lift_right=value_21; if (lift_left<=lift_right) { value_23 = value_21; value_24 = value_22; goto label_00058715; } }
     value_25 = value_21; value_26 = value_22; goto label_00058732;
label_00058713:
     value_23 = value_128;
label_00058715:
    value_127 = (value_23) - (value_122);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32) = value_127; 
    value_128 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32);
    if ((value_128)>=(value_126)) goto label_00058713;
      value_25 = value_128; value_26 = value_24;
label_00058732:
    x87_p0 = (double)g_sfera_static_render_lookup_runtime.view_phase;
    lift_cmp[8]=x87_p0<value_99;
    x87_p1 = 1.0;
     value_129 = x87_p1; value_130 = x87_p0; if (!lift_cmp[8]) { value_30 = value_130; value_31 = value_25; value_32 = value_26; goto label_0005875E; } value_27 = value_130; value_28 = value_25; value_29 = value_26;
label_00058743:
    value_131 = (value_27) + (value_129);
    g_sfera_static_render_lookup_runtime.view_phase = value_131; 
    value_132 = (double)g_sfera_static_render_lookup_runtime.view_phase;
    lift_cmp[9]=value_132<value_99;
    if (lift_cmp[9]) { value_27 = value_132; goto label_00058743; } value_30 = value_132; value_31 = value_28; value_32 = value_29;
label_0005875E:
    { const double lift_left=1.0; const double lift_right=value_30; if (lift_left<=lift_right) { value_33 = value_30; value_34 = value_31; value_35 = value_32; goto label_0005876F; } }
     value_36 = value_31; value_37 = value_32; goto label_0005878E;
label_0005876D:
     value_33 = value_135;
label_0005876F:
    value_133 = (value_33) - (value_129);
    g_sfera_static_render_lookup_runtime.view_phase = value_133; 
    value_134 = 1.0;
    x87_p0 = (double)g_sfera_static_render_lookup_runtime.view_phase;
     value_135 = x87_p0; if ((value_135)>=(value_134)) goto label_0005876D;
      value_36 = value_34; value_37 = value_35;
label_0005878E:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32);
     value_136 = x87_p0; { const double lift_left=value_136; const double lift_right=value_99; if (!(lift_left<lift_right)) { value_41 = value_136; value_42 = value_36; value_43 = value_37; goto label_000587B4; } } value_38 = value_136; value_39 = value_36; value_40 = value_37;
label_0005879D:
    value_137 = (value_38) + (value_129);
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32) = value_137; 
    value_138 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32);
    { const double lift_left=value_138; const double lift_right=value_99; if (lift_left<lift_right) { value_38 = value_138; goto label_0005879D; } } value_41 = value_138; value_42 = value_39; value_43 = value_40;
label_000587B4:
    { const double lift_left=1.0; const double lift_right=value_41; if (!(lift_left<=lift_right)) { value_47 = value_42; value_48 = value_43; goto label_000587DA; } } value_44 = value_41; value_45 = value_42; value_46 = value_43;
label_000587BF:
    value_139 = (value_44) - (value_129);
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32) = value_139; 
    value_140 = 1.0;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32);
     value_141 = x87_p0; { const double lift_left=value_141; const double lift_right=value_140;   if (lift_left>=lift_right) { value_44 = value_141; goto label_000587BF; } } value_47 = value_45; value_48 = value_46;
label_000587DA:
    value_142 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    lift_cmp[10]=value_142<value_99;
    value_143 = 6.283185958862305;
    if (!lift_cmp[10]) { value_52 = value_142; value_53 = value_47; value_54 = value_48; goto label_0005880E; } value_49 = value_142; value_50 = value_47; value_51 = value_48;
label_000587F3:
    value_144 = (value_49) + (value_143);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32) = value_144; 
    value_145 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    lift_cmp[11]=value_145<value_99;
    if (lift_cmp[11]) { value_49 = value_145; goto label_000587F3; } value_52 = value_145; value_53 = value_50; value_54 = value_51;
label_0005880E:
    { const double lift_left=value_143; const double lift_right=value_52; if (lift_left<=lift_right) { value_55 = value_52; value_56 = value_53; value_57 = value_54; goto label_0005881D; } }
     value_58 = value_52; value_59 = value_53; value_60 = value_54; goto label_00058838;
label_0005881B:
     value_55 = value_147;
label_0005881D:
    value_146 = (value_55) - (value_143);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32) = value_146; 
    value_147 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    if ((value_147)>=(value_143)) goto label_0005881B;
      value_58 = value_147; value_59 = value_56; value_60 = value_57;
label_00058838:
    x87_p0 = value_97;
    value_148 = value_60 - x87_p0; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32) = value_148; 
    value_149 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
    value_150 = (value_149) - (value_105);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32) = value_150; 
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32) = ((((double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32))) - (25.600000381469727));
    value_151 = (value_59) - (32.0);
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32) = value_151; 
     value_61 = value_58; value_62 = value_105; value_63 = value_97; value_64 = value_99; goto label_000588D8;
label_00058876:
    cpu->esi = native_function_address32(&::rand);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    g_sfera_static_render_lookup_runtime.view_phase = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) / (32767.0));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)((uintptr_t)&g_sfera_render_sample_runtime.phase.f32) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) / (32767.0));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) / (32767.0));
    x87_p0 = (double)g_sfera_recovered_static_runtime.ui_cell_width;
    x87_p1 = (double)g_sfera_main_ui_state_runtime.scene_factor;
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    x87_p3 = 0.0;
    std::swap(x87_p3, x87_p0);
    std::swap(x87_p3, x87_p1);
    std::swap(x87_p3, x87_p2);
     value_152 = x87_p3; value_153 = x87_p2; value_154 = x87_p1; value_155 = x87_p0;  value_61 = value_152; value_62 = value_153; value_63 = value_154; value_64 = value_155;
label_000588D8:
    sub_pred[0] = (uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32);
    x87_p0 = (x87_p0) / (value_63);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
    x87_p0 = (x87_p0) / (value_62);
    *(float*)(cpu->esp + 0x3Cu) = x87_p0; 
    if (sub_pred[0]) { value_65 = value_61; value_66 = value_62; value_67 = value_63; value_68 = value_64; goto label_00058911; }
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32);
    x87_p0 = (x87_p0) / (value_63);
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32);
    x87_p0 = (x87_p0) / (value_62);
    *(float*)(cpu->esp + 0x3Cu) = x87_p0;  value_65 = value_61; value_66 = value_62; value_67 = value_63; value_68 = value_64;
label_00058911:
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    value_69 = value_65; value_70 = value_66; value_71 = value_67; value_72 = value_68; goto label_0005894B;
label_00058919:
    value_156 = (double)g_sfera_recovered_static_runtime.ui_cell_width;
    value_157 = (double)g_sfera_main_ui_state_runtime.scene_factor;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
     value_158 = x87_p0; value_61 = value_158; value_62 = value_157; value_63 = value_156; value_64 = value_112; goto label_000588D8;
label_00058931:
    x87_p0 = (double)g_sfera_recovered_static_runtime.ui_cell_width;
    x87_p1 = (double)g_sfera_main_ui_state_runtime.scene_factor;
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    x87_p3 = 0.0;
    std::swap(x87_p3, x87_p0);
    std::swap(x87_p3, x87_p1);
    std::swap(x87_p3, x87_p2);
     value_159 = x87_p3; value_160 = x87_p2; value_161 = x87_p1; value_162 = x87_p0;  value_69 = value_159; value_70 = value_160; value_71 = value_161; value_72 = value_162;
label_0005894B:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u))));
    cpu->esi = cpu->edi;
    cpu->ebx=0u;
    cpu->esi <<= 5u;
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    x87_p0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->esi += (uint64_t)(sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::rhw));
    x87_p1 = x87_p0;
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(double*)(cpu->esp + 0x28u) = x87_p1;
     value_163 = x87_p0; value_73 = value_163; value_74 = value_69; value_75 = value_70; value_76 = value_71; value_77 = value_72; goto label_00058994;
label_00058974:
    x87_p0 = (double)g_sfera_recovered_static_runtime.ui_cell_width;
    x87_p1 = (double)g_sfera_main_ui_state_runtime.scene_factor;
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    x87_p3 = (double)*(float*)(cpu->esp + 0x24u);
    x87_p4 = 0.0;
    std::swap(x87_p4, x87_p0);
    std::swap(x87_p4, x87_p1);
    std::swap(x87_p4, x87_p2);
    std::swap(x87_p4, x87_p3);
     value_164 = x87_p4; value_165 = x87_p3; value_166 = x87_p2; value_167 = x87_p1; value_168 = x87_p0;  value_73 = value_164; value_74 = value_165; value_75 = value_166; value_76 = value_167; value_77 = value_168;
label_00058994:
    sub_pred[1] = (uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u;
    *(float*)(cpu->esi + 0xFFFFFFFCu) = value_77; 
    *(float*)(cpu->esi) = (double)(1.0);
    *(float*)(cpu->esp + 0x14u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    value_169 = (double)*(float*)(cpu->esp + 0x14u);
    value_170 = value_76 * value_169; 
     if (!sub_pred[1]) goto label_000589CB;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[4].f32);
    value_171 = value_170 + x87_p0; 
    *(float*)(cpu->esi + 0xFFFFFFF4u) = value_171; 
    value_172 = value_73 * value_75; 
    value_173 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[3].f32);
     value_78 = value_173; value_79 = value_74; value_80 = value_172; goto label_000589E0;
label_000589CB:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[2].f32);
    value_174 = value_170 + x87_p0; 
    *(float*)(cpu->esi + 0xFFFFFFF4u) = value_174; 
    value_175 = value_73 * value_75; 
    value_176 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[1].f32);
      value_78 = value_176; value_79 = value_74; value_80 = value_175;
label_000589E0:
    value_177 = value_80 + value_78; 
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esi + 0x10u;
    cpu->ecx = cpu->esi + 0xCu;
    *(float*)(cpu->esi + 0xFFFFFFF8u) = value_177; 
    *(float*)(cpu->esp + 8u) = value_79; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esi + 0xFFFFFFF8u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esi + 0xFFFFFFF4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458A06u)); sfera_sub_0044E090(cpu, LIFT_CODE_TOKEN_VA(0x458A06u));
    sub_pred[2] = (uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u;
    value_178 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x);
    value_179 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x); 
    value_180 = value_178 - value_179; 
    *(float*)(cpu->esp + 0xA0u) = value_180; 
    value_181 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y);
    value_182 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y); x87_p0 = value_182;
    value_183 = value_181 - x87_p0; 
    *(float*)(cpu->esp + 0xA4u) = value_183; 
    value_184 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z); x87_p1 = x87_p0;
    value_185 = value_184 - x87_p1; 
    value_217 = x87_p0; x87_p0 = value_185;
    *(float*)(cpu->esp + 0xA8u) = x87_p0; 
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) + (((double)*(float*)(cpu->esp + 0x10u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0xA0u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x40u) = x87_p1; 
    x87_p1 = x87_p0;
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esp + 0xA4u)));
    *(float*)(cpu->esp + 0x44u) = x87_p1; 
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0xA8u)));
    *(float*)(cpu->esp + 0x48u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x40u);
    x87_p1 = 0.10000000149011612;
    x87_p0 = (x87_p0) * (x87_p1);
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x11Cu) = cpu->eax;
    x87_p1 = (x87_p1) * (x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x120u) = cpu->ecx;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x);
    *(uint32_t*)(cpu->esp + 0x124u) = cpu->edx;
    x87_p0 = (x87_p0) - (value_179);
     value_186 = x87_p0; if (!sub_pred[2]) goto label_00058B70;
    *(float*)(cpu->esp + 0x88u) = value_186; 
    value_187 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y);
    value_188 = (value_187) - (value_182);
    *(float*)(cpu->esp + 0x8Cu) = value_188; 
    value_189 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z);
    value_190 = (value_189) - (value_217);
    *(float*)(cpu->esp + 0x90u) = value_190; 
    *(float*)(cpu->esp + 0x14u) = *(double*)(cpu->esp + 0x28u);
    value_191 = (double)*(float*)(cpu->esp + 0x88u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u); x87_p1 = x87_p0;
    value_192 = value_191 * x87_p1; 
    value_218 = x87_p0; x87_p0 = value_192;
    *(float*)(cpu->esp + 0x58u) = x87_p0; 
    x87_p0 = value_218;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x8Cu)));
    *(float*)(cpu->esp + 0x5Cu) = x87_p0; 
    value_193 = (value_218) * (((double)*(float*)(cpu->esp + 0x90u)));
    *(float*)(cpu->esp + 0x60u) = value_193; 
    value_194 = (double)*(float*)(cpu->esp + 0x58u);
    x87_p0 = 0.125;
    value_195 = (value_194) * (x87_p0);
    value_219 = x87_p0; x87_p0 = value_195;
    *(float*)(cpu->esp + 0x64u) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x64u);
    x87_p0 = (double)*(float*)(cpu->esp + 0x5Cu);
    x87_p0 = (x87_p0) * (value_219);
    *(float*)(cpu->esp + 0x68u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    value_196 = (value_219) * (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->esp + 0x6Cu) = value_196; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
     goto label_00058BE2;
label_00058B70:
    *(float*)(cpu->esp + 0x4Cu) = value_186; 
    value_197 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y);
    value_198 = (value_197) - (value_182);
    *(float*)(cpu->esp + 0x50u) = value_198; 
    value_199 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z);
    value_200 = (value_199) - (value_217);
    *(float*)(cpu->esp + 0x54u) = value_200; 
    value_201 = *(double*)(cpu->esp + 0x28u);
    x87_p0 = 0.125;
    value_202 = (value_201) * (x87_p0);
    value_220 = x87_p0; x87_p0 = value_202;
    x87_p0 = (x87_p0) * (0.75);
    value_203 = value_220 + x87_p0; 
    *(float*)(cpu->esp + 0x14u) = value_203; 
    value_204 = (double)*(float*)(cpu->esp + 0x4Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u); x87_p1 = x87_p0;
    value_205 = value_204 * x87_p1; 
    value_221 = x87_p0; x87_p0 = value_205;
    *(float*)(cpu->esp + 0x7Cu) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    x87_p0 = value_221;
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0x80u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x80u);
    value_206 = (value_221) * (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x84u) = value_206; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
label_00058BE2:
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->eax;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x110u)));
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->edx;
    *(float*)(cpu->esp + 0x94u) = x87_p0; 
    *(float*)(cpu->esp + 0x98u) = ((((double)*(float*)(cpu->esp + 0x1Cu))) + (((double)*(float*)(cpu->esp + 0x114u))));
    *(float*)(cpu->esp + 0x9Cu) = ((((double)*(float*)(cpu->esp + 0x20u))) + (((double)*(float*)(cpu->esp + 0x118u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x94u);
    value_207 = value_179 + x87_p0; 
    *(float*)(cpu->esp + 0xACu) = value_207; 
    value_208 = (value_182) + (((double)*(float*)(cpu->esp + 0x98u)));
    *(float*)(cpu->esp + 0xB0u) = value_208; 
    value_209 = (value_217) + (((double)*(float*)(cpu->esp + 0x9Cu)));
    *(float*)(cpu->esp + 0xB4u) = value_209; 
    *(float*)(cpu->esp + 0x70u) = ((((double)*(float*)(cpu->esp + 0xACu))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    *(float*)(cpu->esp + 0x74u) = ((((double)*(float*)(cpu->esp + 0xB0u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y)));
    *(float*)(cpu->esp + 0x78u) = ((((double)*(float*)(cpu->esp + 0xB4u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z)));
     if (cpu->ebx != 0u) goto label_00058C9C;
    if (*(uint32_t*)(cpu->esp + 0x38u) != cpu->ebx) goto label_00058C9C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_00058C9E;
label_00058C9C:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
label_00058C9E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x80u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458CC2u)); sfera_sub_00457840(cpu, LIFT_CODE_TOKEN_VA(0x458CC2u));
    x87_p0 = (double)g_sfera_main_ui_state_runtime.scene_scale;
    cpu->eax = g_sfera_recovered_static_runtime.render_state_09;
    *(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.projection_samples[0])) = x87_p0; 
    x87_p0 = (double)g_sfera_main_command_state_runtime.sky_blend_factor;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->eax = g_sfera_render_lookup_runtime.alpha_component;
    *(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.command_samples[0])) = x87_p0;
    x87_p1 = (double)1.5099999904632568f;
    cpu->ecx = cpu->eax;
    cpu->eax|=0xFFFFFF00u;
    lift_cmp[12]=x87_p1>x87_p0;
    cpu->eax <<= 8u;
    cpu->ecx &= 0xFFu;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    if (!lift_cmp[12]) goto label_00058D19;
    cpu->eax = 1u;
    goto label_00058D1B;
label_00058D19:
    cpu->eax = 0u;
label_00058D1B:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.environment_parameter.f32);
    ++cpu->ebx;
    *(float*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_render_sample_runtime.samples[0])) = x87_p0; 
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.sample_flags[0])) = cpu->eax;
    ++cpu->edi;
    cpu->esi += 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)0xCu) goto label_00058974;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0xAu) goto label_00058931;
    cpu->eax = 0u;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 9u;
    (void)cpu;
label_00058D60:
    cpu->ebx = 0xBu;
label_00058D70:
    cpu->ecx = cpu->edi & 0xFFFFu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[0])) = cpu->ecx & 0xFFFFu;
    cpu->edx = cpu->ecx + 1u;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[1])) = cpu->edx & 0xFFFFu;
    cpu->esi = cpu->ecx + 0xCu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[2])) = cpu->esi & 0xFFFFu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[3])) = cpu->edx & 0xFFFFu;
    cpu->ecx += 0xDu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[4])) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_sky_runtime.indices[5])) = cpu->esi & 0xFFFFu;
    cpu->eax += 6u;
    ++cpu->edi;
    if ((--cpu->ebx) != 0u) goto label_00058D70;
    ++cpu->edi;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_00058D60;
    if (g_sfera_main_render_runtime.secondary_render_pass == cpu->ebx) goto label_00058DE0;
    cpu->ecx = (uintptr_t)"black";
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"black";
    goto label_00058DFD;
label_00058DE0:
    cpu->ecx = (uintptr_t)"stars";
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"stars";
label_00058DFD:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Du);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x1C4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetFVF(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), "SetFVF")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0x252u); lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]); lift_push32(cpu, 0x78u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xEu); lift_push32(cpu, 4u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawVertices(static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), SferaAbi::pointer<const std::uint16_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)); cpu->esp += 28u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(static_cast<D3DRENDERSTATETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), "SetRenderState")); cpu->esp += 8u;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_motion_runtime.motion_terms[0].f32);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
     value_210 = x87_p0; cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; result = value_210; return true;
}
__declspec(noinline) void sfera_sub_00458E80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp < 0) goto label_0005904B;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058EA2;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58EA2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58EA2u));
    label_00058EA2:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebp * 4u)) == 0u) goto label_0005904B;
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058EC5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58EC5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58EC5u));
    label_00058EC5:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->edi += 0x44u;
    cpu->ebx = 0x1B58u;
    label_00058EE0:
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0xFFFFFFFFu) goto label_00058F1E;
    if ((int32_t)cpu->esi >= 0) goto label_00058EF5;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58EF5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58EF5u));
    label_00058EF5:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00058F09;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F09u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58F09u));
    label_00058F09:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->eax) != 0u) goto label_00058F1E;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    WorldGuiControls::destroyText(cpu->ecx);
    label_00058F1E:
    cpu->edi += 4u;
    if ((--cpu->ebx) != 0u) goto label_00058EE0;
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count <= (int32_t)cpu->esi) goto label_00058FE1;
    label_00058F35:
    if ((int32_t)cpu->esi >= 0) goto label_00058F43;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F43u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58F43u));
    label_00058F43:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058F57;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F57u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58F57u));
    label_00058F57:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_00058F66;
    ++cpu->esi;
    goto label_00058F35;
    label_00058F66:
    if ((int32_t)cpu->esi >= 0) goto label_00058F74;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F74u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58F74u));
    label_00058F74:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058F88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58F88u));
    label_00058F88:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6DA4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->edx + 0x6DA4u)) goto label_00058FD3;
    if ((int32_t)cpu->esi >= 0) goto label_00058FB1;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58FB1u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x58FB1u));
    label_00058FB1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058FC5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58FC5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58FC5u));
    label_00058FC5:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    --*(uint32_t*)(cpu->eax + 0x6DA4u);
    label_00058FD3:
    ++cpu->edi;
    ++cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count) goto label_00058F35;
    label_00058FE1:
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00058FF5;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58FF5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x58FF5u));
    label_00058FF5:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->ebp * 4u));
    lift_push32(cpu, 0x2E59u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45900Du)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45900Du));
    if ((int32_t)cpu->ebp < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_00059021;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59021u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59021u));
    label_00059021:
    cpu->edx = g_sfera_interface_runtime.windows.data;
    *(uint32_t*)(cpu->edx + (cpu->ebp * 4u)) = 0u;
    g_sfera_main_command_state_runtime.window_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count)) - 1u;
    if (g_sfera_window_runtime.active_window_index != cpu->ebp) goto label_00059046;
    g_sfera_window_runtime.active_window_index = 0xFFFFFFFFu;
    label_00059046:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005904B:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00059058:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00059058;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"delete_window: wrong handle"),28u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0044F500(cpu, stop_address); return;
}





__declspec(noinline) void sfera_sub_00459530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_world_render_runtime.render_queue_count;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if (cpu->eax != 0u) goto label_00059544;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00059544:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_world_render_queue_runtime.entries[0]));
    if ((int32_t)cpu->esi >= 0) goto label_0005955A;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5955Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5955Au));
    label_0005955A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005956E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5956Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5956Eu));
    label_0005956E:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->edx = cpu->ebx;
    cpu->edx -= cpu->eax;
    label_00059590:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059590;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = g_sfera_world_render_runtime.render_queue_count;
    cpu->ecx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_world_render_queue_runtime.entries[0]));
    g_sfera_world_objects.destroy(cpu->ecx);
    --g_sfera_world_render_runtime.render_queue_count;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004595F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x90u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (g_sfera_view_motion_runtime.mode_value == cpu->edi) goto label_00059648;
    cpu->esi = native_function_address32(&::ShowCursor);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(cpu->edi);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax >= 0) goto label_00059629;
    label_00059621:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax < 0) goto label_00059621;
    label_00059629:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, (uintptr_t)"Reenter in epilog detected!"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x45963Bu));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x59642u));
    label_00059648:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    g_sfera_view_motion_runtime.mode_value = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45965Eu)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x45965Eu));
    if (g_sfera_world_render_runtime.world_spatial_index == cpu->edi) goto label_00059695;
    cpu->edx = 0x44Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459675u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459675u));
    cpu->ecx = g_sfera_world_render_runtime.world_spatial_index;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_0005968F;
    std::destroy_at(SferaAbi::pointer<SphereWorld::DynamicVegetation>(cpu->ecx));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45968Cu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x45968Cu));
    cpu->esp += 4u;
    label_0005968F:
    g_sfera_world_render_runtime.world_spatial_index = cpu->edi;
    label_00059695:
    if (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01 == 0u) goto label_000596AB;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->halt_all_requested = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x596ABu)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_RVA(0x596ABu));
    label_000596AB:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596B5u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x4596B5u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596BAu)); sfera_sub_004981F0(cpu, LIFT_CODE_TOKEN_VA(0x4596BAu));
    if (g_sfera_input_device_runtime.shared_object == cpu->edi) goto label_000596F1;
    cpu->edx = 0x457u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596D1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4596D1u));
    cpu->ecx = g_sfera_input_device_runtime.shared_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000596EB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596E2u)); sfera_sub_0047E0F0(cpu, LIFT_CODE_TOKEN_VA(0x4596E2u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596E8u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4596E8u));
    cpu->esp += 4u;
    label_000596EB:
    g_sfera_input_device_runtime.shared_object = cpu->edi;
    label_000596F1:
    if (g_sfera_client_process_runtime.client_object == cpu->edi) goto label_00059728;
    cpu->edx = 0x458u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459708u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459708u));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059722;
    delete SferaAbi::pointer<Contours>(cpu->ecx);
    label_00059722:
    g_sfera_client_process_runtime.client_object = cpu->edi;
    label_00059728:
    if (g_sfera_font_runtime.renderer == cpu->edi) goto label_00059757;
    cpu->edx = 0x459u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45973Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45973Fu));
    cpu->eax = g_sfera_font_runtime.renderer;
    if (cpu->eax == cpu->edi) goto label_00059751;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45974Eu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x45974Eu));
    cpu->esp += 4u;
    label_00059751:
    g_sfera_font_runtime.renderer = cpu->edi;
    label_00059757:
    if (g_sfera_main_aux_runtime.secondary_world_manager == cpu->edi) goto label_00059786;
    cpu->edx = 0x45Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45976Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45976Eu));
    cpu->eax = g_sfera_main_aux_runtime.secondary_world_manager;
    if (cpu->eax == cpu->edi) goto label_00059780;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45977Du)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x45977Du));
    cpu->esp += 4u;
    label_00059780:
    g_sfera_main_aux_runtime.secondary_world_manager = cpu->edi;
    label_00059786:
    if (g_sfera_window_runtime.input_runtime_object == cpu->edi) goto label_000597BD;
    cpu->edx = 0x45Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45979Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45979Du));
    cpu->ecx = g_sfera_window_runtime.input_runtime_object;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_000597B7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597AEu)); sfera_sub_00489810(cpu, LIFT_CODE_TOKEN_VA(0x4597AEu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597B4u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x4597B4u));
    cpu->esp += 4u;
    label_000597B7:
    g_sfera_window_runtime.input_runtime_object = cpu->edi;
    label_000597BD:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_mode;
    if (cpu->eax == cpu->edi) goto label_000597CD;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_RVA(0x597C7u));
    label_000597CD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597D2u)); sfera_sub_0042A3A0(cpu, LIFT_CODE_TOKEN_VA(0x4597D2u));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.shutdown());
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597DCu)); sfera_sub_0048DB30(cpu, LIFT_CODE_TOKEN_VA(0x4597DCu));
    g_sfera_world_objects.destroyAll();
    g_sfera_models.clear();
    label_00059818:
    if (g_sfera_recovered_static_runtime.render_state_08 == cpu->edi) goto label_0005984F;
    cpu->edx = 0x46Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45982Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45982Fu));
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059849;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459840u)); sfera_sub_0041B1E0(cpu, LIFT_CODE_TOKEN_VA(0x459840u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459846u)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x459846u));
    cpu->esp += 4u;
    label_00059849:
    g_sfera_recovered_static_runtime.render_state_08 = cpu->edi;
    label_0005984F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459854u)); sfera_sub_0044CB70(cpu, LIFT_CODE_TOKEN_VA(0x459854u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459859u)); sfera_sub_0044C110(cpu, LIFT_CODE_TOKEN_VA(0x459859u));
    if (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state == cpu->edi) goto label_00059888;
    cpu->edx = 0x473u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459870u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459870u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state;
    if (cpu->ecx == cpu->edi) goto label_00059882;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x59880u));
    label_00059882:
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_state) = cpu->edi;
    label_00059888:
    TerrainTextureCache::release();
    cpu->eax = g_sfera_window_runtime.main_window;
    if (cpu->eax == cpu->edi) goto label_000598A3;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x459897u));
    g_sfera_window_runtime.main_window = cpu->edi;
    label_000598A3:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, sfera_window_class_name());
    lift_native_call(cpu, native_function_address32(&::UnregisterClassA), LIFT_CODE_TOKEN_VA(0x4598AFu));
    lift_native_call(cpu, native_function_address32(&::CoUninitialize), LIFT_CODE_TOKEN_VA(0x4598B5u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode <= (int32_t)cpu->edi) goto label_00059A6F;
    cpu->ebx = native_function_address32(&::fflush);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::fputs);
    cpu->esi = (uintptr_t)&g_sfera_log_runtime.files[0].has_written;
    (void)cpu;
    label_000598E0:
    if (*(uint32_t*)(cpu->esi + 0xFFFFFFFCu) != cpu->edi) goto label_00059A56;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_0005990F;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"**** Quit: ");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459900u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_0005990F:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x459914u));
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x45991Fu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x459935u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0x18u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00059968;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459959u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_00059968:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00059992;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"  ");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x459983u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_00059992:
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x459997u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000599CA;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4599BBu));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_000599CA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000599F4;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"\n\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4599E5u));
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi) = 1u;
    label_000599F4:
    cpu->eax = 0u;
    if (*(uint8_t*)(cpu->esi + 0xFFFFFFC8u) == 0x2Eu) goto label_00059A10;
    label_00059A00:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->eax + 0xFFFFFFC8u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->esi + cpu->eax + 0xFFFFFFC8u) != 0x2Eu) goto label_00059A00;
    label_00059A10:
    *(uint8_t*)(cpu->esp + cpu->eax + 0x1Cu) = 0u;
    cpu->eax = cpu->esp + 0x1Cu;
    --cpu->eax;
    label_00059A20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059A20;
    cpu->ecx = *(uint32_t*)((uintptr_t)".log");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".log") + 4u));
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    if ((int32_t)cpu->eax <= (int32_t)cpu->edi) goto label_00059A54;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59A54u)); sfera_sub_0044C020(cpu, LIFT_CODE_TOKEN_RVA(0x59A54u));
    label_00059A54:
    cpu->edi = 0u;
    label_00059A56:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    cpu->esi += 0x40u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_mode) goto label_000598E0;
    cpu->ebp = lift_pop32(cpu);
    label_00059A6F:
    sub_pred[0] = (uint8_t)g_sfera_process_runtime.executable_path[0] == 0u;
    cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_00059A92;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_relaunch_runtime.argument[0]); lift_push32(cpu, (uintptr_t)&g_sfera_process_runtime.executable_path[0]); lift_push32(cpu, (uintptr_t)&g_sfera_process_runtime.executable_path[0]);
    lift_native_call(cpu, native_function_address32(&::_execl), LIFT_CODE_TOKEN_VA(0x459A89u));
    cpu->esp += 0x10u;
    label_00059A92:
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459A9Cu)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x459A9Cu));
    ::DeleteCriticalSection(&g_sfera_network_send_runtime.critical_section);

    ::DeleteCriticalSection(&g_sfera_window_runtime.timing_critical_section);

    ::DeleteCriticalSection(&g_sfera_recovered_static_runtime.scene_lock);
    if (*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled != 1u) goto label_00059AF1;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24 == cpu->edi) goto label_00059AF1;
    cpu->edx = 0x4B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AD7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x459AD7u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059AF1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AE8u)); sfera_sub_00418D50(cpu, LIFT_CODE_TOKEN_VA(0x459AE8u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AEEu)); sfera_memory_deallocate(cpu, LIFT_CODE_TOKEN_VA(0x459AEEu));
    cpu->esp += 4u;
    label_00059AF1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x90u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00459B10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    (void)stop_address;
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_view_motion_runtime.initialized)) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (sub_pred[0]) goto label_00059B58;
    cpu->esi = native_function_address32(&::ShowCursor);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(0u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax >= 0) goto label_00059B38;
    label_00059B30:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax < 0) goto label_00059B30;
    label_00059B38:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, (uintptr_t)"Reenter in exit_msg detected!"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x459B4Au));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_RVA(0x59B52u));
    label_00059B58:
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ServerN=%d  "); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]);
    g_sfera_view_motion_runtime.initialized = 1u;
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459B73u));
    cpu->eax = cpu->esi;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->eax;
    label_00059B80:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059B80;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    cpu->eax -= cpu->ecx;
    --cpu->edi;
    label_00059B92:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059B92;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->ecx = (uintptr_t)&g_sfera_warning_log_runtime.object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459BB2u)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x459BB2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459BB7u)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x459BB7u));
    if (cpu->eax == 0u) goto label_00059BFC;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    --cpu->edi;
    label_00059BC1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059BC1;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    cpu->ecx = cpu->eax;
    label_00059BD5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059BD5;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059BE6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059BE6;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    label_00059BFC:
    cpu->ecx = 0u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->edi = native_function_address32(&::fputs);
    cpu->ebx = native_function_address32(&::fflush);
    cpu->ebp = native_function_address32(&::fclose);
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00059C36;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00059C36:
    cpu->ecx = 0u;
    cpu->eax = SferaAbi::address(g_sfera_log_runtime.files[cpu->ecx].open());
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00059C5E;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"\n");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fputs)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fflush)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = 1u;
    label_00059C5E:
    cpu->esi = native_function_address32(&::ShowCursor);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(0u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((int32_t)cpu->eax >= 0) goto label_00059C7B;
    label_00059C73:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::ShowCursor)))(1u);
    if ((int32_t)cpu->eax < 0) goto label_00059C73;
    label_00059C7B:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"\316\370\350\341\352\340"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.fatal_message[0]); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x459C8Du));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459C98u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x459C98u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x459C9Au));
    cpu->eip = 0x459CA0u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00459CB0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax = cpu->edx;
    cpu->esi -= cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    label_00059CC0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->ebx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00059CC0;
    cpu->ebx = lift_pop32(cpu);
    label_00059CD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059CD0;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->edx;
    --cpu->edi;
    (void)cpu;
    label_00059CE0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059CE0;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459D02u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x459D02u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eip = 0x459D04u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00459D10(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax = cpu->edx;
    cpu->esi -= cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    label_00059D20:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->ebx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00059D20;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_00059D30:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059D30;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059D41:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059D41;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    --cpu->eax;
    label_00059D60:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00059D60;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint16_t*)(cpu->eax) = cpu->ecx & 0xFFFFu;
    *(uint8_t*)(cpu->eax + 2u) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->eax;
    label_00059D81:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00059D81;
    cpu->edi = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00059D92:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00059D92;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459DB2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x459DB2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eip = 0x459DB4u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00459E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::GetSystemMetrics);
    lift_push32(cpu, cpu->edi);
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetSystemMetrics)))(0u);
    lift_push32(cpu, 1u);
    g_sfera_scene_control_runtime.timing_anchor = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::GetSystemMetrics)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    cpu->esi = g_sfera_graphics_runtime.display_width;
    g_sfera_recovered_static_runtime.scene_state_07 = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)0x320u) goto label_00059E83;
    cpu->esi = 0x320u;
    g_sfera_graphics_runtime.display_width = cpu->esi;
    label_00059E83:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    if ((int32_t)cpu->ecx >= (int32_t)0x258u) goto label_00059E9C;
    cpu->ecx = 0x258u;
    g_sfera_graphics_runtime.display_height = cpu->ecx;
    label_00059E9C:
    cpu->ebx = 0u;
    cpu->edi = 0u;
    if (g_sfera_window_runtime.windowed == cpu->ebx) goto label_00059EF3;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ebp = 0xCA0000u;
    lift_native_call(cpu, native_function_address32(&::SetRect), LIFT_CODE_TOKEN_VA(0x459EB6u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::AdjustWindowRect), LIFT_CODE_TOKEN_VA(0x459EC3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi -= *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_recovered_static_runtime.scene_state_07) goto label_00059F33;
    cpu->esi = g_sfera_graphics_runtime.display_width;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    g_sfera_window_runtime.windowed = cpu->ebx;
    label_00059EF3:
    cpu->ebp = 0x80000000u;
    label_00059EF8:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.active_ui_object;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Sphere"); lift_push32(cpu, sfera_window_class_name()); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateWindowExA), LIFT_CODE_TOKEN_VA(0x459F16u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_window_runtime.main_window = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    if (cpu->eax != 0u) goto label_00059F51;
    cpu->ecx = (uintptr_t)"CreateWindowEx() failed! => init_main_window()";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59F33u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x59F33u));
    label_00059F33:
    cpu->eax = g_sfera_scene_control_runtime.timing_anchor;
    cpu->eax -= cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_recovered_static_runtime.scene_state_07;
    cpu->eax -= cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->edi = (int32_t)(cpu->edi) >> 1u;
    cpu->ebx = (int32_t)(cpu->ebx) >> 1u;
    goto label_00059EF8;
    label_00059F51:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::ShowWindow), LIFT_CODE_TOKEN_VA(0x459F54u));
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::InvalidateRect), LIFT_CODE_TOKEN_VA(0x459F64u));
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::UpdateWindow), LIFT_CODE_TOKEN_VA(0x459F71u));
    cpu->edx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::BringWindowToTop), LIFT_CODE_TOKEN_VA(0x459F7Eu));
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00459FA0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23, value_24, value_25, value_26, value_27, value_28, value_29, value_30, value_31, value_32, value_33, value_34, value_35, value_36;
 bool sub_pred[3]; double x87_p0;
    cpu->esp -= 0xB4u;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_09;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->edi = cpu->edx;
    if (cpu->eax == 0u) goto label_00059FE9;
    if (cpu->eax == 1u) goto label_00059FE9;
    lift_push32(cpu, (uintptr_t)&g_sfera_font_runtime.language_suffix[0]);
    cpu->eax = cpu->esp + 0x84u;
    lift_push32(cpu, (uintptr_t)"fonts\\font%s.txt"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459FDEu));
    cpu->esp += 0xCu;
    goto label_00059FFF;
label_00059FE9:
    cpu->ecx = cpu->esp + 0x80u;
    lift_push32(cpu, (uintptr_t)"fonts\\font.txt"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x459FF6u));
    cpu->esp += 8u;
label_00059FFF:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0x20020u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_font_atlas_staging_runtime);
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0])) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45A01Du));
    cpu->esp += 0xCu;
    cpu->eax = 0x100u;
    lift_push32(cpu, 0x7F9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x400u;
    g_sfera_font_atlas_staging_runtime.magic = 0x6D786554u;
    g_sfera_font_atlas_staging_runtime.width = cpu->eax;
    g_sfera_font_atlas_staging_runtime.height = cpu->eax;
    g_sfera_font_atlas_staging_runtime.mip_count = UINT32_C(1);
    g_sfera_font_atlas_staging_runtime.encoding = 0x115Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A066u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A066u));
    lift_push32(cpu, 0x7FAu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x400u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A07Eu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A07Eu));
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x7FDu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A09Cu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A09Cu));
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->edi = *(uint16_t*)(cpu->ebx + 0xAu);
    cpu->edx = *(uint16_t*)(cpu->ebx + 6u);
    cpu->ecx = cpu->ebx + cpu->esi + 0xFFFFFD00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->edi -= cpu->edx;
    cpu->ecx = cpu->esp + 0x80u;
    ++cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.fileSize(SferaAbi::pointer<const char>(cpu->ecx)));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x805u);
    cpu->ecx = cpu->esi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A0F0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A0F0u));
    cpu->ebp = cpu->eax;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x80u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebp;
    *(uint8_t*)(cpu->esi + cpu->ebp) = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.open(SferaAbi::pointer<const char>(cpu->ecx), static_cast<std::int32_t>(cpu->edx)));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.read(static_cast<std::int32_t>(cpu->ecx), SferaAbi::pointer<void>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_files.close(static_cast<std::int32_t>(cpu->ecx)));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_0005A140;
    cpu->ecx = cpu->eax;
label_0005A130:
    if (*(uint8_t*)(cpu->eax + cpu->ebp) != 0x23u) goto label_0005A137;
    ++cpu->ecx;
label_0005A137:
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->esi) goto label_0005A130;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
label_0005A140:
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x118u);
    lift_push32(cpu, 0x810u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A15Bu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A15Bu));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    cpu->eax = cpu->ebx + 0x80u;
    goto label_0005A174;
label_0005A170:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
label_0005A174:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    if ((cpu->edx & 0xFFu) <= 0xC0u) goto label_0005A18E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0x3Fu))) & 0xFFu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
label_0005A18E:
    cpu->eax = cpu->ecx & 0xFFu;
    cpu->edi -= cpu->eax;
label_0005A193:
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    ++cpu->esi;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx - 1u) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0005A193;
    if (cpu->edi != 0u) goto label_0005A170;
    cpu->edx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) <= (int32_t)cpu->edx) goto label_0005A1DA;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x38u);
label_0005A1B0:
    cpu->ecx = *(uint8_t*)(cpu->esi + cpu->edx);
    cpu->eax = cpu->edi + (cpu->ecx * 2u);
    cpu->ecx += cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (0xF0u & 0xFFu);
    if (*(uint8_t*)(cpu->ecx) <= (cpu->eax & 0xFFu)) goto label_0005A1CF;
    if (*(uint8_t*)(cpu->ecx + 1u) <= (cpu->eax & 0xFFu)) goto label_0005A1CF;
    if (*(uint8_t*)(cpu->ecx + 2u) <= (cpu->eax & 0xFFu)) goto label_0005A1CF;
    *(uint8_t*)(cpu->esi + cpu->edx) = 1u;
    goto label_0005A1D3;
label_0005A1CF:
    *(uint8_t*)(cpu->esi + cpu->edx) = 0u;
label_0005A1D3:
    ++cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_0005A1B0;
label_0005A1DA:
    lift_push32(cpu, 0x82Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A1EBu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A1EBu));
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->eax = 0u;
    cpu->edx = 0x1Au;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x4Cu) <= (int32_t)cpu->esi) goto label_0005A829;
    x87_p0 = 0.00390625;
    cpu->ecx = cpu->ebp;
     value_35 = x87_p0; value_0 = value_35; goto label_0005A229;
label_0005A225:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u); value_0 = value_34;
label_0005A229:
    if (*(uint8_t*)(cpu->ecx) == 0x23u) { value_2 = value_0; goto label_0005A235; } value_1 = value_0;
label_0005A22E:
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax + cpu->ebp) != 0x23u) goto label_0005A22E; value_2 = value_1;
label_0005A235:
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    if (*(uint8_t*)(cpu->eax + cpu->ebp + 0xFFFFFFFFu) != 0x20u) { value_4 = value_2; goto label_0005A24C; } value_3 = value_2;
label_0005A23F:
    if ((--cpu->ecx) == 0u) goto label_0005A8B2;
    if (*(uint8_t*)(cpu->ecx + cpu->ebp) == 0x20u) goto label_0005A23F; value_4 = value_3;
label_0005A24C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->ebp));
    if ((cpu->edx & 0xFFu) < 0x30u) goto label_0005A8B2;
    if ((cpu->edx & 0xFFu) > 0x39u) goto label_0005A8B2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->ebp + 0xFFFFFFFFu));
    if ((cpu->ecx & 0xFFu) < 0x41u) goto label_0005A8B2;
    if ((cpu->ecx & 0xFFu) > 0x5Au) goto label_0005A8B2;
    cpu->edi = cpu->edx & 0xFFu;
    cpu->ebx = cpu->ecx & 0xFFu;
    ++cpu->eax;
    cpu->edi -= 0x30u;
    cpu->ebx -= 0x41u;
    sub_pred[0] = *(uint8_t*)(cpu->eax + cpu->ebp) == 0x20u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    if (!sub_pred[0]) { value_6 = value_4; goto label_0005A2A4; } value_5 = value_4;
label_0005A28E:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->ebp + 1u));
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0005A8B2;
    if ((cpu->ecx & 0xFFu) == 0x20u) goto label_0005A28E; value_6 = value_5;
label_0005A2A4:
    sub_pred[1] = *(uint8_t*)(cpu->eax + cpu->ebp) == 0x27u;
    cpu->ecx = cpu->eax + cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ecx;
    if (!sub_pred[1]) goto label_0005A8B2;
    cpu->ecx = *(uint8_t*)(cpu->eax + cpu->ebp + 1u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx <<= 5u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->esi <<= 5u;
    cpu->ecx <<= 8u;
    cpu->ecx += cpu->esi;
    cpu->edx -= cpu->eax;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ecx;
    cpu->ecx = cpu->ecx + ((uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0]);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = 0x20u; value_7 = value_6;
label_0005A2F7:
    cpu->esi = 0x20u; value_8 = value_7;
label_0005A2FC:
    cpu->ebp = 0u;
    *(uint16_t*)(cpu->ecx) = cpu->ebp & 0xFFFFu;
    *(uint8_t*)(cpu->edx + cpu->eax) = 0u;
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ecx += 2u;
    ++cpu->eax;
    if ((--cpu->esi) != 0u) goto label_0005A2FC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += 0x200u;
    --*(uint32_t*)(cpu->esp + 0x24u); sub_pred[2] = *(uint32_t*)(cpu->esp + 0x24u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (!sub_pred[2]) { value_7 = value_8; goto label_0005A2F7; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1Au);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x1Au);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->ebx += 0x14u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->ebx;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x118u);
    cpu->edi += 0x14u;
    cpu->ebx += cpu->edi;
    cpu->eax += cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xC8u);
    cpu->edx = 0x60u;
    cpu->ecx += 3u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx; value_9 = value_8;
label_0005A36C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = 0u;
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx; value_10 = value_9;
label_0005A37C:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint8_t*)(cpu->esi) = cpu->ecx & 0xFFu;
    if (*(uint8_t*)(cpu->eax) == 0u) { value_18 = value_10; goto label_0005A3D9; }
    cpu->esi = 0u;
    if ((int32_t)cpu->ebx < 0) { value_18 = value_10; goto label_0005A3D9; } value_11 = value_10;
label_0005A38F:
    cpu->eax = 0u; value_12 = value_11;
label_0005A391:
    if (cpu->ebx == 1u) { value_16 = value_12; goto label_0005A3BA; }
    cpu->ecx = cpu->ebx;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    if (cpu->eax != cpu->ecx) { value_13 = value_12; goto label_0005A3A2; }
    if (cpu->esi == cpu->ecx) { value_17 = value_12; goto label_0005A3C4; } value_13 = value_12;
label_0005A3A2:
    if (cpu->eax != cpu->ebx) { value_14 = value_13; goto label_0005A3AA; }
    if (cpu->esi == cpu->ebx) { value_17 = value_13; goto label_0005A3C4; } value_14 = value_13;
label_0005A3AA:
    if (cpu->eax != cpu->ecx) { value_15 = value_14; goto label_0005A3B2; }
    if (cpu->esi == cpu->ebx) { value_17 = value_14; goto label_0005A3C4; } value_15 = value_14;
label_0005A3B2:
    if (cpu->eax != cpu->ebx) { value_16 = value_15; goto label_0005A3BA; }
    if (cpu->esi == cpu->ecx) { value_17 = value_15; goto label_0005A3C4; } value_16 = value_15;
label_0005A3BA:
    cpu->ecx = cpu->edx + cpu->eax;
    cpu->ecx += cpu->ebp;
    *(uint8_t*)(cpu->ecx + cpu->edi + 3u) = 1u; value_17 = value_16;
label_0005A3C4:
    ++cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebx) { value_12 = value_17; goto label_0005A391; }
    ++cpu->esi;
    cpu->edx += 0x20u;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ebx) { value_11 = value_17; goto label_0005A38F; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u); value_18 = value_17;
label_0005A3D9:
    ++*(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->ebp < (int32_t)0x1Au) { value_10 = value_18; goto label_0005A37C; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->edx += 0x20u;
    cpu->eax += 0x118u;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->eax;
    if ((int32_t)cpu->edx < (int32_t)0x3A0u) { value_9 = value_18; goto label_0005A36C; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = 0x19u;
    cpu->edx += 0x1B71u; value_19 = value_18;
label_0005A417:
    cpu->eax = 0x19u;
    cpu->ecx = cpu->edx; value_20 = value_19;
label_0005A41E:
    if (*(uint8_t*)(cpu->ecx) != 0u) goto label_0005A46F;
    cpu->ecx -= 0x118u;
    if ((int32_t)(--cpu->eax) >= 0) goto label_0005A41E;
    --cpu->edx;
    if ((int32_t)(--cpu->esi) >= 0) { value_19 = value_20; goto label_0005A417; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->edx + (cpu->eax * 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xD0u);
    cpu->ecx += cpu->eax;
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0])) = cpu->edx; value_21 = value_20;
label_0005A44B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = 0u; value_22 = value_21;
label_0005A451:
    cpu->eax = 0u;
    cpu->ecx = cpu->esi; value_23 = value_22;
label_0005A455:
    if (*(uint8_t*)(cpu->ecx) != 0u) goto label_0005A486;
    ++cpu->eax;
    ++cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)0x1Au) goto label_0005A455;
    ++cpu->edx;
    cpu->esi += 0x118u;
    if ((int32_t)cpu->edx < (int32_t)0x1Au) { value_22 = value_23; goto label_0005A451; }
    value_24 = value_23; goto label_0005A490;
label_0005A46F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->esi;
    cpu->ecx = cpu->edx + (cpu->eax * 4u);
    cpu->ecx += cpu->eax;
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0])) = cpu->esi;
    value_21 = value_20; goto label_0005A44B;
label_0005A486:
    if ((int32_t)cpu->edx >= (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) { value_24 = value_23; goto label_0005A490; }
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx; value_24 = value_23;
label_0005A490:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    cpu->esi = 0x19u;
    cpu->eax += cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x118u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x58u);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x38u); value_25 = value_24;
label_0005A4A9:
    cpu->ecx = 0u;
    cpu->edx = cpu->eax; value_26 = value_25;
label_0005A4AD:
    if (*(uint8_t*)(cpu->edx) != 0u) goto label_0005A4C3;
    ++cpu->ecx;
    ++cpu->edx;
    if ((int32_t)cpu->ecx < (int32_t)0x1Au) goto label_0005A4AD;
    cpu->eax -= 0x118u;
    if ((int32_t)(--cpu->esi) >= 0) { value_25 = value_26; goto label_0005A4A9; }
    value_27 = value_26; goto label_0005A4CD;
label_0005A4C3:
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->esp + 0x3Cu)) { value_27 = value_26; goto label_0005A4CD; }
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi; value_27 = value_26;
label_0005A4CD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->eax -= cpu->edi;
    cpu->edx = cpu->edx + ((uintptr_t)((uint8_t*)&g_sfera_font_atlas_staging_runtime.pixels[0] + 2u));
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x20u; value_28 = value_27;
label_0005A4F4:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 8u; value_29 = value_28;
label_0005A504:
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFFFDu) == 0u) goto label_0005A517;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_30 = value_29; goto label_0005A52A;
label_0005A517:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 0xFFFFFFFFu) == 0u) goto label_0005A528;
    cpu->eax = cpu->ecx + 0xFu;
    value_30 = value_29; goto label_0005A52A;
label_0005A528:
    cpu->eax=0u; value_30 = value_29;
label_0005A52A:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi + 0xFFFFFFFEu) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    if (*(uint8_t*)(cpu->eax + cpu->ebx) == 0u) goto label_0005A554;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_31 = value_30; goto label_0005A566;
label_0005A554:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx) == 0u) goto label_0005A564;
    cpu->eax = cpu->ecx + 0xFu;
    value_31 = value_30; goto label_0005A566;
label_0005A564:
    cpu->eax=0u; value_31 = value_30;
label_0005A566:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi) = cpu->eax & 0xFFFFu;
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFFFFu) == 0u) goto label_0005A58B;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_32 = value_31; goto label_0005A59E;
label_0005A58B:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 1u) == 0u) goto label_0005A59C;
    cpu->eax = cpu->ecx + 0xFu;
    value_32 = value_31; goto label_0005A59E;
label_0005A59C:
    cpu->eax=0u; value_32 = value_31;
label_0005A59E:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi + 2u) = cpu->eax & 0xFFFFu;
    if (*(uint8_t*)(cpu->ebp) == 0u) goto label_0005A5C4;
    cpu->ecx = 0xFu;
    cpu->edx = cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    value_33 = value_32; goto label_0005A5D7;
label_0005A5C4:
    cpu->ecx = 0u;
    cpu->edx = 0u;
    cpu->esi = 0u;
    if (*(uint8_t*)(cpu->ebx + 2u) == 0u) goto label_0005A5D5;
    cpu->eax = cpu->ecx + 0xFu;
    value_33 = value_32; goto label_0005A5D7;
label_0005A5D5:
    cpu->eax=0u; value_33 = value_32;
label_0005A5D7:
    cpu->eax <<= 4u;
    cpu->eax|=cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax|=cpu->edx;
    cpu->eax <<= 4u;
    cpu->eax |= cpu->ecx;
    *(uint16_t*)(cpu->edi + 4u) = cpu->eax & 0xFFFFu;
    cpu->edi += 8u;
    cpu->ebp += 4u;
    cpu->ebx += 4u;
    if ((--*(uint32_t*)(cpu->esp + 0x1Cu)) != 0u) { value_29 = value_33; goto label_0005A504; }
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x200u) + (uint64_t)(0u);
    --*(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = cpu->ebp;
    cpu->ecx = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) != 0u) { value_28 = value_33; goto label_0005A4F4; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xC8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx -= cpu->edx;
    cpu->ecx += 3u;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x60u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax <<= 4u;
    cpu->ecx -= cpu->edx;
    x87_p0 = (x87_p0) * (value_33);
    cpu->ecx += 3u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    ++cpu->esi;
    *(float*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].u)) = x87_p0; 
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].defined)) = 1u;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u))));
    *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].texture_index)) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    x87_p0 = (x87_p0) * (value_33);
    *(float*)(cpu->eax + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].v)) = x87_p0; 
    if (cpu->esi != 8u) { value_34 = value_33; goto label_0005A746; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    ++cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if (cpu->eax != 8u) { value_34 = value_33; goto label_0005A746; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = g_sfera_font_atlas_staging_runtime.height;
    cpu->eax = cpu->edi;
    cpu->edi = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edi += cpu->eax;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->edi = (cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
     cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(D3DXCreateTexture(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device, *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), static_cast<D3DPOOL>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), SferaAbi::pointer<IDirect3DTexture9*>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u))), "D3DXCreateTexture")); cpu->esp += 32u;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4Cu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5A6DFu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->ebp = (uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0];
    if ((int32_t)g_sfera_font_atlas_staging_runtime.height <= (int32_t)cpu->ebx) goto label_0005A728;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->eax += cpu->eax;
label_0005A700:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x45A703u));
    cpu->edx = g_sfera_font_atlas_staging_runtime.width;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    cpu->eax = cpu->edx + cpu->edx;
    cpu->ecx >>= 1u;
    ++cpu->ebx;
    cpu->esp += 0xCu;
    cpu->ebp += cpu->eax;
    cpu->esi = cpu->esi + (cpu->ecx * 2u);
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_font_atlas_staging_runtime.height) goto label_0005A700;
label_0005A728:
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x50u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0x5A732u));
    x87_p0 = 0.00390625;
    ++*(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
     value_36 = x87_p0;  value_34 = value_36;
label_0005A746:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x5Cu);
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x4Cu)) goto label_0005A225;
     if (cpu->esi != 0u) goto label_0005A771;
    if (*(uint32_t*)(cpu->esp + 0x34u) == cpu->esi) goto label_0005A821;
label_0005A771:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_font_atlas_staging_runtime.height;
    cpu->ecx = g_sfera_font_atlas_staging_runtime.width;
    cpu->esi = cpu->edx + (cpu->edi * 4u);
    cpu->esi += cpu->edi;
    cpu->esi = (cpu->esi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au); lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->edx = SferaAbi::address(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(D3DXCreateTexture(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device, *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u), static_cast<D3DFORMAT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u)), static_cast<D3DPOOL>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)), SferaAbi::pointer<IDirect3DTexture9*>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 28u))), "D3DXCreateTexture")); cpu->esp += 32u;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x4Cu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5A7BDu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->ebx = (uintptr_t)&g_sfera_font_atlas_staging_runtime.pixels[0];
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (((uint32_t)(g_sfera_font_atlas_staging_runtime.height) == 0u) || ((int32_t)((uint32_t)(g_sfera_font_atlas_staging_runtime.height)) < (int32_t)(0u))) goto label_0005A810;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->eax += cpu->eax;
label_0005A7E0:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x45A7E3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    cpu->edx = g_sfera_font_atlas_staging_runtime.width;
    cpu->ecx >>= 1u;
    cpu->esi = cpu->esi + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->edx + cpu->edx;
    ++cpu->ecx;
    cpu->esp += 0xCu;
    cpu->ebx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_font_atlas_staging_runtime.height) goto label_0005A7E0;
label_0005A810:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x50u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5A81Eu));
    ++cpu->edi;
label_0005A821:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
label_0005A829:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx -= cpu->edx;
    cpu->ecx += 3u;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0])) = cpu->ecx;
    cpu->ecx = 0x14u;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0])) = cpu->edx;
    lift_push32(cpu, 0x8C8u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.resource_count[0])) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A868u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A868u));
    lift_push32(cpu, 0x8C9u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A879u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A879u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, 0x8CAu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A88Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A88Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, 0x8CBu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A89Fu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45A89Fu));
    if ((uint32_t)(g_sfera_font_runtime.glyphs[124].defined) != 0u) goto label_0005A8BE;
    cpu->ecx = (uintptr_t)"Symbol for CODE_FOR_UNDIFINED_SYMBOL is not found in font.txt";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A8B2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5A8B2u));
label_0005A8B2:
    cpu->ecx = (uintptr_t)"wrong format of font1.txt";
     lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A8BEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5A8BEu));
label_0005A8BE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0045A9C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000000u); lift_push32(cpu, 3u); lift_push32(cpu, 0u); lift_push32(cpu, 1u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, 0x80000000u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::CreateFileA), LIFT_CODE_TOKEN_VA(0x45A9D7u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0xFFFFFFFFu) goto label_0005A9F0;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3402: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A9F0u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x5A9F0u));
    label_0005A9F0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CreateFileMappingA), LIFT_CODE_TOKEN_VA(0x45A9FDu));
    cpu->ebx = native_function_address32(&::CloseHandle);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    if (cpu->esi != 0xFFFFFFFFu) goto label_0005AA1D;
    cpu->ecx = (uintptr_t)"CreateFileMapping failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AA1Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AA1Du));
    label_0005AA1D:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::MapViewOfFile), LIFT_CODE_TOKEN_VA(0x45AA26u));
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(*(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    if (cpu->edi != 0u) goto label_0005AA41;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"MapViewOfFile failed  ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AA41u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x5AA41u));
    label_0005AA41:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045AA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    cpu->eax = address32(::GetModuleHandleW(nullptr));
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.direct_input); lift_push32(cpu, address32(&IID_IDirectInput8A)); lift_push32(cpu, 0x800u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DirectInput8Create), LIFT_CODE_TOKEN_VA(0x45AA75u));
    if (cpu->eax == 0u) goto label_0005AA88;
    cpu->ecx = (uintptr_t)"DirectInputCreate failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AA88u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AA88u));
    label_0005AA88:
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_input_device_runtime.keyboard_device); lift_push32(cpu, address32(&GUID_SysKeyboard)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AA9Fu));
    if (cpu->eax == 0u) goto label_0005AAAF;
    cpu->ecx = (uintptr_t)"CreateDevice failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AAAFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AAAFu));
    label_0005AAAF:
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.mouse_device); lift_push32(cpu, address32(&GUID_SysMouse)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AAC6u));
    if (cpu->eax == 0u) goto label_0005AAD6;
    cpu->ecx = (uintptr_t)"CreateDevice failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AAD6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AAD6u));
    label_0005AAD6:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5AAEAu));
    if (cpu->eax == 0u) goto label_0005AAFA;
    cpu->ecx = (uintptr_t)"SetCooperativeLevel failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AAFAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AAFAu));
    label_0005AAFA:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 6u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5AB0Eu));
    if (cpu->eax == 0u) goto label_0005AB1E;
    cpu->ecx = (uintptr_t)"SetCooperativeLevel failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AB1Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AB1Eu));
    label_0005AB1E:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    lift_push32(cpu, address32(&c_dfDIKeyboard)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AB2Eu));
    if (cpu->eax == 0u) goto label_0005AB3E;
    cpu->ecx = (uintptr_t)"SetDataFormat failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AB3Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AB3Eu));
    label_0005AB3E:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    lift_push32(cpu, address32(&c_dfDIMouse)); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5AB4Eu));
    if (cpu->eax == 0u) goto label_0005AB5E;
    cpu->ecx = (uintptr_t)"SetDataFormat failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AB5Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AB5Eu));
    label_0005AB5E:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->edx = cpu->esp;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 4u) = 0x14u;
    *(uint32_t*)(cpu->esp + 8u) = 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 8u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x18u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5AB97u));
    if (cpu->eax == 0u) goto label_0005ABA7;
    cpu->ecx = (uintptr_t)"SetProperty failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ABA7u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5ABA7u));
    label_0005ABA7:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5ABB2u));
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5ABBFu));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045AC40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005AC54;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC54u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5AC54u));
    label_0005AC54:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005AC68;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC68u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5AC68u));
    label_0005AC68:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0005AC7D;
    cpu->ecx = (uintptr_t)"text_color: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC7Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AC7Du));
    label_0005AC7D:
    if ((int32_t)cpu->esi >= 0) goto label_0005AC8B;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC8Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5AC8Bu));
    label_0005AC8B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005AC9F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC9Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5AC9Fu));
    label_0005AC9F:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0x28u) = cpu->edi;
    if ((int32_t)cpu->esi >= 0) goto label_0005ACB9;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ACB9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5ACB9u));
    label_0005ACB9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005ACCD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ACCDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5ACCDu));
    label_0005ACCD:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 0xE80u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0045AFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AFBCu)); sfera_sub_00449180(cpu, LIFT_CODE_TOKEN_VA(0x45AFBCu));
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01) = 1u;
    cpu->edi = 0u;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    g_sfera_client_process_runtime.shutdown_requested = cpu->edi;
    label_0005AFD6:
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->ebx;
    cpu->edi += cpu->ecx;
    if ((cpu->edi == 0x2710u) || ((int32_t)(cpu->edi) < (int32_t)(0x2710u))) goto label_0005AFEE;
    cpu->edi = 0x2710u;
    label_0005AFEE:
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->ecx = cpu->edi + 0x1Au;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x4EC4EC4Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 4u;
    cpu->esi = cpu->edx;
    cpu->esi >>= 31u;
    cpu->esi += cpu->edx;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xFFFFFFCCu);
    cpu->edi += cpu->edx;
    cpu->ebp = 0u;
    if ((int32_t)cpu->esi <= 0) goto label_0005B02A;
    label_0005B015:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B01Cu)); sfera_sub_004496F0(cpu, LIFT_CODE_TOKEN_VA(0x45B01Cu));
    if (g_sfera_client_process_runtime.shutdown_requested != 0u) goto label_0005B054;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)cpu->esi) goto label_0005B015;
    label_0005B02A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B02Fu)); sfera_sub_004D0FC0(cpu, LIFT_CODE_TOKEN_VA(0x45B02Fu));
    if ((uint32_t)(g_sfera_render_lookup_runtime.initialized) == 1u) goto label_0005B042;
    lift_push32(cpu, 0xAu);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x45B03Au));
    goto label_0005AFD6;
    label_0005B042:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B047u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x45B047u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B04Cu)); sfera_sub_0042EB70(cpu, LIFT_CODE_TOKEN_VA(0x45B04Cu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x5B04Eu));
    label_0005B054:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}



__declspec(noinline) void sfera_sub_0045BC60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = 0u;
    g_sfera_window_runtime.runtime_debug_enabled = 1u;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.debug_config_enabled == cpu->esi) goto label_0005BCCE;
    cpu->ecx = (uintptr_t)"debug.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCA1u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x45BCA1u));
    cpu->edx = (uintptr_t)&g_sfera_window_runtime.runtime_debug_enabled;
    cpu->ecx = (uintptr_t)"RUNTIME";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCB0u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x45BCB0u));
    cpu->edx = (uintptr_t)&g_sfera_main_command_state_runtime.escape_without_query;
    cpu->ecx = (uintptr_t)"ESCNOQUERY";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCBFu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x45BCBFu));
    cpu->edx = (uintptr_t)&g_sfera_world_load_runtime.render_shadows;
    cpu->ecx = (uintptr_t)"RENDERSHADOW";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BCCEu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_RVA(0x5BCCEu));
    label_0005BCCE:
    g_sfera_world_objects.destroyAll();
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCD8u)); sfera_sub_004980F0(cpu, LIFT_CODE_TOKEN_VA(0x45BCD8u));
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCE2u)); sfera_sub_0048DA70(cpu, LIFT_CODE_TOKEN_VA(0x45BCE2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCE7u)); sfera_sub_00457490(cpu, LIFT_CODE_TOKEN_VA(0x45BCE7u));
    WorldDebugDraw::clear();
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)((uintptr_t)"cursor1");
    g_sfera_main_view_state_runtime.view_coefficients[5] = x87_v0;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"cursor1") + 4u);
    g_sfera_main_view_state_runtime.view_coefficients[4] = x87_v0;
    g_sfera_main_view_state_runtime.view_coefficients[3] = x87_v0;
    cpu->edi |= 0xFFFFFFFFu;
    g_sfera_main_view_state_runtime.view_coefficients[2] = x87_v0;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.default_cursor_token[0]) = cpu->eax;
    g_sfera_main_view_state_runtime.view_coefficients[1] = x87_v0;
    g_sfera_world_objects.controlled_object_handle = cpu->edi;
    g_sfera_main_view_state_runtime.view_coefficients[0] = x87_v0;
    g_sfera_recovered_static_runtime.interaction_enabled = cpu->esi;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.z.f32) = x87_v0;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.render_channel_mask) = 0xFFu;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.y.f32) = x87_v0;
    g_sfera_main_command_state_runtime.default_cursor_token[1] = cpu->ecx;
    *(float*)((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.primary_vector.x.f32) = x87_v0;
    g_sfera_window_runtime.active_window_index = cpu->edi;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.render_scale.x.f32) = x87_v0;
    g_sfera_texture_cache_runtime.render_gate = cpu->esi;
    x87_v1 = 1.0;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_02) = cpu->esi;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.render_scale.y.f32) = x87_v1; 
    cpu->eax = (uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count;
    *(float*)((uintptr_t)&g_sfera_scene_vector_runtime.render_scale.z.f32) = x87_v0; 
    g_sfera_graphics_runtime.base_render_factor = (double)0.05999999865889549f;
    *(float*)((uintptr_t)((uint8_t *)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0] + 0xF4u)) = (double)9.999999747378752e-05f;
    label_0005BD96:
    *(uint32_t*)(cpu->eax + 0xFFFFFFF4u) = cpu->esi;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->eax += 0x10u;
    if ((int32_t)(cpu->eax) < (int32_t)((uint32_t)((uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, use_count)))) goto label_0005BD96;
    cpu->edx = 0x15C2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDB4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45BDB4u));
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDBBu)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x45BDBBu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_0005BDD3;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDD1u)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x45BDD1u));
    goto label_0005BDD5;
    label_0005BDD3:
    cpu->eax = 0u;
    label_0005BDD5:
    lift_push32(cpu, (uintptr_t)"Landscape\\zoning.cfg");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    g_sfera_recovered_static_runtime.scene_state_08 = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDEAu)); sfera_sub_0049DF00(cpu, LIFT_CODE_TOKEN_VA(0x45BDEAu));
    cpu->edx = 0x15C4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDF9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45BDF9u));
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BE00u)); sfera_memory_allocate_zeroed(cpu, LIFT_CODE_TOKEN_VA(0x45BE00u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (cpu->eax == cpu->esi) goto label_0005BE1C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BE1Au)); sfera_sub_0042D0F0(cpu, LIFT_CODE_TOKEN_VA(0x45BE1Au));
    goto label_0005BE1E;
    label_0005BE1C:
    cpu->eax = 0u;
    label_0005BE1E:
    lift_push32(cpu, (uintptr_t)"Landscape\\zoningHaron.cfg");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    g_sfera_world_render_queue_runtime.entries[0] = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BE33u)); sfera_sub_0049DF00(cpu, LIFT_CODE_TOKEN_VA(0x45BE33u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0045C230(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17, value_18, value_19, value_20, value_21, value_22, value_23;
 bool sub_pred[1]; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5, x87_p6;
    bool lift_cmp[1];
    cpu->esp -= 0xB8u;
    x87_p0 = (double)0.1899999976158142f;
    lift_push32(cpu, cpu->ebp);
    x87_p1 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, cpu->esi);
    lift_cmp[0]=x87_p1>x87_p0;
    lift_push32(cpu, cpu->edi);
    x87_p0 = x87_p1; 
     value_1 = x87_p0; if (!lift_cmp[0]) goto label_0005C277;
    if (!((value_1)<(0.8299999833106995))) goto label_0005C279;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x96u;
    goto label_0005C286;
label_0005C277:
label_0005C279:
    cpu->ebp = 1u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0x40u;
label_0005C286:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x);
    cpu->esp -= 0xCu;
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x);
    cpu->eax = cpu->esp;
    x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0xB4u) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y);
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xB8u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z);
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    std::swap(x87_p3, x87_p2);
    *(float*)(cpu->esp + 0xBCu) = x87_p3; 
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[3].x);
    x87_p0 = x87_p3 - x87_p0; 
    std::swap(x87_p2, x87_p0);
    *(float*)(cpu->esp + 0xC0u) = x87_p2; 
    x87_p1 = (((double)g_sfera_view_geometry_runtime.reference_points[3].y)) - (x87_p1);
    *(float*)(cpu->esp + 0xC4u) = x87_p1; 
    x87_p0 = (((double)g_sfera_view_geometry_runtime.reference_points[3].z)) - (x87_p0);
    *(float*)(cpu->esp + 0xC8u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0xC8u); x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->esp + 0xB8u); x87_p3 = x87_p2;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0xC4u); x87_p4 = x87_p3;
    x87_p5 = (double)*(float*)(cpu->esp + 0xBCu); x87_p6 = x87_p5;
    x87_p4 = x87_p4 * x87_p6; 
    std::swap(x87_p5, x87_p1);
    x87_p4 = x87_p5 - x87_p4; 
    *(float*)(cpu->esp + 0x1Cu) = x87_p4; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p4 = (double)*(float*)(cpu->esp + 0xC0u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_p5 = x87_p4;
    x87_p1 = x87_p1 * x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0xB4u); x87_p6 = x87_p5;
    x87_p0 = x87_p0 * x87_p6; 
    std::swap(x87_p5, x87_p1);
    x87_p0 = x87_p5 - x87_p0; 
    std::swap(x87_p4, x87_p0);
    *(float*)(cpu->esp + 0x20u) = x87_p4; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_p1 = x87_p1 * x87_p3; 
    cpu->edx = 1u;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p1 - x87_p0; 
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x48u;
    *SferaAbi::pointer<SferaVec3F>(cpu->ecx) = SferaVec3F{*SferaAbi::pointer<const float>(cpu->esp), *SferaAbi::pointer<const float>(cpu->esp + 4u), *SferaAbi::pointer<const float>(cpu->esp + 8u)}.normalized(static_cast<std::int32_t>(cpu->edx)); cpu->eax = cpu->ecx; cpu->edx = sfera_f32_bits(SferaAbi::pointer<SferaVec3F>(cpu->ecx)->z); cpu->esp += 12u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0xA8u) = cpu->edx;
    x87_p0 = (double)*(float*)(cpu->esp + 0xA8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0xACu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(float*)(cpu->esp + 0x3Cu) = x87_p0;
    x87_p1 = (double)*(float*)(cpu->esp + 0xACu);
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->edx;
    *(float*)(cpu->esp + 0x40u) = x87_p1;
    x87_p2 = (double)*(float*)(cpu->esp + 0xB0u);
    *(float*)(cpu->esp + 0x44u) = x87_p2;
    std::swap(x87_p2, x87_p0);
    x87_p2 = -x87_p2;
    x87_p2 = (x87_p2) * (((double)g_sfera_view_geometry_runtime.reference_points[1].x));
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p1 = x87_p2 - x87_p1; 
    g_sfera_recovered_static_runtime.scene_state_09 = 0u;
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p1 - x87_p0; 
    *(float*)(cpu->esp + 0x48u) = x87_p0; 
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x))) + (((double)g_sfera_view_spatial_runtime.position_offset.x.f32)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y);
    *(uint32_t*)(cpu->esp + 0xA8u) = cpu->eax;
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.position_offset.y.f32));
    cpu->eax = cpu->esp + 0xB4u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z);
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->ecx;
    x87_p0 = (x87_p0) + (((double)g_sfera_view_spatial_runtime.position_offset.z.f32));
    cpu->ecx = cpu->esp + 0xACu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x);
    *(float*)(cpu->esp + 0x24u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->edx;
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<const SferaPlaneF>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))->intersectLine(*SferaAbi::pointer<const SferaVec3F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), *SferaAbi::pointer<const SferaVec3F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<SferaVec3F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u)))); cpu->esp += 16u;
    if (cpu->eax != 1u) goto label_0005CB15;
    x87_p0 = (double)*(float*)(cpu->esp + 0xB4u);
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].x); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0xB8u);
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].y); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x14u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xBCu);
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[0].z); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    std::swap(x87_p3, x87_p2);
    *(float*)(cpu->esp + 0x18u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p4 = 0.8999999761581421;
    x87_p3 = (x87_p3) * (x87_p4);
    std::swap(x87_p4, x87_p3);
    *(float*)(cpu->esp + 0x2Cu) = x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p4 = (x87_p4) * (x87_p3);
    *(float*)(cpu->esp + 0x30u) = x87_p4; 
    x87_p3 = (x87_p3) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x34u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p0 = x87_p0 + x87_p3; 
    std::swap(x87_p2, x87_p0);
    *(float*)(cpu->esp + 0x10u) = x87_p2; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->eax;
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->esp + 0x30u)));
    cpu->eax = cpu->esp + 0xA8u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->ecx;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x38u)));
    cpu->ecx = cpu->esp + 0xB8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_collision_scratch_runtime.view_transform[0];
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0xC4u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C520u)); sfera_sub_0042F7D0(cpu, LIFT_CODE_TOKEN_VA(0x45C520u));
    if (cpu->eax == 0u) goto label_0005CB15;
    sub_pred[0] = (uint32_t)(g_sfera_main_render_runtime.secondary_render_pass) == 0u;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x20u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xB4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xBCu);
    x87_p0 = (x87_p0) / (640.0);
    g_sfera_recovered_static_runtime.flare_clip_vector.x.u32 = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xA8u);
    g_sfera_recovered_static_runtime.flare_clip_vector.y.u32 = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xACu);
    g_sfera_recovered_static_runtime.flare_clip_vector.z.u32 = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xB0u);
    g_sfera_flare_projection.x.u32 = cpu->edx;
    g_sfera_flare_projection.y.u32 = cpu->eax;
    g_sfera_flare_projection.z.u32 = cpu->ecx;
     value_2 = x87_p0; if (sub_pred[0]) goto label_0005C59B;
    value_3 = (value_2) * (256.0);
    *(float*)(cpu->esp + 0x20u) = value_3; 
    value_4 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x24u) = value_4;
    value_0 = value_4; goto label_0005C5C1;
label_0005C59B:
    value_5 = (value_2) * ((double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    *(float*)(cpu->esp + 0x24u) = value_5;
    *(float*)(cpu->esp + 0xCu) = (double)(((int32_t)(g_sfera_graphics_runtime.display_height)));
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu); x87_p1 = x87_p0;
    value_6 = value_5 / x87_p1; 
    value_7 = value_6 * x87_p0; 
    *(float*)(cpu->esp + 0x20u) = value_7; 
    value_8 = (double)*(float*)(cpu->esp + 0x20u); value_0 = value_8;
label_0005C5C1:
    x87_p0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->edi = 0u;
    x87_p1 = x87_p0;
    x87_p1 = -x87_p1;
    x87_p2 = 0.5;
    x87_p1 = (x87_p1) * (x87_p2);
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xCu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x) = x87_p2;
    x87_p3 = value_0;
    x87_p3 = -x87_p3;
    x87_p3 = (x87_p3) * (x87_p1);
    *(float*)(cpu->esp + 0xCu) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y) = x87_p3;
    x87_p4 = 0.0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u) = x87_p4;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v) = x87_p4;
    std::swap(x87_p4, x87_p0);
    x87_p4 = (x87_p4) * (x87_p1);
    *(float*)(cpu->esp + 0xCu) = x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x) = x87_p4;
    std::swap(x87_p4, x87_p3);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y) = x87_p4; 
    x87_p4 = 1.0;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u) = x87_p4;
    std::swap(x87_p4, x87_p0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v) = x87_p4;
    std::swap(x87_p4, x87_p3);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x) = x87_p4; 
    value_22 = x87_p3; x87_p3 = value_0;
    x87_p1 = x87_p1 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0xCu) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y) = x87_p2;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y) = x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v) = x87_p1;
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v) = x87_p1; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x) = x87_p0; 
    *(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u) = value_22; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x);
    *(float*)(cpu->esp + 0x38u) = (double)*(float*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y);
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x1Cu) = (-((double)*(float*)(cpu->esp + 0xC8u)));
    value_9 = (double)*(float*)(cpu->esp + 0x1Cu);
    value_10 = std::cos(value_9);
    *(float*)(cpu->esp + 0xCu) = value_10; 
    *(float*)(cpu->esp + 0x4Cu) = (double)*(float*)(cpu->esp + 0xCu);
    value_11 = (double)*(float*)(cpu->esp + 0x1Cu);
    value_12 = std::sin(value_11);
    *(float*)(cpu->esp + 0xCu) = value_12; 
    value_13 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->esi = (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x;
    *(float*)(cpu->esp + 0xCu) = value_13; 
     goto label_0005C6D5;
label_0005C6D3:
label_0005C6D5:
    x87_p0 = (double)*(float*)(cpu->esp + 0x4Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_p2 = (double)*(float*)(cpu->esi);
    x87_p2 = (x87_p2) * (x87_p0);
    x87_p3 = (double)*(float*)(cpu->esi + 4u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p2 = x87_p2 - x87_p3; 
    *(float*)(cpu->esp + 0x1Cu) = x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->esi)));
    x87_p2 = (double)*(float*)(cpu->esi + 4u);
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esi + 4u) = x87_p0; 
    *(float*)(cpu->esi) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi))) + (((double)*(float*)(cpu->esp + 0xA8u))));
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x98u) = x87_p0;
    *(float*)(cpu->esi) = x87_p0;
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esi + 4u))) + (((double)*(float*)(cpu->esp + 0xACu))));
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x1Cu) = x87_p1;
    *(float*)(cpu->esp + 0x10u) = x87_p1;
    *(float*)(cpu->esi + 4u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x98u);
     value_14 = x87_p1; value_15 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x38u))>(value_14))) goto label_0005C74D;
    *(float*)(cpu->esp + 0x38u) = value_14;
label_0005C74D:
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
     value_16 = x87_p0; if (!((value_16)<(value_14))) goto label_0005C760;
    *(float*)(cpu->esp + 0x28u) = value_15; 
     goto label_0005C762;
label_0005C760:
label_0005C762:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
     value_17 = x87_p0; if (!(((double)*(float*)(cpu->esp + 0x24u))>(value_17))) goto label_0005C777;
    *(float*)(cpu->esp + 0x24u) = value_17;
label_0005C777:
    x87_p0 = (double)*(float*)(cpu->esp + 0x20u);
     value_18 = x87_p0; if (!((value_18)<(value_17))) goto label_0005C78C;
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 0x10u);
label_0005C78C:
    if (cpu->ebp != 0u) goto label_0005C79C;
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ecx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5C79Cu)); sfera_sub_004501C0(cpu, LIFT_CODE_TOKEN_RVA(0x5C79Cu));
label_0005C79C:
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].x);
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].x); x87_p2 = x87_p1;
    x87_p0 = x87_p0 - x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x2Cu) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].y);
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].y); x87_p3 = x87_p2;
    x87_p1 = x87_p1 - x87_p3; 
    std::swap(x87_p2, x87_p1);
    *(float*)(cpu->esp + 0x30u) = x87_p2; 
    x87_p2 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[2].z);
    x87_p3 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[1].z); x87_p4 = x87_p3;
    x87_p2 = x87_p2 - x87_p4; 
    std::swap(x87_p3, x87_p2);
    *(float*)(cpu->esp + 0x34u) = x87_p3; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esi);
    x87_p3 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_p4 = (double)*(float*)(cpu->esp + 0x10u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    std::swap(x87_p4, x87_p3);
    *(float*)(cpu->esp + 0x68u) = x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0x30u);
    x87_p4 = (x87_p4) * (x87_p3);
    *(float*)(cpu->esp + 0x6Cu) = x87_p4; 
    x87_p3 = (x87_p3) * (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x70u) = x87_p3; 
    x87_p3 = (double)(((int32_t)(g_sfera_graphics_runtime.display_width)));
    x87_p4 = 1.0;
    x87_p5 = x87_p4;
    x87_p3 = x87_p5 / x87_p3; 
    std::swap(x87_p4, x87_p3);
    *(float*)(cpu->esp + 0x10u) = x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0x10u); x87_p5 = x87_p4;
    x87_p5 = (x87_p5) * (((double)*(float*)(cpu->esp + 0x68u)));
    *(float*)(cpu->esp + 0x74u) = x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0x6Cu);
    x87_p5 = (x87_p5) * (x87_p4);
    *(float*)(cpu->esp + 0x78u) = x87_p5; 
    x87_p4 = (x87_p4) * (((double)*(float*)(cpu->esp + 0x70u)));
    *(float*)(cpu->esp + 0x7Cu) = x87_p4; 
    x87_p4 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].x);
    x87_p4 = (x87_p4) - (x87_p0);
    *(float*)(cpu->esp + 0x50u) = x87_p4; 
    x87_p4 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].y);
    x87_p4 = (x87_p4) - (x87_p1);
    *(float*)(cpu->esp + 0x54u) = x87_p4; 
    x87_p4 = (double)*(float*)((uintptr_t)&g_sfera_view_geometry_runtime.reference_points[4].z);
    x87_p4 = (x87_p4) - (x87_p2);
    *(float*)(cpu->esp + 0x58u) = x87_p4; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esi + 4u);
    x87_p4 = (double)*(float*)(cpu->esp + 0x50u);
    x87_p5 = (double)*(float*)(cpu->esp + 0x10u); x87_p6 = x87_p5;
    x87_p4 = x87_p4 * x87_p6; 
    std::swap(x87_p5, x87_p4);
    *(float*)(cpu->esp + 0x80u) = x87_p5; 
    x87_p5 = (double)*(float*)(cpu->esp + 0x54u);
    x87_p5 = (x87_p5) * (x87_p4);
    *(float*)(cpu->esp + 0x84u) = x87_p5; 
    x87_p4 = (x87_p4) * (((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x88u) = x87_p4; 
    x87_p3 = (x87_p3) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    *(float*)(cpu->esp + 0x10u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->esp + 0x10u); x87_p4 = x87_p3;
    x87_p4 = (x87_p4) * (((double)*(float*)(cpu->esp + 0x80u)));
    *(float*)(cpu->esp + 0x5Cu) = x87_p4; 
    x87_p4 = (double)*(float*)(cpu->esp + 0x84u);
    x87_p4 = (x87_p4) * (x87_p3);
    *(float*)(cpu->esp + 0x60u) = x87_p4; 
    x87_p3 = (x87_p3) * (((double)*(float*)(cpu->esp + 0x88u)));
    *(float*)(cpu->esp + 0x64u) = x87_p3; 
    *(float*)(cpu->esp + 0x8Cu) = ((((double)*(float*)(cpu->esp + 0x5Cu))) + (((double)*(float*)(cpu->esp + 0x74u))));
    cpu->esp -= 0xCu;
    x87_p3 = (double)*(float*)(cpu->esp + 0x6Cu);
    cpu->eax = cpu->esp;
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->esp + 0x84u)));
    *(float*)(cpu->esp + 0x9Cu) = x87_p3; 
    *(float*)(cpu->esp + 0xA0u) = ((((double)*(float*)(cpu->esp + 0x70u))) + (((double)*(float*)(cpu->esp + 0x88u))));
    x87_p3 = (double)*(float*)(cpu->esp + 0x98u);
    x87_p0 = x87_p0 + x87_p3; 
    std::swap(x87_p2, x87_p0);
    *(float*)(cpu->esp + 0xA8u) = x87_p2; 
    x87_p1 = (x87_p1) + (((double)*(float*)(cpu->esp + 0x9Cu)));
    *(float*)(cpu->esp + 0xACu) = x87_p1; 
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0xA0u)));
    *(float*)(cpu->esp + 0xB0u) = x87_p0; 
    *(float*)(cpu->esp + 0x48u) = ((((double)*(float*)(cpu->esp + 0xA8u))) - (((double)g_sfera_view_geometry_runtime.reference_points[0].x)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    x87_p0 = (double)*(float*)(cpu->esp + 0xACu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    x87_p0 = (x87_p0) - (((double)g_sfera_view_geometry_runtime.reference_points[0].y));
    *(float*)(cpu->esp + 0x4Cu) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0xB0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    x87_p0 = (x87_p0) - (((double)g_sfera_view_geometry_runtime.reference_points[0].z));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C979u)); sfera_sub_00457840(cpu, LIFT_CODE_TOKEN_VA(0x45C979u));
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].x);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.x);
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.position_offset.y);
    x87_p0 = std::atan2(x87_p0, x87_p1); 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    x87_p0 = fabs(x87_p0);
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p0 = (x87_p0) / (3.1415929794311523);
    x87_p1 = 1.0;
    x87_p0 = x87_p1 - x87_p0; 
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C9C1u)); value_23 = sfera_sub_0044E400(cpu, LIFT_CODE_TOKEN_VA(0x45C9C1u));
    value_19 = (value_23) * (255.0);
    cpu->ecx |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x14u) = 0u;
    *(float*)(cpu->esp + 0x10u) = value_19; 
    value_20 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esi += 0x20u;
    ++cpu->edi;
    *(uint64_t*)(cpu->esp + 0x10u) = static_cast<int64_t>(std::trunc(value_20));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx -= cpu->eax;
    cpu->ecx <<= 24u;
    cpu->ecx |= 0xFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xFFFFFFF0u) = cpu->ecx;
    value_21 = 0.0;
    *(float*)(cpu->esi + 0xFFFFFFE8u) = value_21;
    *(float*)(cpu->esi + 0xFFFFFFECu) = (double)(1.0);
    if ((int32_t)cpu->esi < (int32_t)((uintptr_t)&g_sfera_scene_render_runtime.textured_quad[4])) goto label_0005C6D3;
    { const double lift_right=(double)*(float*)(cpu->esp + 0x38u); const double lift_left=(double)(((int32_t)(g_sfera_graphics_runtime.display_width))); if (!(lift_left>lift_right)) goto label_0005CB13; }
    if (!((value_21)<(((double)*(float*)(cpu->esp + 0x28u))))) goto label_0005CB13;
    { const double lift_right=(double)*(float*)(cpu->esp + 0x24u); const double lift_left=(double)(((int32_t)(g_sfera_graphics_runtime.display_height))); if (!(lift_left>lift_right)) goto label_0005CB13; }
    if (!((value_21)<(((double)*(float*)(cpu->esp + 0x20u))))) goto label_0005CB15;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    if (cpu->ebp != 0u) goto label_0005CAAF;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"sun";
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"sun";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    g_sfera_recovered_static_runtime.scene_state_09 = 1u;
    goto label_0005CADA;
label_0005CAAF:
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->setAlphaBlending(static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), static_cast<D3DBLEND>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"moon";
    cpu->eax = SferaAbi::address(g_sfera_textures.resource(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetTexture(*SferaAbi::pointer<const std::uint32_t>(cpu->esp), SferaAbi::pointer<IDirect3DBaseTexture9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))), "SetTexture")); cpu->esp += 8u;
    cpu->ecx = (uintptr_t)"moon";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_textures.hasAlpha(static_cast<std::uint32_t>(g_sfera_textures.find(SferaAbi::pointer<const char>(cpu->ecx)))));
label_0005CADA:
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x1C4u);
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetFVF(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), "SetFVF")); cpu->esp += 4u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    SferaAbi::pointer<CD3D9Device>(cpu->ecx)->drawVertices(static_cast<D3DPRIMITIVETYPE>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u), SferaAbi::pointer<const void>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u), SferaAbi::pointer<const std::uint16_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 16u)), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 20u), *SferaAbi::pointer<const std::uint32_t>(cpu->esp + 24u)); cpu->esp += 28u;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE));
    goto label_0005CB15;
label_0005CB13:
label_0005CB15:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xB8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045CB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if (cpu->eax != 0u) goto label_0005CB65;
    label_0005CB4D:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0005CB65:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0005CB4D;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005CB86;
    cpu->eax = (uintptr_t)"<none>";
    label_0005CB86:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CB9Au));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CBACu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45CBACu));
    cpu->eip = 0x45CBACu; ::DebugBreak(); return;
}

__declspec(noinline) void sfera_sub_0045CC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005CD20;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CC63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CC63u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CC63u));
    label_0005CC63:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005CD20;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CC86;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CC86u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CC86u));
    label_0005CC86:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->edx + 0x138u) == 0u) goto label_0005CD4B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CCB0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CCB0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CCB0u));
    label_0005CCB0:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005CCD8;
    label_0005CCBC:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005CCD8:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005CCBC;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005CCF9;
    cpu->eax = (uintptr_t)"<none>";
    label_0005CCF9:
    lift_push32(cpu, 0x2475u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CD0Eu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CD20u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5CD20u));
    label_0005CD20:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005CD30:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005CD30;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetProcess: wrong handle"),25u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CD4Au)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45CD4Au));
    cpu->edi = lift_pop32(cpu);
    label_0005CD4B:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045CD70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005CD98;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CD98u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5CD98u));
    label_0005CD98:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CDAC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CDACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CDACu));
    label_0005CDAC:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_0005CDE5;
    label_0005CDB8:
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x144u) >= (int32_t)0u) goto label_0005CE2D;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CDCEu)); sfera_sub_0041B560(cpu, LIFT_CODE_TOKEN_VA(0x45CDCEu));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005CDE5:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_0005CDB8;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005CE06;
    cpu->eax = (uintptr_t)"<none>";
    label_0005CE06:
    lift_push32(cpu, 0x247Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CE1Bu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CE2Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5CE2Du));
    label_0005CE2D:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0005CEB8;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CE57;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CE57u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CE57u));
    label_0005CE57:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) == 0u) goto label_0005CEB8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 0x50u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005CE7B;
    cpu->ecx = (uintptr_t)"GetSubAnimLen: model has no animation";
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CE79u)); sfera_sub_0044F4C0(cpu, LIFT_CODE_TOKEN_VA(0x45CE79u));
    goto label_0005CED9;
    label_0005CE7B:
    if ((int32_t)cpu->ebp >= 0) goto label_0005CE92;
    cpu->ecx = (uintptr_t)"GetSubAnimLen: negative subanimation number";
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CE90u)); sfera_sub_0044F4C0(cpu, LIFT_CODE_TOKEN_VA(0x45CE90u));
    goto label_0005CED9;
    label_0005CE92:
    cpu->edx = cpu->eax & 0xFFu;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_0005CEDE;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x5Cu);
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->ebp * 2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005CEB8:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005CEC5:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005CEC5;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetSubAnimLen: wrong handle"),28u); cpu->ecx = 0u;
    label_0005CED9:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CEDEu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x5CEDEu));
    label_0005CEDE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045CF00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005CFCB;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CF33;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CF33u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CF33u));
    label_0005CF33:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005CFCB;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005CF56;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CF56u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5CF56u));
    label_0005CF56:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005CFFD;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005CFAF;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005CF88;
    cpu->eax = (uintptr_t)"<none>";
    label_0005CF88:
    lift_push32(cpu, 0x248Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45CF9Du));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CFAFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5CFAFu));
    label_0005CFAF:
    cpu->eax = cpu->esi + 0x170u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005CFCB:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005CFE0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005CFE0;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetAnimation: wrong handle"),27u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CFFCu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45CFFCu));
    cpu->edi = lift_pop32(cpu);
    label_0005CFFD:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045D020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005D0EB;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D053;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D053u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D053u));
    label_0005D053:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005D0EB;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D076;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D076u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D076u));
    label_0005D076:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005D11D;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005D0CF;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005D0A8;
    cpu->eax = (uintptr_t)"<none>";
    label_0005D0A8:
    lift_push32(cpu, 0x2493u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D0BDu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D0CFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5D0CFu));
    label_0005D0CF:
    cpu->eax = cpu->esi + 0x174u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005D0EB:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005D100:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005D100;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetFrame: wrong handle"),23u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D11Cu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45D11Cu));
    cpu->edi = lift_pop32(cpu);
    label_0005D11D:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045D140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005D20B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D173;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D173u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D173u));
    label_0005D173:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005D20B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D196;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D196u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D196u));
    label_0005D196:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005D25A;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005D1EF;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005D1C8;
    cpu->eax = (uintptr_t)"<none>";
    label_0005D1C8:
    lift_push32(cpu, 0x249Cu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D1DDu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D1EFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5D1EFu));
    label_0005D1EF:
    cpu->eax = cpu->esi + 0x178u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005D20B:
    cpu->eax = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->eax;
    label_0005D218:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0005D218;
    cpu->ecx = *(uint32_t*)((uintptr_t)"GetInterp: wrong handle");
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetInterp: wrong handle") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetInterp: wrong handle") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetInterp: wrong handle") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetInterp: wrong handle") + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetInterp: wrong handle") + 0x14u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D25Au)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x5D25Au));
    label_0005D25A:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045D280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005D34B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D2B3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D2B3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D2B3u));
    label_0005D2B3:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005D34B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D2D6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D2D6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D2D6u));
    label_0005D2D6:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005D39A;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005D32F;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005D308;
    cpu->eax = (uintptr_t)"<none>";
    label_0005D308:
    lift_push32(cpu, 0x24A5u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D31Du));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D32Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5D32Fu));
    label_0005D32F:
    cpu->eax = cpu->esi + 0x17Cu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005D34B:
    cpu->eax = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->eax;
    label_0005D358:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0005D358;
    cpu->ecx = *(uint32_t*)((uintptr_t)"GetFrame2: wrong handle");
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetFrame2: wrong handle") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetFrame2: wrong handle") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetFrame2: wrong handle") + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"GetFrame2: wrong handle") + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uintptr_t)"GetFrame2: wrong handle") + 0x14u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D39Au)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x5D39Au));
    label_0005D39A:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045D3C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_0005D48B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D3F3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D3F3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D3F3u));
    label_0005D3F3:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005D48B;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D416;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D416u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D416u));
    label_0005D416:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005D4BA;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005D46F;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005D448;
    cpu->eax = (uintptr_t)"<none>";
    label_0005D448:
    lift_push32(cpu, 0x24AEu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D45Du));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D46Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5D46Fu));
    label_0005D46F:
    cpu->eax = cpu->esi + 0x180u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005D48B:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005D4A0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005D4A0;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetAnimation2: wrong handle"),28u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D4B9u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45D4B9u));
    cpu->edi = lift_pop32(cpu);
    label_0005D4BA:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045D4E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x418u;
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0005D512;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D512u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5D512u));
    label_0005D512:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005D526;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D526u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D526u));
    label_0005D526:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (cpu->ebx == 0u) goto label_0005D57E;
    if (*(uint8_t*)(cpu->ebx + 0x138u) != 0u) goto label_0005D588;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0005D557;
    cpu->eax = (uintptr_t)"<none>";
    label_0005D557:
    lift_push32(cpu, 0x29F1u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45D56Cu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D57Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5D57Eu));
    label_0005D57E:
    cpu->ecx = (uintptr_t)"CalcCharacterNeck: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D588u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5D588u));
    label_0005D588:
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x144u) >= (int32_t)0u) goto label_0005D5B8;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D59Eu)); sfera_sub_0041C5B0(cpu, LIFT_CODE_TOKEN_VA(0x45D59Eu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005D5B8:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    g_sfera_world_render_runtime.active_model = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x170u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x174u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)cpu->edx < 0) goto label_0005D5F7;
    cpu->esi = *(uint8_t*)(cpu->ecx + 0x50u);
    if ((int32_t)cpu->edx < (int32_t)cpu->esi) goto label_0005D62C;
    label_0005D5F7:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005D604:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005D604;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"CalcCharacterNeck: wrong animation"),35u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D620u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45D620u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = 0u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_0005D62C:
    lift_push32(cpu, cpu->ebp);
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)(cpu->edx) < (int32_t)(2u)) goto label_0005D661;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->ecx = cpu->edx + 0xFFFFFFFEu;
    cpu->ecx >>= 1u;
    ++cpu->ecx;
    cpu->ebp = cpu->ecx + cpu->ecx;
    label_0005D644:
    cpu->ebx = *(uint16_t*)(cpu->eax);
    cpu->esi += cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->eax + 2u);
    cpu->edi += cpu->ebx;
    cpu->eax += 4u;
    if ((--cpu->ecx) != 0u) goto label_0005D644;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0005D661:
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_0005D674;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->ecx = *(uint16_t*)(cpu->ecx + (cpu->ebp * 2u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0005D674:
    cpu->edi += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->ebp = 0u;
    if ((int32_t)cpu->eax < (int32_t)cpu->ebp) goto label_0005D68B;
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->edx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0005D6BA;
    label_0005D68B:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005D698:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005D698;
    cpu->esi = (uintptr_t)"CalcCharacterNeck: wrong frame";
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),31u); cpu->esi += 31u; cpu->edi += 31u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D6B4u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45D6B4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = 0u;
    label_0005D6BA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)9.999999747378752e-06f;
    cpu->edx += cpu->eax;
    g_sfera_client_main_scalar_runtime.state_06 = cpu->edx;
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = cpu->ebp;
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->ebx + 0x178u));  if (!(lift_left<lift_right)) goto label_0005D7E4; }
    (*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_enabled) = 1u;
    *(float*)((uintptr_t)&g_sfera_sky_runtime.horizon_scale.f32) = (double)*(float*)(cpu->ebx + 0x178u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x180u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x17Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)cpu->edx < (int32_t)cpu->ebp) goto label_0005D719;
    cpu->esi = *(uint8_t*)(cpu->ecx + 0x50u);
    if ((int32_t)cpu->edx < (int32_t)cpu->esi) goto label_0005D74C;
    label_0005D719:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005D726:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005D726;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"CalcCharacterNeck: wrong animation 2"),37u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D740u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45D740u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = 0u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_0005D74C:
    cpu->esi = 0u;
    cpu->edi = 0u;
    cpu->ebp = 0u;
    if ((int32_t)(cpu->edx) < (int32_t)(2u)) goto label_0005D784;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->ecx = cpu->edx + 0xFFFFFFFEu;
    cpu->ecx >>= 1u;
    ++cpu->ecx;
    cpu->ebp = cpu->ecx + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    label_0005D767:
    cpu->ebp = *(uint16_t*)(cpu->eax);
    cpu->esi += cpu->ebp;
    cpu->ebp = *(uint16_t*)(cpu->eax + 2u);
    cpu->edi += cpu->ebp;
    cpu->eax += 4u;
    if ((--cpu->ecx) != 0u) goto label_0005D767;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    label_0005D784:
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edx) goto label_0005D795;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->ebp = *(uint16_t*)(cpu->eax + (cpu->ebp * 2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_0005D799;
    label_0005D795:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    label_0005D799:
    cpu->edi += cpu->esi;
    cpu->ebp += cpu->edi;
    if ((int32_t)cpu->eax < 0) goto label_0005D7AC;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->edx * 2u));
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0005D7DC;
    label_0005D7AC:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005D7C0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005D7C0;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"CalcCharacterNeck: wrong frame 2"),33u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D7DAu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45D7DAu));
    cpu->eax = 0u;
    label_0005D7DC:
    cpu->ebp += cpu->eax;
    g_sfera_render_sample_runtime.material_base = cpu->ebp;
    label_0005D7E4:
    lift_push32(cpu, (uintptr_t)&g_sfera_character_frame_matrix.m[0][0]);
    cpu->edx = cpu->ebx + 0x14u;
    cpu->ecx = cpu->ebx + 8u;
    { auto* destination = SferaAbi::pointer<SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)); *destination = SferaMatrix4x4F::fromEuler(*SferaAbi::pointer<const SferaVec3F>(cpu->ecx), *SferaAbi::pointer<const SferaVec3F>(cpu->edx)); cpu->eax = SferaAbi::address(destination); }; cpu->esp += 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint8_t*)(cpu->eax + 0x40u);
    cpu->ecx = (uintptr_t)&g_sfera_character_frame_matrix.m[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D806u)); sfera_sub_00454FF0(cpu, LIFT_CODE_TOKEN_VA(0x45D806u));
    cpu->ecx = g_sfera_scene_vector_runtime.frame_102_position.x.u32;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = g_sfera_scene_vector_runtime.frame_102_position.y.u32;
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = g_sfera_scene_vector_runtime.frame_102_position.z.u32;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x418u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0045DC60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005DC74;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DC74u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5DC74u));
    label_0005DC74:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005DC88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DC88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5DC88u));
    label_0005DC88:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = cpu->esi + 0x44u;
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->ecx) == 0xFFFFFFFFu) goto label_0005DCB0;
    label_0005DCA0:
    ++cpu->eax;
    cpu->ecx += 4u;
    if (cpu->eax == 0x1B58u) goto label_0005DCBA;
    if (*(uint32_t*)(cpu->ecx) != 0xFFFFFFFFu) goto label_0005DCA0;
    label_0005DCB0:
    *(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 0x44u) = cpu->edi;
    ++*(uint32_t*)(cpu->esi + 0x40u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005DCBA:
    cpu->ecx = (uintptr_t)"MNO_CONTROLS_IN_WINDOW exceed";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DCC4u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45DCC4u));
    cpu->eip = 0x45DCC4u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0045DCD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0xC8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi < 0) goto label_0005E512;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005DD04;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DD04u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5DD04u));
    label_0005DD04:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005E512;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005DD27;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DD27u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5DD27u));
    label_0005DD27:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005E0F4;
    cpu->edi = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->edi == 0u) goto label_0005E0F4;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(float*)(cpu->esp + 0xB4u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    *(float*)(cpu->esp + 0xB8u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x28u);
    cpu->eax -= cpu->ecx;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->esi -= cpu->edx;
    x87_v2 = 0.00390625;
    ++cpu->esi;
    cpu->ebx = cpu->esp + 0xB4u;
    x87_v1 = (x87_v1) * (x87_v2);
    lift_push32(cpu, cpu->ebx);
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x18u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(float*)(cpu->esp + 0xC4u) = x87_v2;
    *(float*)(cpu->esp + 0xCCu) = x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xC8u) = x87_v1;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0xD0u) = x87_v1;
    *(float*)(cpu->esp + 0xD8u) = x87_v1; 
    *(float*)(cpu->esp + 0xD4u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"winfon"); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DDDAu)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45DDDAu));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(float*)(cpu->esp + 0xB4u) = x87_v0;
    x87_v1 = (double)0.0234375f;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(float*)(cpu->esp + 0xB8u) = x87_v1;
    cpu->eax = cpu->ebx;
    *(float*)(cpu->esp + 0xBCu) = x87_v1;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(float*)(cpu->esp + 0xC4u) = x87_v1;
    *(float*)(cpu->esp + 0xC8u) = x87_v1; 
    lift_push32(cpu, cpu->ecx);
    x87_v1 = (double)0.046875f;
    *(float*)(cpu->esp + 0xD0u) = x87_v1;
    *(float*)(cpu->esp + 0xD8u) = x87_v1; 
    *(float*)(cpu->esp + 0xD4u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DE47u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45DE47u));
    x87_v0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(float*)(cpu->esp + 0xBCu) = x87_v0;
    x87_v1 = (double)0.0234375f;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    *(float*)(cpu->esp + 0xC0u) = x87_v1;
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp + 0xC4u) = x87_v1;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0xCCu) = x87_v1;
    *(float*)(cpu->esp + 0xD0u) = x87_v1; 
    x87_v1 = (double)0.046875f;
    *(float*)(cpu->esp + 0xD4u) = x87_v1;
    *(float*)(cpu->esp + 0xBCu) = x87_v1; 
    *(float*)(cpu->esp + 0xB8u) = x87_v0;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->ecx -= cpu->edx;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DEB7u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45DEB7u));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x20u);
    *(float*)(cpu->esp + 0xC4u) = x87_v0;
    x87_v1 = (double)0.0234375f;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x28u);
    *(float*)(cpu->esp + 0xC8u) = x87_v1;
    cpu->edx = cpu->ebx;
    *(float*)(cpu->esp + 0xCCu) = x87_v1;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(float*)(cpu->esp + 0xD4u) = x87_v1;
    *(float*)(cpu->esp + 0xB8u) = x87_v1; 
    lift_push32(cpu, cpu->ecx);
    x87_v1 = (double)0.046875f;
    *(float*)(cpu->esp + 0xC0u) = x87_v1;
    *(float*)(cpu->esp + 0xC8u) = x87_v1; 
    *(float*)(cpu->esp + 0xC4u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + 1u;
    ++cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DF28u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45DF28u));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(float*)(cpu->esp + 0xCCu) = x87_v0;
    x87_v1 = (double)0.0234375f;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x28u);
    *(float*)(cpu->esp + 0xD0u) = x87_v1;
    cpu->edx = cpu->ebx;
    *(float*)(cpu->esp + 0xB4u) = x87_v1;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    *(float*)(cpu->esp + 0xBCu) = x87_v1;
    *(float*)(cpu->esp + 0xC0u) = x87_v1; 
    lift_push32(cpu, cpu->ecx);
    x87_v1 = (double)0.046875f;
    *(float*)(cpu->esp + 0xC8u) = x87_v1;
    *(float*)(cpu->esp + 0xD0u) = x87_v1; 
    *(float*)(cpu->esp + 0xCCu) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DF98u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45DF98u));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(float*)(cpu->esp + 0xB4u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    *(float*)(cpu->esp + 0xB8u) = x87_v0;
    cpu->eax -= cpu->ecx;
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x10u) = ((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (0.00390625));
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(float*)(cpu->esp + 0xBCu) = x87_v1;
    cpu->esi = cpu->ebx;
    *(float*)(cpu->esp + 0xC4u) = x87_v1; 
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    *(float*)(cpu->esp + 0xC4u) = x87_v0;
    lift_push32(cpu, cpu->ecx);
    x87_v1 = (double)0.0234375f;
    *(float*)(cpu->esp + 0xD0u) = x87_v1;
    *(float*)(cpu->esp + 0xD8u) = x87_v1; 
    *(float*)(cpu->esp + 0xD4u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x24u);
    lift_push32(cpu, (uintptr_t)"wf_bord");
    cpu->esi -= cpu->edx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E016u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45E016u));
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x28u);
    cpu->edx = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->edx -= cpu->eax;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->edx -= cpu->ecx;
    ++cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E043u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45E043u));
    x87_v0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x24u);
    *(float*)(cpu->esp + 0xB4u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x28u);
    x87_v1 = (double)0.0234375f;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(float*)(cpu->esp + 0xB8u) = x87_v1;
    cpu->eax -= cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xBCu) = x87_v1;
    ++cpu->eax;
    *(float*)(cpu->esp + 0xC0u) = x87_v1;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->esi = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    x87_v2 = (x87_v2) * (0.00390625);
    *(float*)(cpu->esp + 0x18u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0xCCu) = x87_v2;
    *(float*)(cpu->esp + 0xD4u) = x87_v2; 
    *(float*)(cpu->esp + 0xD0u) = x87_v1;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0xD8u) = x87_v1; 
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E0C5u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45E0C5u));
    x87_v0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x28u);
    cpu->ecx -= cpu->edx;
    ++cpu->ecx;
    lift_push32(cpu, (uintptr_t)"wf_bord"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax + 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E0F2u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45E0F2u));
    x87_v0 = 0.0;
    label_0005E0F4:
    *(float*)(cpu->esp + 0x5Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x60u) = (double)(1.0);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->ecx -= *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax = cpu->esp + 0x4Cu;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x28u);
    cpu->edx -= *(uint32_t*)(cpu->ebp + 0x24u);
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    ++cpu->edx;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetViewport(SferaAbi::pointer<const D3DVIEWPORT9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->esp += 4u;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    g_sfera_screen_clip_runtime.left = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x24u);
    g_sfera_screen_clip_runtime.top = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    g_sfera_screen_clip_runtime.right = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x28u);
    g_sfera_screen_clip_runtime.bottom = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->ebp + 0x34u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = (double)*(float*)(cpu->ebp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x40u) <= (int32_t)cpu->edi) goto label_0005E4C2;
    label_0005E180:
    cpu->eax = cpu->ebp + (cpu->edi * 4u) + 0x44u;
    if (*(uint32_t*)(cpu->ebp + (cpu->edi * 4u) + 0x44u) != 0xFFFFFFFFu) goto label_0005E19D;
    label_0005E190:
    cpu->eax += 4u;
    ++cpu->edi;
    if (*(uint32_t*)(cpu->eax) == 0xFFFFFFFFu) goto label_0005E190;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_0005E19D:
    cpu->esi = *(uint32_t*)(cpu->ebp + (cpu->edi * 4u) + 0x44u);
    if ((int32_t)cpu->esi >= 0) goto label_0005E1AF;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E1AFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5E1AFu));
    label_0005E1AF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005E1C3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E1C3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E1C3u));
    label_0005E1C3:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ebx = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->eax = 0u;
    if (cpu->ebx == cpu->eax) goto label_0005E508;
    x87_v0 = 0.0;
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xE80u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (cpu->ecx == 0xFFFFFFFFu) goto label_0005E39A;
    x87_v0 = (double)*(float*)(cpu->ebx + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x44u;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E20Au)); sfera_sub_004558A0(cpu, LIFT_CODE_TOKEN_VA(0x45E20Au));
    if (cpu->eax != 1u) goto label_0005E4AB;
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0005E23E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E23Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5E23Eu));
    label_0005E23E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005E252;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E252u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E252u));
    label_0005E252:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = 1u;
    cpu->esi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005E272;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E272u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E272u));
    label_0005E272:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->ecx + 8u))) - (((double)*(float*)(cpu->eax + 8u))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->ecx + 0xCu))) - (((double)*(float*)(cpu->eax + 0xCu))));
    *(float*)(cpu->esp + 0x34u) = ((((double)*(float*)(cpu->ecx + 0x10u))) - (((double)*(float*)(cpu->eax + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = 100.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0005E4A7; }
    x87_v0 = x87_v0 / x87_v1; 
    x87_v0 = (x87_v0) * (255.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x1Cu);
    cpu->ecx = 0xFFu;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_0005E310;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E310u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5E310u));
    label_0005E310:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005E324;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E324u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E324u));
    label_0005E324:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    cpu->esi = (uintptr_t)&g_sfera_model_transform_scratch_matrix;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ecx = cpu->esp + 0x64u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *SferaAbi::pointer<SferaVec3F>(cpu->edx) = SferaAbi::pointer<const SferaMatrix4x4F>(*SferaAbi::pointer<const std::uint32_t>(cpu->ecx))->inverseTransformPoint(*SferaAbi::pointer<const SferaVec3F>(cpu->edx));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esp + 0x34u))) - (2.0));
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v1 = (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.scale.x);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_0005E398; }
    x87_v0 = (x87_v0) + (0.009999999776482582);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    goto label_0005E39A;
    label_0005E398:
    x87_v0 = x87_v0; 
    label_0005E39A:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if ((cpu->eax) == 0u) goto label_0005E40B;
    if ((--cpu->eax) != 0u) goto label_0005E4AB;
    lift_push32(cpu, cpu->eax);
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xE80u);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x30u));
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80808081u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xE54u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xE50u);
    cpu->edx = cpu->ebx + 0xE58u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xE4Cu);
    cpu->edx -= *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xE48u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E406u)); sfera_sub_0044FCD0(cpu, LIFT_CODE_TOKEN_VA(0x45E406u));
    goto label_0005E4AB;
    label_0005E40B:
    sub_pred[0] = *(uint32_t*)(cpu->ebx + 0x2Cu) == 0u; sub_pred[1] = (int32_t)(*(uint32_t*)(cpu->ebx + 0x2Cu)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((sub_pred[0]) || (sub_pred[1])) goto label_0005E4AB;
    cpu->edi = cpu->ebx + 0x4E0u;
    label_0005E423:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xE40u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xE44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    cpu->ecx >>= 24u;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80808081u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x4B0u);
    cpu->ecx <<= 24u;
    cpu->esi &= 0xFFFFFFu;
    cpu->ecx |= cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xFFFFFB50u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->edx -= *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E490u)); sfera_sub_0044D190(cpu, LIFT_CODE_TOKEN_VA(0x45E490u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)(cpu->eax) < (int32_t)(*(uint32_t*)(cpu->ebx + 0x2Cu))) goto label_0005E423;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_0005E4AB;
    label_0005E4A7:
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    label_0005E4AB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->ebp + 0x40u)) goto label_0005E180;
    label_0005E4C2:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->edx = cpu->esp + 0x4Cu;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ecx;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->SetViewport(SferaAbi::pointer<const D3DVIEWPORT9>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)))); cpu->esp += 4u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xC8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005E508:
    cpu->ecx = (uintptr_t)"internal error 37185837";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E512u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5E512u));
    label_0005E512:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    (void)cpu;
    label_0005E520:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005E520;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"draw_window: wrong handle"),26u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E53Bu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45E53Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xC8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045E560(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    cpu->esi = 0u;
    cpu->ebx = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_0005E62A;
    label_0005E575:
    if ((int32_t)cpu->esi >= 0) goto label_0005E583;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E583u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5E583u));
    label_0005E583:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005E597;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E597u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E597u));
    label_0005E597:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0005E5A5;
    ++cpu->esi;
    goto label_0005E575;
    label_0005E5A5:
    if ((int32_t)cpu->esi >= 0) goto label_0005E5B3;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E5B3u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5E5B3u));
    label_0005E5B3:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005E5C7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E5C7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E5C7u));
    label_0005E5C7:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = cpu->ecx + (cpu->esi * 4u);
    if ((int32_t)cpu->esi >= 0) goto label_0005E5DE;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E5DEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5E5DEu));
    label_0005E5DE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005E5F2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5E5F2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5E5F2u));
    label_0005E5F2:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = g_sfera_interface_runtime.windows.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x3Cu);
    cpu->edi = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x3E8u);
    cpu->edx += *(uint32_t*)(cpu->eax + 0x6DA4u);
    *(uint32_t*)((cpu->ebx * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0])) = cpu->esi;
    *(uint32_t*)((cpu->ebx * 4u) + ((uintptr_t)&g_sfera_main_view_state_runtime.ui_sort_keys[0])) = cpu->edx;
    ++cpu->ebx;
    ++cpu->esi;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_0005E575;
    label_0005E62A:
    cpu->edx = cpu->edi + 0xFFFFFFFFu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E634u)); sfera_sub_0044F940(cpu, LIFT_CODE_TOKEN_VA(0x45E634u));
    cpu->esi = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_0005E655;
    label_0005E640:
    cpu->ecx = *(uint32_t*)((cpu->esi * 4u) + ((uintptr_t)&g_sfera_spatial_index_runtime.ui_sort_indices[0]));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E64Cu)); sfera_sub_0045DCD0(cpu, LIFT_CODE_TOKEN_VA(0x45E64Cu));
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.window_count) goto label_0005E640;
    label_0005E655:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0045EB60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005EB74;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EB74u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EB74u));
    label_0005EB74:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005EB88;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EB88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EB88u));
    label_0005EB88:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0005EB9D;
    cpu->ecx = (uintptr_t)"set_sprite_alpha: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EB9Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5EB9Du));
    label_0005EB9D:
    if ((int32_t)cpu->esi >= 0) goto label_0005EBAB;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EBABu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EBABu));
    label_0005EBAB:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005EBBF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EBBFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EBBFu));
    label_0005EBBF:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0xE80u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045EBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0005ECF0;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005EC06;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC06u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EC06u));
    label_0005EC06:
    cpu->eax = g_sfera_interface_runtime.windows.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == cpu->ebx) goto label_0005ECF0;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.windows.capacity) goto label_0005EC28;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.windows.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC28u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EC28u));
    label_0005EC28:
    cpu->ecx = g_sfera_interface_runtime.windows.data;
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x40u) <= (int32_t)cpu->ebx) goto label_0005ECB1;
    label_0005EC41:
    cpu->eax = cpu->edi + (cpu->ebx * 4u) + 0x44u;
    if (*(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x44u) != 0xFFFFFFFFu) goto label_0005EC59;
    label_0005EC50:
    cpu->eax += 4u;
    ++cpu->ebx;
    if (*(uint32_t*)(cpu->eax) == 0xFFFFFFFFu) goto label_0005EC50;
    label_0005EC59:
    cpu->esi = *(uint32_t*)(cpu->edi + (cpu->ebx * 4u) + 0x44u);
    if ((int32_t)cpu->esi >= 0) goto label_0005EC6B;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC6Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EC6Bu));
    label_0005EC6B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005EC7F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EC7Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EC7Fu));
    label_0005EC7F:
    cpu->edx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->esi == 0u) goto label_0005ECE6;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebp) goto label_0005EC95;
    cpu->ebp = cpu->eax;
    label_0005EC95:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x18u);
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_0005ECA2;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0005ECA2:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 0x40u)) goto label_0005EC41;
    label_0005ECB1:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->eax -= *(uint32_t*)(cpu->edi + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->ecx -= *(uint32_t*)(cpu->edi + 0x24u);
    ++*(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    ++cpu->eax;
    ++cpu->ecx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->ebp) goto label_0005ECCA;
    cpu->ebp = cpu->eax;
    label_0005ECCA:
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_0005ECD4;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_0005ECD4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + 0x2Cu) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->edi + 0x30u) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005ECE6:
    cpu->ecx = (uintptr_t)"internal error 47581837";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ECF0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5ECF0u));
    label_0005ECF0:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = cpu->ebx & 0xFFu;
    --cpu->edi;
    label_0005ED00:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005ED00;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"recalc_virtual_window_size: wrong handle"),41u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_0044F500(cpu, stop_address); return;
}







__declspec(noinline) void sfera_sub_00460C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_00060CB8;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60CB8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x60CB8u));
    label_00060CB8:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00060CCC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60CCCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x60CCCu));
    label_00060CCC:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_00060CFE;
    label_00060CD8:
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x144u) < (int32_t)0u) goto label_00060CE7;
    *(uint32_t*)(cpu->esi + 0x144u) = cpu->edi;
    label_00060CE7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00060CFE:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00060CD8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00060D1F;
    cpu->eax = (uintptr_t)"<none>";
    label_00060D1F:
    lift_push32(cpu, 0x45DDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x460D34u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460D46u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x460D46u));
    cpu->eip = 0x460D46u; ::DebugBreak(); return;
}





__declspec(noinline) void sfera_sub_00461700(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_main_view_state_runtime.view_accumulator = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_accumulator)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->ecx = g_sfera_world_load_runtime.loading_work_total;
    cpu->ecx += 0xFFFFFFB0u;
    if ((int32_t)cpu->ecx >= (int32_t)1u) goto label_00061719;
    cpu->ecx = 1u;
    label_00061719:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_accumulator;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi <= (int32_t)0x64u) goto label_00061731;
    cpu->esi = 0x64u;
    label_00061731:
    if (cpu->esi == g_sfera_graphics_runtime.rebuild_percent) goto label_0006179E;
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    g_sfera_graphics_runtime.rebuild_percent = cpu->esi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->beginScene());
    if ((cpu->eax & 0xFFu) == 0u) goto label_0006179E;
    cpu->ecx = cpu->esi;
    g_sfera_world_render_runtime.scene_active = 1u;
    g_sfera_interface.setLoadingProgress(static_cast<std::int32_t>(cpu->ecx));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    g_sfera_interface.update(static_cast<std::uint8_t>(cpu->ecx), static_cast<std::uint8_t>(cpu->edx), *SferaAbi::pointer<const std::uint32_t>(cpu->esp), static_cast<std::int32_t>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u))); cpu->esp += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461771u)); sfera_sub_0045E560(cpu, LIFT_CODE_TOKEN_VA(0x461771u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->EndScene(), "EndScene"));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461781u)); sfera_sub_0044E020(cpu, LIFT_CODE_TOKEN_VA(0x461781u));
    cpu->ecx = SferaAbi::address(g_sfera_graphics_runtime.d3d_runtime.get());
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    g_sfera_world_render_runtime.scene_active = 0u;
    cpu->eax = static_cast<std::uint32_t>(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->checkResult(SferaAbi::pointer<CD3D9Device>(cpu->ecx)->native_device->Present(SferaAbi::pointer<const RECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)), SferaAbi::pointer<const RECT>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 4u)), SferaAbi::pointer<HWND__>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 8u)), SferaAbi::pointer<const RGNDATA>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp + 12u))), "Present")); cpu->esp += 16u;
    label_0006179E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00461DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x424u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    cpu->esi = cpu->eax;
    { const auto result = WorldClock::nowTicks(); cpu->eax = static_cast<std::uint32_t>(result); cpu->edx = static_cast<std::uint32_t>(result >> 32u); }
    cpu->edx = (uintptr_t)"trap";
    cpu->ecx = cpu->esi;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461E0Du)); sfera_sub_0044CB00(cpu, LIFT_CODE_TOKEN_VA(0x461E0Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00061F47;
    cpu->ecx = cpu->ebx;
    cpu->ecx -= g_sfera_model_material_lookup_runtime.refresh_tick;
    if (cpu->ecx <= 0x2710u) goto label_00061F47;
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00061F41;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_00061E47;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61E47u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x61E47u));
    label_00061E47:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00061E5B;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61E5Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61E5Bu));
    label_00061E5B:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_00061E93;
    label_00061E68:
    if (*(uint32_t*)(cpu->eax + 0x18Cu) == 0u) goto label_00061F41;
    cpu->eax = 0u;
    cpu->ecx = cpu->edi + 0x10Cu;
    label_00061E80:
    if (*(uint32_t*)(cpu->ecx) != 0xFFFFFFFFu) goto label_00061EDB;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)cpu->eax < (int32_t)0xAu) goto label_00061E80;
    goto label_00061F41;
    label_00061E93:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00061E68;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00061EB4;
    cpu->eax = (uintptr_t)"<none>";
    label_00061EB4:
    lift_push32(cpu, 0x4A1Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461EC9u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61EDBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x61EDBu));
    label_00061EDB:
    cpu->ecx = *(uint32_t*)(cpu->edi + (cpu->eax * 4u) + 0x10Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461EE7u)); sfera_sub_00425BF0(cpu, LIFT_CODE_TOKEN_VA(0x461EE7u));
    cpu->edi = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"trap %d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x61EF8u));
    cpu->eax = g_sfera_world_objects.controlled_object_handle;
    cpu->esp += 0xCu;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_00061F12;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61F12u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x61F12u));
    label_00061F12:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00061F26;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61F26u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61F26u));
    label_00061F26:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->eax != 0u) goto label_00061F5F;
    label_00061F32:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18Cu);
    cpu->edx = cpu->esp + 0xCu;
    SferaAbi::pointer<SferaMbcProcessRecord>(cpu->ecx)->appendCommand(SferaAbi::pointer<const char>(cpu->edx));
    label_00061F41:
    g_sfera_model_material_lookup_runtime.refresh_tick = cpu->ebx;
    label_00061F47:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x424u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00061F5F:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00061F32;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = SferaAbi::address((*SferaAbi::pointer<const std::uint32_t>(cpu->esp) > 5000u && *SferaAbi::pointer<const std::uint32_t>(cpu->esp) != UINT32_MAX) ? SferaAbi::pointer<SphereRender::Model>(*SferaAbi::pointer<const std::uint32_t>(cpu->esp)) : g_sfera_models.model(*SferaAbi::pointer<const std::uint32_t>(cpu->esp))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_00061F80;
    cpu->eax = (uintptr_t)"<none>";
    label_00061F80:
    lift_push32(cpu, 0x4A25u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x61F95u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461FA3u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x461FA3u));
    cpu->eip = 0x461FA3u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00461FD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x34u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_shadow_runtime.manager;
    sub_pred[0] = *(uint8_t*)(cpu->ebp + 0xA0u) < 4u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->edi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    if (!sub_pred[0]) goto label_000623A0;
    { const double lift_left=(double)*(float*)(cpu->edi + 0x148u); const double lift_right=0.9900000095367432; if (lift_left<lift_right) goto label_000623A0; }
    x87_v0 = (double)50.0f;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->esi = 0u;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    if ((int32_t)g_sfera_client_main_scalar_runtime.counter_03 <= (int32_t)cpu->ebx) goto label_000621CB;
    cpu->esi = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0].position.y;
    label_00062041:
    if (*(uint32_t*)((cpu->ebx * 4u) + ((uintptr_t)&g_sfera_light_runtime.render_candidate_active[0])) == 0u) goto label_00062105;
    { const double lift_right=(double)*(float*)(cpu->esi); const double lift_left=(double)*(float*)(cpu->edi + 0xCu); if (lift_left<lift_right) goto label_00062105; }
    x87_v0 = (double)*(float*)(cpu->esi + 0xFFFFFFFCu);
    cpu->ebp = cpu->esi + 0xFFFFFFFCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 8u)));
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->esi))) - (((double)*(float*)(cpu->edi + 0xCu))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esi + 4u))) - (((double)*(float*)(cpu->edi + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (lift_left==lift_right) goto label_00062103; }
    { const double lift_left=x87_v0; const double lift_right=15.0; if (!(lift_left<lift_right)) goto label_00062103; }
    { const double lift_left=(double)*(float*)(cpu->esp + 0x14u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_00062103; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    goto label_00062105;
    label_00062103:
    x87_v0 = x87_v0; 
    label_00062105:
    ++cpu->ebx;
    cpu->esi += 0x3Cu;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_client_main_scalar_runtime.counter_03) goto label_00062041;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->esi == 0u) goto label_000621C7;
    sub_pred[1] = (uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == 0u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u); x87_v1 = x87_v0;
    x87_v2 = 1.0;
    x87_v1 = x87_v2 / x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x34u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x38u);
    x87_v2 = (x87_v2) * (x87_v1);
    *(float*)(cpu->esp + 0x38u) = x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v0 = (x87_v0) / (15.0);
    x87_v0 = (x87_v0) + (0.20000000298023224);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    if (!sub_pred[1]) goto label_000621AD;
    x87_v0 = (double)0.25f;
    x87_v1 = (double)g_sfera_graphics_runtime.environment_factor;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>=lift_right)) goto label_000621AB; }
    { const double lift_left=x87_v0; const double lift_right=0.8299999833106995;  if (!(lift_left<=lift_right)) goto label_000621AD; }
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (double)g_sfera_graphics_runtime.view_scale;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>lift_right)) goto label_000621AB; }
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    goto label_000621AD;
    label_000621AB:
    x87_v0 = x87_v0; 
    label_000621AD:
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x38u;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4621C5u)); sfera_sub_0048C860(cpu, LIFT_CODE_TOKEN_VA(0x4621C5u));
    goto label_000621CB;
    label_000621C7:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    label_000621CB:
    sub_pred[2] = (uint8_t)(g_sfera_view_spatial_runtime.alternate_projection) == 0u;
    x87_v0 = 1.0;
    if (sub_pred[2]) goto label_000621FA;
    if (cpu->esi != 0u) goto label_000621FA;
    x87_v1 = 0.0;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1;
    cpu->edx = cpu->esp + 0x2Cu;
    *(float*)(cpu->esp + 0x34u) = x87_v1; 
    cpu->ecx = cpu->ebp;
    *(float*)(cpu->esp + 0x30u) = x87_v0;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4621F8u)); sfera_sub_0048C860(cpu, LIFT_CODE_TOKEN_VA(0x4621F8u));
    goto label_000621FC;
    label_000621FA:
    x87_v0 = x87_v0; 
    label_000621FC:
    cpu->esi = 0u;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)1u) goto label_00062214;
    cpu->edx = cpu->esi + 1u;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62214u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x62214u));
    label_00062214:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0x28u) = ((((double)*(float*)(cpu->eax + 8u))) - (((double)*(float*)(cpu->edi + 8u))));
    *(float*)(cpu->esp + 0x2Cu) = ((((double)*(float*)(cpu->eax + 0xCu))) - (((double)*(float*)(cpu->edi + 0xCu))));
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->eax + 0x10u))) - (((double)*(float*)(cpu->edi + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x30u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = 15.0;
    x87_v1 = (x87_v0) - (x87_v1);
    x87_v1 = (x87_v1) / (10.0);
    x87_v2 = 1.0;
    x87_v1 = x87_v2 - x87_v1; 
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = 1.0;
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    { const double lift_left=x87_v2; const double lift_right=x87_v1; if (!(lift_left>lift_right)) goto label_000622A0; }
    x87_v2 = x87_v2; 
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    goto label_000622B7;
    label_000622A0:
    x87_v1 = x87_v2; 
    x87_v2 = 0.0;
    { const double lift_left=x87_v2; const double lift_right=x87_v1; x87_v1=x87_v2;  if (!(lift_left>lift_right)) goto label_000622B5; }
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    goto label_000622B7;
    label_000622B5:
    x87_v1 = x87_v1; 
    label_000622B7:
    { const double lift_left=x87_v0; const double lift_right=7.0; if (!(lift_left>lift_right)) goto label_000622CD; }
    x87_v0 = x87_v0; 
    cpu->esi = 2u;
    goto label_000622DF;
    label_000622CD:
    { const double lift_left=x87_v0; const double lift_right=((double)5.0f);  if (!(lift_left>lift_right)) goto label_000622DF; }
    cpu->esi = 1u;
    label_000622DF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    SphereWorld::ContactQuery::updateBounds(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xB0u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xB4u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xACu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = fabs(x87_v0);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)((uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp");
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esp + 0x1Cu)); if (!(lift_left>lift_right)) goto label_0006232F; }
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    goto label_00062331;
    label_0006232F:
    x87_v0 = x87_v0; 
    label_00062331:
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_v0 = std::acos(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::tan(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v1 = (double)*(float*)(cpu->edi + 0x8Cu);
    cpu->esp -= 8u;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edi + 0x80u)));
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    *(float*)(cpu->ecx) = x87_v0;
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x54u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x50u)));
    x87_v0 = (1.4900000095367432) / (x87_v0);
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46239Eu)); sfera_sub_0048CE10(cpu, LIFT_CODE_TOKEN_VA(0x46239Eu));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000623A0:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004623C0(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->esp -= 0x404u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x408u);
    cpu->eax = cpu->esp + 0x40Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x4623E9u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4623FAu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4623FAu));
    cpu->eip = 0x4623FAu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00462690(LiftCpu* cpu, uint32_t stop_address) {
    WNDCLASSEXA window_class{};
    window_class.cbSize = sizeof(window_class);
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc = &sfera_main_window_proc;
    window_class.hInstance = reinterpret_cast<HINSTANCE>(static_cast<uintptr_t>(g_sfera_main_ui_state_runtime.active_ui_object));
    window_class.hIcon = ::LoadIconA(window_class.hInstance, MAKEINTRESOURCEA(0x71));
    window_class.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
    window_class.hbrBackground = reinterpret_cast<HBRUSH>(::GetStockObject(BLACK_BRUSH));
    window_class.lpszClassName = reinterpret_cast<LPCSTR>(static_cast<uintptr_t>(sfera_window_class_name()));
    window_class.hIconSm = window_class.hIcon;
    if (::RegisterClassExA(&window_class) == 0u) { cpu->ecx = reinterpret_cast<uint32_t>("RegisterClassEx() failed! => init_main_window_class()"); lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62730u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x62730u)); }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


} // namespace lifted
