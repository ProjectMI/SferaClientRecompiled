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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45837Eu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x45837Eu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458DCCu)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x458DCCu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458DD9u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x458DD9u));
    cpu->ecx = (uintptr_t)"black";
    goto label_00058DFD;
label_00058DE0:
    cpu->ecx = (uintptr_t)"stars";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458DEAu)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x458DEAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458DF8u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x458DF8u));
    cpu->ecx = (uintptr_t)"stars";
label_00058DFD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458E02u)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_VA(0x458E02u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Du);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458E11u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x458E11u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458E21u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x458E21u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0x252u); lift_push32(cpu, (uintptr_t)&g_sfera_sky_runtime.indices[0]); lift_push32(cpu, 0x78u); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_sky_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xEu); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458E43u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x458E43u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Du);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x458E52u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x458E52u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x58F1Eu)); sfera_sub_00457370(cpu, LIFT_CODE_TOKEN_RVA(0x58F1Eu));
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
__declspec(noinline) void sfera_sub_00459080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.projection_sample_count;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_00059143;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->eax;
    label_00059096:
    if ((int32_t)cpu->esi >= 0) goto label_000590A4;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x590A4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x590A4u));
    label_000590A4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000590B8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x590B8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x590B8u));
    label_000590B8:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_000590C6;
    ++cpu->esi;
    goto label_00059096;
    label_000590C6:
    if ((int32_t)cpu->esi >= 0) goto label_000590D4;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x590D4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x590D4u));
    label_000590D4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_000590E8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x590E8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x590E8u));
    label_000590E8:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint32_t*)(cpu->edx + 0x1Cu) != cpu->edi) goto label_0005913A;
    if ((int32_t)cpu->esi >= 0) goto label_00059104;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59104u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x59104u));
    label_00059104:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_00059118;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59118u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59118u));
    label_00059118:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if ((cpu->eax) == 0u) goto label_00059133;
    if ((--cpu->eax) != 0u) goto label_0005913A;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459131u)); sfera_sub_00455C20(cpu, LIFT_CODE_TOKEN_VA(0x459131u));
    goto label_0005913A;
    label_00059133:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5913Au)); sfera_sub_00457370(cpu, LIFT_CODE_TOKEN_RVA(0x5913Au));
    label_0005913A:
    ++cpu->esi;
    if ((--cpu->ebx) != 0u) goto label_00059096;
    cpu->ebx = lift_pop32(cpu);
    label_00059143:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00459150(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebx < 0) goto label_00059339;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00059171;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59171u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59171u));
    label_00059171:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) == 0u) goto label_00059339;
    if ((int32_t)cpu->ebx >= (int32_t)g_sfera_client_main_scalar_runtime.mode_02) goto label_0005918E;
    g_sfera_client_main_scalar_runtime.mode_02 = cpu->ebx;
    label_0005918E:
    cpu->eax = g_sfera_world_objects.max_occupied_object_handle;
    if (cpu->ebx != cpu->eax) goto label_000591E7;
    --cpu->eax;
    g_sfera_world_objects.max_occupied_object_handle = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0xFFFFFFFFu) goto label_000591E7;
    label_000591A2:
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_000591B7;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4591B2u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x4591B2u));
    cpu->eax = g_sfera_world_objects.max_occupied_object_handle;
    label_000591B7:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000591D0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4591CBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x4591CBu));
    cpu->eax = g_sfera_world_objects.max_occupied_object_handle;
    label_000591D0:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) != 0u) goto label_000591E7;
    --cpu->eax;
    g_sfera_world_objects.max_occupied_object_handle = cpu->eax;
    if ((int32_t)cpu->eax > (int32_t)0xFFFFFFFFu) goto label_000591A2;
    label_000591E7:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000591FB;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x591FBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x591FBu));
    label_000591FB:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->edx + (cpu->ebx * 4u));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45920Cu)); sfera_sub_00459080(cpu, LIFT_CODE_TOKEN_VA(0x45920Cu));
    cpu->esi = cpu->ebp + 0x10Cu;
    cpu->edi = 0xAu;
    label_00059217:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_00059223;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59223u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_RVA(0x59223u));
    label_00059223:
    cpu->esi += 4u;
    if ((--cpu->edi) != 0u) goto label_00059217;
    if (*(uint8_t*)(cpu->ebp + 0x138u) != 1u) goto label_000592F5;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x184u);
    lift_test[0]=((cpu->esi)&0x80000000u)!=0u;
    if (cpu->esi!=0u) goto label_00059265;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459247u)); sfera_sub_00455D80(cpu, LIFT_CODE_TOKEN_VA(0x459247u));
    cpu->esi = cpu->ebp + 0xF8u;
    cpu->edi = 5u;
    label_00059252:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_0005925D;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5925Du)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_RVA(0x5925Du));
    label_0005925D:
    cpu->esi += 4u;
    if ((--cpu->edi) != 0u) goto label_00059252;
    goto label_0005929F;
    label_00059265:
    if (!lift_test[0]) goto label_00059271;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59271u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x59271u));
    label_00059271:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00059285;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59285u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59285u));
    label_00059285:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x188u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u) + 0xF8u) = 0u;
    label_0005929F:
    if ((int32_t)*(uint32_t*)(cpu->ebp + 0x144u) >= (int32_t)0u) goto label_000592B4;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x592B4u)); sfera_sub_0041B530(cpu, LIFT_CODE_TOKEN_RVA(0x592B4u));
    label_000592B4:
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x13Cu);
    if (cpu->esi == 0xFFFFFFFFu) goto label_000592FC;
    if ((int32_t)cpu->esi >= 0) goto label_000592CD;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x592CDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x592CDu));
    label_000592CD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_000592E1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x592E1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x592E1u));
    label_000592E1:
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 0u;
    --g_sfera_world_objects.extended_object_count;
    goto label_000592FC;
    label_000592F5:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x592FCu)); sfera_sub_00455D80(cpu, LIFT_CODE_TOKEN_RVA(0x592FCu));
    label_000592FC:
    lift_push32(cpu, 0x2453u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45930Du)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45930Du));
    cpu->ebp = lift_pop32(cpu);
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00059322;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59322u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59322u));
    label_00059322:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u)) = 0u;
    --g_sfera_main_render_runtime.world_object_count;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00059339:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00059346:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00059346;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"DeleteObject: wrong handle"),27u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0044F500(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00459370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 2u;
    label_00059376:
    if ((int32_t)cpu->esi >= 0) goto label_00059384;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59384u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x59384u));
    label_00059384:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00059398;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59398u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59398u));
    label_00059398:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_000593AA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x593AAu)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_RVA(0x593AAu));
    label_000593AA:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x7A120u) goto label_00059376;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004593C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_000593DF;
    lift_push32(cpu, (uintptr_t)"Wrong handle: Link_object_to_object\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4593D9u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4593D9u));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000593DF:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_000593F3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x593F3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x593F3u));
    label_000593F3:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0xF8u);
    if (cpu->ecx == 0u) goto label_0005940B;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5940Bu)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_RVA(0x5940Bu));
    label_0005940B:
    *(uint32_t*)(cpu->esi + (cpu->edi * 4u) + 0xF8u) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00459420(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    sub_pred[0] = (int32_t)(cpu->esi) < (int32_t)(cpu->edi);
    if (cpu->esi == cpu->edi) goto label_0005952C;
    if (!sub_pred[0]) goto label_0005943D;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5943Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5943Du));
    label_0005943D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00059451;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x59451u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x59451u));
    label_00059451:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->ecx == cpu->edi) goto label_00059475;
    lift_push32(cpu, 0x4024u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459472u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x459472u));
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    label_00059475:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x2Cu);
    if (cpu->ecx == cpu->edi) goto label_0005948E;
    lift_push32(cpu, 0x4025u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45948Bu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45948Bu));
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    label_0005948E:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x3Cu);
    if (cpu->ecx == cpu->edi) goto label_000594A7;
    lift_push32(cpu, 0x4026u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4594A4u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4594A4u));
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->edi;
    label_000594A7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == cpu->edi) goto label_000594C0;
    lift_push32(cpu, 0x4027u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4594BDu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4594BDu));
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    label_000594C0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1CCu);
    if (cpu->ecx == cpu->edi) goto label_000594DF;
    lift_push32(cpu, 0x4028u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4594D9u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4594D9u));
    *(uint32_t*)(cpu->esi + 0x1CCu) = cpu->edi;
    label_000594DF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1C8u);
    if (cpu->ecx == cpu->edi) goto label_000594FE;
    lift_push32(cpu, 0x4029u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4594F8u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4594F8u));
    *(uint32_t*)(cpu->esi + 0x1C8u) = cpu->edi;
    label_000594FE:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1D0u);
    if (cpu->eax == cpu->edi) goto label_00059512;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x459509u));
    cpu->esp += 4u;
    label_00059512:
    lift_push32(cpu, 0x402Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459523u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x459523u));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45952Au)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_VA(0x45952Au));
    *(uint32_t*)(cpu->ebx) = cpu->edi;
    label_0005952C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459585u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x459585u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4595D1u)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_VA(0x4595D1u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459686u)); sfera_sub_004258F0(cpu, LIFT_CODE_TOKEN_VA(0x459686u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45968Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x45968Cu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4596E8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4596E8u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459719u)); sfera_sub_0041F2F0(cpu, LIFT_CODE_TOKEN_VA(0x459719u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45971Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x45971Fu));
    cpu->esp += 4u;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45974Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x45974Eu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45977Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x45977Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597B4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4597B4u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597D7u)); sfera_sub_004BCEF0(cpu, LIFT_CODE_TOKEN_VA(0x4597D7u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597DCu)); sfera_sub_0048DB30(cpu, LIFT_CODE_TOKEN_VA(0x4597DCu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597E1u)); sfera_sub_00459370(cpu, LIFT_CODE_TOKEN_VA(0x4597E1u));
    if (g_sfera_model_runtime.repository == cpu->edi) goto label_00059818;
    cpu->edx = 0x46Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4597F8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4597F8u));
    cpu->ecx = g_sfera_model_runtime.repository;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == cpu->edi) goto label_00059812;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459809u)); sfera_sub_0047F450(cpu, LIFT_CODE_TOKEN_VA(0x459809u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45980Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x45980Fu));
    cpu->esp += 4u;
    label_00059812:
    g_sfera_model_runtime.repository = cpu->edi;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459846u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x459846u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45988Du)); sfera_sub_004571F0(cpu, LIFT_CODE_TOKEN_VA(0x45988Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4598EEu)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x4598EEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459947u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x459947u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459971u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x459971u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4599A9u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x4599A9u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4599D3u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x4599D3u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459A45u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x459A45u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459AEEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x459AEEu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459C03u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x459C03u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x459C3Du)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x459C3Du));
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
    lift_trap(cpu, 0x459CA0u, "INT3"); return;
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
    lift_trap(cpu, 0x459D04u, "INT3"); return;
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
    lift_trap(cpu, 0x459DB4u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00459DC0(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->ecx > 7u) goto label_00059E1C;
    switch (cpu->ecx) {
        case 0u: goto label_00059DCC;
        case 1u: goto label_00059DD6;
        case 2u: goto label_00059DE0;
        case 3u: goto label_00059DEA;
        case 4u: goto label_00059DF4;
        case 5u: goto label_00059DFE;
        case 6u: goto label_00059E08;
        case 7u: goto label_00059E12;
        default: lift_trap(cpu, 0x459DC5u, "resolved jump-table index out of range"); return;
    }
label_00059DCC: ;
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \356\362\352\360\373\362\350\377 \364\340\351\353\3403: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DD6:
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \361\356\347\344\340\355\350\377 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DE0:
    cpu->ecx = (uintptr_t)"\315\345\356\346\350\344\340\355\355\373\351 \352\356\355\345\366 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DEA:
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \367\362\345\355\350\377 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DF4:
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \347\340\357\350\361\350 \364\340\351\353\340 (\342\356\347\354\356\346\355\356, \355\345\362 \354\345\361\362\340 \355\340 \344\350\361\352\345): ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059DFE:
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \347\340\357\350\361\350 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059E08:
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \357\356\347\350\366\350\356\355\350\360\356\342\340\355\350\377 \342 \364\340\351\353\345: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059E12:
    cpu->ecx = (uintptr_t)"\316\370\350\341\352\340 \347\340\352\360\373\362\350\377 \364\340\351\353\340: ";
    sfera_sub_00459CB0(cpu, stop_address); return;
    label_00059E1C:
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A089u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x45A089u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x7FDu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A09Cu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45A09Cu));
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A0A7u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x45A0A7u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A0B3u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x45A0B3u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A0BAu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x45A0BAu));
    cpu->edi = *(uint16_t*)(cpu->ebx + 0xAu);
    cpu->edx = *(uint16_t*)(cpu->ebx + 6u);
    cpu->ecx = cpu->ebx + cpu->esi + 0xFFFFFD00u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->edi -= cpu->edx;
    cpu->ecx = cpu->esp + 0x80u;
    ++cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A0DCu)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x45A0DCu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A108u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x45A108u));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A116u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x45A116u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A11Fu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x45A11Fu));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->edi += cpu->eax;
    cpu->eax = g_sfera_font_atlas_staging_runtime.width;
    cpu->edi = (cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u); lift_push32(cpu, 0x1Au);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A6CFu)); sfera_sub_004D8E70(cpu, LIFT_CODE_TOKEN_VA(0x45A6CFu));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45A7AAu)); sfera_sub_004D8E70(cpu, LIFT_CODE_TOKEN_VA(0x45A7AAu));
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
__declspec(noinline) void sfera_sub_0045A8E0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6;
 double x87_p0, x87_p1, x87_p2, x87_p3;
    lift_push32(cpu, cpu->ecx);
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    x87_p2 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->edi = cpu->edx;
    x87_p3 = x87_p1;
    cpu->esi = cpu->ecx;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 8u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 8u) = x87_p0; 
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->esp + 8u);
    x87_p0 = (double)9.999999747378752e-06f;
    x87_p1 = (double)*(float*)(cpu->esp + 8u);
     value_0 = x87_p1; value_1 = x87_p0; if (!((value_0)<(value_1))) goto label_0005A96C;
     if (cpu->edi != 0u) goto label_0005A949;
    x87_p0 = 0.0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi) = x87_p0;
    cpu->eax = cpu->esi;
    *(float*)(cpu->esi + 4u) = x87_p0;
    *(float*)(cpu->esi + 8u) = x87_p0; 
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
label_0005A949:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)&g_sfera_terrain_diagnostic_runtime.normalize_code[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45A954u));
    cpu->esp += 0xCu;
    cpu->edx = (uintptr_t)&g_sfera_terrain_diagnostic_runtime.normalize_code[0];
    cpu->ecx = (uintptr_t)"normalize: normal with extra short length found. Code:";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5A96Cu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x5A96Cu));
label_0005A96C:
    x87_p0 = 1.0;
    cpu->edi = lift_pop32(cpu);
    value_2 = x87_p0 / value_0; 
    *(float*)(cpu->esp + 4u) = value_2; 
    value_3 = (double)*(float*)(cpu->esp + 0xCu);
    x87_p0 = (double)*(float*)(cpu->esp + 4u); x87_p1 = x87_p0;
    value_4 = value_3 * x87_p1; 
    value_6 = x87_p0; x87_p0 = value_4;
    *(float*)(cpu->esp + 0xCu) = x87_p0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    x87_p0 = (x87_p0) * (value_6);
    cpu->eax = cpu->esi;
    *(float*)(cpu->esp + 0x10u) = x87_p0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    value_5 = (value_6) * (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = value_5; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
     cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_0045ACF0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = 0u;
    label_0005AD00:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005AD14;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AD14u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5AD14u));
    label_0005AD14:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005AD22;
    ++cpu->esi;
    goto label_0005AD00;
    label_0005AD22:
    if (cpu->ebx != 0xFFFFFFFFu) goto label_0005ADA4;
    cpu->edx = 0xD4Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AD36u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45AD36u));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AD3Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x45AD3Du));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0005AD7D;
    *(float*)(cpu->eax) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->eax + 8u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->eax + 0xCu) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->eax + 0x10u) = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edi;
    *(float*)(cpu->eax + 0x14u) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->esi;
    g_sfera_main_command_state_runtime.object_reference_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) + 1u;
    cpu->edi = cpu->eax;
    goto label_0005AD7F;
    label_0005AD7D:
    cpu->edi = 0u;
    label_0005AD7F:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005AD93;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AD93u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5AD93u));
    label_0005AD93:
    cpu->ecx = g_sfera_collision_runtime.contact_objects.data;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_0005ADA4:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005ADB8;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ADB8u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5ADB8u));
    label_0005ADB8:
    cpu->edx = g_sfera_collision_runtime.contact_objects.data;
    if (*(uint32_t*)(cpu->edx + (cpu->ebx * 4u)) != 0u) goto label_0005ADCE;
    cpu->ecx = (uintptr_t)"create_line: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ADCEu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5ADCEu));
    label_0005ADCE:
    cpu->edx = 0xD52u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45ADDDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x45ADDDu));
    lift_push32(cpu, 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45ADE4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x45ADE4u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0005AE24;
    *(float*)(cpu->eax) = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->esp + 0x14u);
    *(float*)(cpu->eax + 8u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->eax + 0xCu) = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->eax + 0x10u) = (double)*(float*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edi;
    *(float*)(cpu->eax + 0x14u) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ebx;
    g_sfera_main_command_state_runtime.object_reference_count = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.object_reference_count)) + 1u;
    cpu->edi = cpu->eax;
    goto label_0005AE26;
    label_0005AE24:
    cpu->edi = 0u;
    label_0005AE26:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_collision_runtime.contact_objects.capacity) goto label_0005AE3A;
    cpu->edx = (uintptr_t)&g_sfera_collision_runtime.contact_objects.data;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AE3Au)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5AE3Au));
    label_0005AE3A:
    cpu->eax = g_sfera_collision_runtime.contact_objects.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045AE50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x4B8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x4C8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x4C8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if ((int32_t)cpu->edi <= (int32_t)1u) goto label_0005AE8F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->edi + 0xFFFFFFFEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AE8Au)); sfera_sub_004A5270(cpu, LIFT_CODE_TOKEN_VA(0x45AE8Au));
    goto label_0005AF7E;
    label_0005AE8F:
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->ebx) = 0u;
    sub_pred[0] = *(uint8_t*)(cpu->ecx) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->edx = 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (sub_pred[0]) goto label_0005AF3A;
    label_0005AEB4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    cpu->eax = *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u);
    if ((cpu->ecx & 0xFFu) != 0xAu) goto label_0005AEF0;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x4CCu));
    *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi)) goto label_0005AED9;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_0005AED9:
    ++cpu->edx;
    if (cpu->edx == 0x12Cu) goto label_0005AF98;
    *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u) = 0u;
    goto label_0005AF2F;
    label_0005AEF0:
    if ((cpu->eax==0u) || (((cpu->eax)&0x80000000u)!=0u)) goto label_0005AF05;
    cpu->ebx = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    cpu->ebx += cpu->eax;
    *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0005AF05:
    cpu->eax = cpu->ecx & 0xFFu;
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    if (*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].defined)) != 0u) goto label_0005AF1F;
    cpu->eax = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[124][0]));
    goto label_0005AF2B;
    label_0005AF1F:
    cpu->ecx = cpu->edi + (cpu->eax * 4u);
    cpu->ecx += cpu->eax;
    cpu->eax = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    label_0005AF2B:
    *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_0005AF2F:
    ++cpu->ebp;
    if (*(uint8_t*)(cpu->ebp) != 0u) goto label_0005AEB4;
    label_0005AF3A:
    cpu->eax = *(uint32_t*)(cpu->esp + (cpu->edx * 4u) + 0x14u);
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi)) goto label_0005AF44;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_0005AF44:
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(2u) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.span[0]));
    --cpu->edx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.cell_step[0])));
    cpu->edx -= *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0]));
    cpu->eax = cpu->edx + cpu->ecx + 2u;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x4CCu));
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    if (cpu->edi != 1u) goto label_0005AF7D;
    cpu->eax += 2u;
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    label_0005AF7D:
    cpu->ebp = lift_pop32(cpu);
    label_0005AF7E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4B8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0005AF98:
    cpu->ecx = (uintptr_t)"MNO_LINES_IN_TEXT exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AFA2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45AFA2u));
    lift_trap(cpu, 0x45AFA2u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0045AFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AFBCu)); sfera_sub_00449180(cpu, LIFT_CODE_TOKEN_VA(0x45AFBCu));
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_01) = 1u;
    cpu->edi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AFCAu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x45AFCAu));
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    g_sfera_client_process_runtime.shutdown_requested = cpu->edi;
    label_0005AFD6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45AFDBu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x45AFDBu));
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
__declspec(noinline) void sfera_sub_0045B060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x19Cu;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x138u;
    cpu->edx -= cpu->eax;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ebx = 0u;
    label_0005B087:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0005B087;
    cpu->eax = cpu->esp + 0x13Cu;
    --cpu->eax;
    label_0005B0A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0005B0A0;
    cpu->ecx = *(uint32_t*)((uintptr_t)"*.siz");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"*.siz") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint16_t*)(cpu->eax + 4u) = cpu->edx & 0xFFFFu;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x140u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x45B0C8u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    if (cpu->esi != 0xFFFFFFFFu) goto label_0005B0E6;
    cpu->ecx = (uintptr_t)"*.siz files not found";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B0E6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5B0E6u));
    label_0005B0E6:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_0005B0F0:
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_0005B32A;
    cpu->esi = g_sfera_recovered_static_runtime.font_renderer_state;
    cpu->edi = 0u;
    if ((int32_t)cpu->esi > (int32_t)0x12Bu) goto label_0005B364;
    cpu->ebp = cpu->esi;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x6CCu);
    label_0005B117:
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B125;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B125u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B125u));
    label_0005B125:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B139;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B139u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B139u));
    label_0005B139:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->edi + 0x40u));
    cpu->eax += cpu->ebp;
    *(uint8_t*)(cpu->eax + cpu->edi) = cpu->ecx & 0xFFu;
    ++cpu->edi;
    if (*(uint8_t*)(cpu->esp + cpu->edi + 0x40u) != 0x2Eu) goto label_0005B117;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B15D;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B15Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B15Du));
    label_0005B15D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B171;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B171u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B171u));
    label_0005B171:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->eax += cpu->ebp;
    *(uint8_t*)(cpu->eax + cpu->edi) = cpu->ebx & 0xFFu;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B18D;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B18Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B18Du));
    label_0005B18D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B1A1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B1A1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B1A1u));
    label_0005B1A1:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = cpu->ecx + cpu->ebp + 0x1Eu;
    label_0005B1B0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->edi;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0005B1B0;
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B1C5u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x45B1C5u));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B1D5;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B1D5u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B1D5u));
    label_0005B1D5:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B1E9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B1E9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B1E9u));
    label_0005B1E9:
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->edx + cpu->ebp + 0x84u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B1FFu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x45B1FFu));
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B20D;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B20Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B20Du));
    label_0005B20D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B221;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B221u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B221u));
    label_0005B221:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->eax + cpu->ebp + 0x88u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B236u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x45B236u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B23Du)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x45B23Du));
    cpu->edi = cpu->ebp + 0x21Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xAu;
    label_0005B250:
    cpu->ebp = 0xAu;
    label_0005B255:
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B263;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B263u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B263u));
    label_0005B263:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B277;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B277u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B277u));
    label_0005B277:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    *(uint32_t*)(cpu->edi + cpu->ecx + 0xFFFFFE70u) = cpu->ebx;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B292;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B292u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B292u));
    label_0005B292:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B2A6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B2A6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B2A6u));
    label_0005B2A6:
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    *(uint32_t*)(cpu->edi + cpu->edx) = cpu->ebx;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B2BD;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B2BDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B2BDu));
    label_0005B2BD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B2D1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B2D1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B2D1u));
    label_0005B2D1:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    *(uint32_t*)(cpu->edi + cpu->eax + 0x190u) = cpu->ebx;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005B2EB;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B2EBu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B2EBu));
    label_0005B2EB:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B2FF;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B2FFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B2FFu));
    label_0005B2FF:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    *(uint32_t*)(cpu->edi + cpu->ecx + 0x320u) = cpu->ebx;
    cpu->edi += 4u;
    if ((--cpu->ebp) != 0u) goto label_0005B255;
    if ((--*(uint32_t*)(cpu->esp + 0x10u)) != 0u) goto label_0005B250;
    ++g_sfera_recovered_static_runtime.font_renderer_state;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    label_0005B32A:
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x45B330u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0005B0F0;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x45B342u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x19Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005B364:
    cpu->ecx = (uintptr_t)"Too many landscape files\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B36Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45B36Eu));
    lift_trap(cpu, 0x45B36Eu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0045B370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x1326u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x20000u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B385u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45B385u));
    lift_push32(cpu, 0x20000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    g_sfera_client_main_scalar_runtime.state_02 = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45B395u));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)"landscape\\*.mtx";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B3A7u)); sfera_sub_0044D960(cpu, LIFT_CODE_TOKEN_VA(0x45B3A7u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_0005B3BA;
    cpu->ecx = (uintptr_t)"landscape_hr\\*.mtx";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B3BAu)); sfera_sub_0044D960(cpu, LIFT_CODE_TOKEN_RVA(0x5B3BAu));
    label_0005B3BA:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_0005B3CD;
    cpu->ecx = (uintptr_t)"landscape_ph\\*.mtx";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B3CDu)); sfera_sub_0044D960(cpu, LIFT_CODE_TOKEN_RVA(0x5B3CDu));
    label_0005B3CD:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_0005B3E0;
    cpu->ecx = (uintptr_t)"landscape_rd\\*.mtx";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B3E0u)); sfera_sub_0044D960(cpu, LIFT_CODE_TOKEN_RVA(0x5B3E0u));
    label_0005B3E0:
    if (g_sfera_graphics_runtime.base_microtexture_id != 0xFFFFFFFFu) goto label_0005B3F3;
    cpu->ecx = (uintptr_t)"Base microtexture not found: landscape\\\077\077_.mtx";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B3F3u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5B3F3u));
    label_0005B3F3:
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_0005B3F6:
    if ((int32_t)cpu->esi >= 0) goto label_0005B404;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B404u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B404u));
    label_0005B404:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.microtexture_handles.capacity) goto label_0005B418;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.microtexture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B418u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B418u));
    label_0005B418:
    cpu->eax = g_sfera_landscape_runtime.microtexture_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 0xFFFFFFFFu;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x2710u) goto label_0005B3F6;
    cpu->ecx = (uintptr_t)"landscape\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B437u)); sfera_sub_0045B060(cpu, LIFT_CODE_TOKEN_VA(0x45B437u));
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_20 == 0u) goto label_0005B44A;
    cpu->ecx = (uintptr_t)"landscape_hr\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B44Au)); sfera_sub_0045B060(cpu, LIFT_CODE_TOKEN_RVA(0x5B44Au));
    label_0005B44A:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_21 == 0u) goto label_0005B45D;
    cpu->ecx = (uintptr_t)"landscape_ph\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B45Du)); sfera_sub_0045B060(cpu, LIFT_CODE_TOKEN_RVA(0x5B45Du));
    label_0005B45D:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_22 == 0u) goto label_0005B470;
    cpu->ecx = (uintptr_t)"landscape_rd\\";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B470u)); sfera_sub_0045B060(cpu, LIFT_CODE_TOKEN_RVA(0x5B470u));
    label_0005B470:
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)"landscape\\map.bin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B47Cu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x45B47Cu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x22600u);
    cpu->edx = (uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B48Fu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x45B48Fu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B496u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x45B496u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->esi = (uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    lift_push32(cpu, cpu->edi);
    label_0005B4A0:
    cpu->ebx = 0x50u;
    label_0005B4A5:
    cpu->edi = 0u;
    if ((int32_t)g_sfera_recovered_static_runtime.font_renderer_state <= (int32_t)cpu->edi) goto label_0005B4F8;
    cpu->ebp = 0u;
    label_0005B4B1:
    if ((int32_t)cpu->edi >= 0) goto label_0005B4BF;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B4BFu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B4BFu));
    label_0005B4BF:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B4D3;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B4D3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B4D3u));
    label_0005B4D3:
    cpu->eax = g_sfera_landscape_runtime.file_records.data;
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x45B4DCu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0005B519;
    ++cpu->edi;
    cpu->ebp += 0x6CCu;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_recovered_static_runtime.font_renderer_state) goto label_0005B4B1;
    label_0005B4F8:
    cpu->edx = *(uint32_t*)((uintptr_t)"FILL_EMPT");
    cpu->eax = *(uint32_t*)(((uintptr_t)"FILL_EMPT") + 4u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"FILL_EMPT") + 8u));
    *(uint32_t*)(cpu->esi) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 8u) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + 0x14u) = 0u;
    label_0005B519:
    cpu->esi += 0x16u;
    if ((--cpu->ebx) != 0u) goto label_0005B4A5;
    if ((int32_t)cpu->esi < (int32_t)((uintptr_t)&g_sfera_landscape_map_runtime.records[kLandscapeMapRecordCount])) goto label_0005B4A0;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    (void)cpu;
    label_0005B530:
    cpu->ebp = 0u;
    label_0005B532:
    cpu->esi = 0u;
    cpu->edi = 0u;
    label_0005B540:
    if ((int32_t)(cpu->esi) >= (int32_t)((uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state))) goto label_0005B5F6;
    if ((int32_t)cpu->esi >= 0) goto label_0005B55A;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B55Au)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B55Au));
    label_0005B55A:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B56E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B56Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B56Eu));
    label_0005B56E:
    cpu->edx = g_sfera_landscape_runtime.file_records.data;
    cpu->ecx = cpu->ebx + cpu->ebp;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x16u);
    cpu->ecx += ((uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->eax = cpu->edi + cpu->edx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x45B585u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0005B59B;
    ++cpu->esi;
    cpu->edi += 0x6CCu;
    goto label_0005B540;
    label_0005B59B:
    if ((int32_t)cpu->esi >= 0) goto label_0005B5A9;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B5A9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5B5A9u));
    label_0005B5A9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_0005B5BD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B5BDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5B5BDu));
    label_0005B5BD:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x6CCu);
    cpu->esi += g_sfera_landscape_runtime.file_records.data;
    cpu->edx = cpu->ebx + cpu->ebp;
    ++cpu->ebp;
    *(uint32_t*)((cpu->edx * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0])) = cpu->esi;
    if ((int32_t)cpu->ebp < (int32_t)0x50u) goto label_0005B532;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 0x50u;
    if ((int32_t)cpu->ebx < (int32_t)0x1900u) goto label_0005B530;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005B5F6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->edx <<= 4u;
    cpu->edx += cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16u);
    cpu->edx += ((uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->ecx = (uintptr_t)"Patch present in map, but not found in \\landscape. Name: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B615u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_VA(0x45B615u));
    lift_trap(cpu, 0x45B615u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0045B620(LiftCpu* cpu, uint32_t stop_address) { double x87_p0, x87_p1, x87_p2, x87_p3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xDCu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xD4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B688u)); sfera_sub_00453A20(cpu, LIFT_CODE_TOKEN_VA(0x45B688u));
    if (cpu->eax == 0u) goto label_0005BC34;
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = 0x78u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B6A1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45B6A1u));
    lift_push32(cpu, 0x78u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45B6AAu));
    cpu->esp += 0xCu;
    cpu->ebx = 0xAu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x54u) = 0x1Eu;
    *(uint32_t*)(cpu->esp + 0x58u) = 0x32u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x60u) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B6DFu)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x45B6DFu));
    cpu->ebp = native_function_address32(&::strncpy);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncpy)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esp + 0x6Fu) = 0u;
    *(uint32_t*)(cpu->esp + 0x80u) = 0x1513u;
    lift_push32(cpu, 0x66u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    cpu->ecx = cpu->ebx + 0x14u;
    *(uint32_t*)(cpu->esp + 0xCCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B71Au)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x45B71Au));
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->edx + 0x14u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint16_t*)(cpu->edx + 0x1Cu) = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, 0xFu);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    *(uint32_t*)(cpu->esp + 0x8Cu) = 0x1Eu;
    *(uint32_t*)(cpu->esp + 0x90u) = 0x32u;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x98u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45B7A0u)); sfera_sub_00401000(cpu, LIFT_CODE_TOKEN_VA(0x45B7A0u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0xA0u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::strncpy)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esp + 0xA7u) = 0u;
    *(uint32_t*)(cpu->esp + 0xB8u) = 0x1514u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u) + 0x68B0u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint8_t*)(cpu->esp + 0xC8u) = 1u;
    if (cpu->eax == *(uint32_t*)(cpu->edx + (cpu->edi * 4u) + 0x68B0u)) goto label_0005B7EB;
    cpu->ecx = (uintptr_t)"Error of smoothing region's edge: numbers of vertex groups are differ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B7EBu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5B7EBu));
    label_0005B7EB:
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u) + 0x68A0u);
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u) + 0x68A0u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_0005BBF9;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    goto label_0005B81B;
    label_0005B813:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    label_0005B81B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u));
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ebp = *(uint16_t*)(cpu->edx + (cpu->ecx * 2u));
    ++cpu->ecx;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    if ((int32_t)cpu->ebx <= 0) goto label_0005B898;
    label_0005B83B:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005B84C;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B84Cu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B84Cu));
    label_0005B84C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u));
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = cpu->eax + (cpu->edx * 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    ++cpu->ecx;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005B888;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B888u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B888u));
    label_0005B888:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint8_t*)(cpu->ecx + cpu->esi) = 0u;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0005B83B;
    label_0005B898:
    if ((int32_t)cpu->ebp <= 0) goto label_0005B8FA;
    cpu->edi = cpu->ebp;
    label_0005B89E:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005B8AF;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B8AFu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B8AFu));
    label_0005B8AF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->eax = *(uint16_t*)(cpu->edx + (cpu->ecx * 2u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax = cpu->edx + (cpu->eax * 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    ++cpu->ecx;
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005B8EB;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B8EBu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B8EBu));
    label_0005B8EB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint8_t*)(cpu->eax + cpu->esi) = 0u;
    ++cpu->esi;
    if ((--cpu->edi) != 0u) goto label_0005B89E;
    label_0005B8FA:
    cpu->ebx += cpu->ebp;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)cpu->ebx <= 0) goto label_0005BBEF;
    label_0005B910:
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005B927;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B927u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B927u));
    label_0005B927:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    if (*(uint8_t*)(cpu->ecx + cpu->edi) == 2u) goto label_0005BBE6;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005B94F;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B94Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B94Fu));
    label_0005B94F:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint8_t*)(cpu->edx + cpu->edi) = 1u;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005B96B;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B96Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B96Bu));
    label_0005B96B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->esi = cpu->edi + 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0005BAFA;
    label_0005B992:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005B9A9;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B9A9u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B9A9u));
    label_0005B9A9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) == 2u) goto label_0005BAF1;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005B9CB;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B9CBu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B9CBu));
    label_0005B9CB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = cpu->edx + (cpu->esi * 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005B9E7;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5B9E7u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5B9E7u));
    label_0005B9E7:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->edx = cpu->ecx + (cpu->edi * 4u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005BA03;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BA03u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BA03u));
    label_0005BA03:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->eax + (cpu->esi * 4u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005BA1F;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BA1Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BA1Fu));
    label_0005BA1F:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ebx = cpu->edx + (cpu->edi * 4u);
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005BA37;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BA37u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BA37u));
    label_0005BA37:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ebp = cpu->eax + (cpu->esi * 4u);
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005BA4F;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BA4Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BA4Fu));
    label_0005BA4F:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    x87_p0 = (double)*(float*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->eax + 4u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    x87_p1 = (double)*(float*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ecx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    x87_p0 = x87_p0 + x87_p1; 
    x87_p1 = (double)*(float*)(cpu->eax + 8u);
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ecx + 8u)));
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    { const double lift_left=0.0; const double lift_right=((double)*(float*)(cpu->esp + 0x14u)); if (lift_left>lift_right) goto label_0005BAED; }
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005BAA9;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BAA9u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BAA9u));
    label_0005BAA9:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint8_t*)(cpu->edx + cpu->esi) = 1u;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005BAC5;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BAC5u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BAC5u));
    label_0005BAC5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->eax + 0xCu))) + (((double)*(float*)(cpu->esp + 0x18u))));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->eax + 0x10u))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->eax + 0x14u))) + (((double)*(float*)(cpu->esp + 0x20u))));
    label_0005BAED:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    label_0005BAF1:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_0005B992;
    label_0005BAFA:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p2 = (double)*(float*)(cpu->esp + 0x20u);
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p0; x87_p0 = temporary; }
    x87_p1 = x87_p1 + x87_p2; 
    x87_p2 = x87_p0;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->esi = cpu->edi;
    x87_p1 = 1.0;
    x87_p0 = x87_p1 / x87_p0; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x14u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    { double temporary = x87_p1; x87_p1 = x87_p0; x87_p0 = temporary; }
    *(float*)(cpu->esp + 0x18u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p1 = (x87_p1) * (x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p1; 
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_p0; 
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0005BBE6;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0005BB70:
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005BB87;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BB87u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BB87u));
    label_0005BB87:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 1u) goto label_0005BBDB;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x88u)) goto label_0005BBAB;
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BBABu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BBABu));
    label_0005BBAB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint8_t*)(cpu->edx + cpu->esi) = 2u;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x50u)) goto label_0005BBC7;
    cpu->edx = cpu->esp + 0x4Cu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5BBC7u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x5BBC7u));
    label_0005BBC7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ebx;
    label_0005BBDB:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x24u)) goto label_0005BB70;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    label_0005BBE6:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_0005B910;
    label_0005BBEF:
    if ((--*(uint32_t*)(cpu->esp + 0x34u)) != 0u) goto label_0005B813;
    label_0005BBF9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    *(uint8_t*)(cpu->esp + 0xCCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BC14u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45BC14u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, 0x73u);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\arrays.h";
    *(uint32_t*)(cpu->esp + 0xCCu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BC2Fu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x45BC2Fu));
    cpu->eax = 1u;
    label_0005BC34:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB8u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCD3u)); sfera_sub_00459370(cpu, LIFT_CODE_TOKEN_VA(0x45BCD3u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCD8u)); sfera_sub_004980F0(cpu, LIFT_CODE_TOKEN_VA(0x45BCD8u));
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCE2u)); sfera_sub_0048DA70(cpu, LIFT_CODE_TOKEN_VA(0x45BCE2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCE7u)); sfera_sub_00457490(cpu, LIFT_CODE_TOKEN_VA(0x45BCE7u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BCECu)); sfera_sub_00451E00(cpu, LIFT_CODE_TOKEN_VA(0x45BCECu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BDBBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x45BDBBu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BE00u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x45BE00u));
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
__declspec(noinline) void sfera_sub_0045BE50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->ebx = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)&g_sfera_texture_cache_runtime.entries[0].kind;
    label_0005BE76:
    if (*(uint32_t*)(cpu->ecx + 0xFFFFFFFCu) != cpu->eax) goto label_0005BE86;
    cpu->esi = *(uint8_t*)(cpu->ecx);
    if (cpu->esi == cpu->ebx) goto label_0005BF04;
    label_0005BE86:
    cpu->ecx += 0x10u;
    ++cpu->edx;
    if ((int32_t)(cpu->ecx) < (int32_t)((uint32_t)((uintptr_t)&g_sfera_texture_cache_runtime.entries[kTextureCacheEntryCount] + offsetof(SferaTextureCacheEntry, kind)))) goto label_0005BE76;
    cpu->edx = 0u;
    cpu->esi = cpu->edx + 1u;
    cpu->ecx = 0x10u;
    lift_push32(cpu, cpu->ebp);
    label_0005BEA0:
    cpu->ebp = *(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count));
    if (cpu->ebp <= *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count))) goto label_0005BEB2;
    cpu->edx = cpu->esi;
    cpu->edi = cpu->ecx;
    label_0005BEB2:
    cpu->ecx += 0x10u;
    ++cpu->esi;
    if ((int32_t)(cpu->ecx) < (int32_t)(0x320u)) goto label_0005BEA0;
    cpu->edx <<= 4u;
    cpu->ecx = cpu->edx;
    *(uint8_t*)(cpu->ecx + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].kind)) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].owner)) = cpu->eax;
    *(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count)) = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->ebx * 2u) + 0x18u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->edx = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].resource));
    cpu->ebx = cpu->ebx + (cpu->ebx * 8u);
    cpu->ebx <<= 6u;
    cpu->ebx += *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->edx += 0x21u;
    cpu->ecx=0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    goto label_0005BF3C;
    label_0005BF04:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    cpu->edx <<= 4u;
    cpu->esi = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45BF1Cu)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x45BF1Cu));
    *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].use_count)) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005BF34:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    label_0005BF3C:
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->esi <<= 8u;
    cpu->edi = *(uint8_t*)(cpu->ecx + cpu->esi + ((uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_a[0]));
    cpu->ecx += cpu->esi;
    cpu->eax <<= 8u;
    cpu->esi = cpu->eax + ((uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_b[0]);
    cpu->eax = cpu->eax + ((uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_a[0]);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->esi = *(uint8_t*)(cpu->ecx + ((uintptr_t)&g_sfera_static_render_lookup_runtime.quantization_b[0]));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    cpu->eax += cpu->eax;
    cpu->esi <<= 8u;
    cpu->eax += cpu->eax;
    cpu->esi += ((uintptr_t)&g_sfera_static_render_lookup_runtime.blend_lut[0]);
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = 0x40u;
    goto label_0005BF98;
    label_0005BF90:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0005BF98:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint8_t*)(cpu->ecx);
    cpu->ebp = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 2u);
    cpu->edi = cpu->esi + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint8_t*)(cpu->ecx);
    cpu->ecx += cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->ecx + cpu->ebx + 0x19u);
    cpu->ecx += cpu->ebx;
    cpu->ebx = *(uint8_t*)(cpu->edi + 3u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = *(uint8_t*)(cpu->edi + 1u);
    cpu->edi = *(uint8_t*)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = *(uint8_t*)(cpu->ecx + 1u);
    cpu->ecx = *(uint8_t*)(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->eax += cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 8u;
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0005BFEE;
    cpu->eax = 0xFFu;
    label_0005BFEE:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->eax + 1u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 3u);
    cpu->ebp = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 2u);
    cpu->edi = cpu->esi + (cpu->ecx * 4u);
    cpu->ecx = *(uint8_t*)(cpu->eax + 1u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint8_t*)(cpu->ecx + 0x19u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = *(uint8_t*)(cpu->edi + 1u);
    cpu->edi = *(uint8_t*)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = *(uint8_t*)(cpu->ecx + 1u);
    cpu->ecx = *(uint8_t*)(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->eax += cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 8u;
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0005C055;
    cpu->eax = 0xFFu;
    label_0005C055:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 2u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->edx + 2u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->eax + 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 3u);
    cpu->ebp = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 2u);
    cpu->edi = cpu->esi + (cpu->ecx * 4u);
    cpu->ecx = *(uint8_t*)(cpu->eax + 2u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint8_t*)(cpu->ecx + 0x19u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = *(uint8_t*)(cpu->edi + 1u);
    cpu->edi = *(uint8_t*)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = *(uint8_t*)(cpu->ecx + 1u);
    cpu->ecx = *(uint8_t*)(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->eax += cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 8u;
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0005C0BE;
    cpu->eax = 0xFFu;
    label_0005C0BE:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 4u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->edx + 4u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->eax + 3u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 3u);
    cpu->ebp = *(uint8_t*)(cpu->esi + (cpu->ecx * 4u) + 2u);
    cpu->edi = cpu->esi + (cpu->ecx * 4u);
    cpu->ecx = *(uint8_t*)(cpu->eax + 3u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint8_t*)(cpu->ecx + 0x19u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->ecx + 0x18u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ebp = *(uint8_t*)(cpu->edi + 1u);
    cpu->edi = *(uint8_t*)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->ebx = *(uint8_t*)(cpu->ecx + 1u);
    cpu->ecx = *(uint8_t*)(cpu->ecx);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(cpu->ebp);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->eax += cpu->ebx;
    cpu->eax += cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 8u;
    if ((int32_t)cpu->eax <= (int32_t)0xFFu) goto label_0005C127;
    cpu->eax = 0xFFu;
    label_0005C127:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 6u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFu))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->eax = 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint8_t*)(cpu->edx + 6u) = cpu->ecx & 0xFFu;
    cpu->edx += 8u;
    if ((--*(uint32_t*)(cpu->esp + 0x24u)) != 0u) goto label_0005BF90;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->ecx;
    cpu->ebx = 0x100u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if ((int32_t)(cpu->ecx) < (int32_t)(cpu->ebx)) goto label_0005BF34;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x5C182u));
    cpu->eax = *(uint32_t*)(cpu->ebp + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x44u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5C197u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->edx != 0u) goto label_0005C1AB;
    cpu->ecx = (uintptr_t)"BeginDraw has returned NULL";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5C1ABu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5C1ABu));
    label_0005C1AB:
    if (*(uint32_t*)(cpu->esp + 0x54u) != cpu->ebx) goto label_0005C21D;
    if (*(uint32_t*)(cpu->esp + 0x58u) != cpu->ebx) goto label_0005C21D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0x18u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].resource));
    cpu->eax += 0x20u;
    label_0005C1D1:
    cpu->esi = cpu->eax;
    cpu->edi = cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),512u); cpu->esi += 512u; cpu->edi += 512u; cpu->ecx = 0u;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax += 0x200u;
    if ((--cpu->ebx) != 0u) goto label_0005C1D1;
    cpu->eax = *(uint32_t*)(cpu->ebp + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x50u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x5C1F5u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + ((uintptr_t)&g_sfera_texture_cache_runtime.entries[0].resource));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C20Au)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x45C20Au));
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005C21D:
    cpu->ecx = (uintptr_t)"BeginDraw has returned texture size != 256x256";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C227u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45C227u));
    lift_trap(cpu, 0x45C227u, "INT3"); return;
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C37Du)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45C37Du));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45C457u)); sfera_sub_00451A40(cpu, LIFT_CODE_TOKEN_VA(0x45C457u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    if (cpu->ebp != 0u) goto label_0005CAAF;
    lift_push32(cpu, 2u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CA82u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x45CA82u));
    cpu->ecx = (uintptr_t)"sun";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CA8Cu)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x45CA8Cu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CA99u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x45CA99u));
    cpu->ecx = (uintptr_t)"sun";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CAA3u)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_VA(0x45CAA3u));
    g_sfera_recovered_static_runtime.scene_state_09 = 1u;
    goto label_0005CADA;
label_0005CAAF:
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CAB8u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x45CAB8u));
    cpu->ecx = (uintptr_t)"moon";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CAC2u)); sfera_sub_0049A4A0(cpu, LIFT_CODE_TOKEN_VA(0x45CAC2u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CAD0u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x45CAD0u));
    cpu->ecx = (uintptr_t)"moon";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5CADAu)); sfera_sub_0049A4C0(cpu, LIFT_CODE_TOKEN_RVA(0x5CADAu));
label_0005CADA:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CAEAu)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x45CAEAu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CB06u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x45CB06u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CB11u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x45CB11u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CB7Du)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45CB7Du));
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
    lift_trap(cpu, 0x45CBACu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0045CBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_model_registry_runtime.sentinel;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->eax) goto label_0005CC2A;
    label_0005CBC0:
    cpu->eax = cpu->esi + 0xCu;
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_0005CBCB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0005CBCB:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s\t%d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CBDAu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x45CBDAu));
    cpu->esp += 0xCu;
    if (*(uint8_t*)(cpu->esi + 0x2Du) != 0u) goto label_0005CC22;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0005CC02;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0005CC22;
    label_0005CBF6:
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0005CBF6;
    goto label_0005CC22;
    label_0005CC02:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) != 0u) goto label_0005CC20;
    label_0005CC10:
    if (cpu->esi != *(uint32_t*)(cpu->eax + 8u)) goto label_0005CC20;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x2Du) == 0u) goto label_0005CC10;
    label_0005CC20:
    cpu->esi = cpu->eax;
    label_0005CC22:
    if (cpu->esi != g_sfera_model_registry_runtime.sentinel) goto label_0005CBC0;
    label_0005CC2A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CCF0u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45CCF0u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CDFDu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45CDFDu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CE3Du)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45CE3Du));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45CF7Fu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45CF7Fu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D09Fu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45D09Fu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D1BFu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45D1BFu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D2FFu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45D2FFu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D43Fu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45D43Fu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D54Eu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45D54Eu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D5C7u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45D5C7u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D7F4u)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x45D7F4u));
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
__declspec(noinline) void sfera_sub_0045D840(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edi);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->edx = 2u;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D897u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45D897u));
    x87_v0 = (double)*(float*)(cpu->esi + 0x24u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 4u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = 3u;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D8EFu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45D8EFu));
    x87_v0 = (double)*(float*)(cpu->esi + 0x3Cu);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esi + 0x40u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 4u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 0x44u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = 4u;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45D947u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45D947u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    cpu->esi = cpu->esp + 0x24u;
    cpu->ebx = 3u;
    label_0005D964:
    *(float*)(cpu->esp + 0x18u) = (fabs(((double)*(float*)(cpu->esi + 0xFFFFFFFCu))));
    { const double lift_left=(double)*(float*)(cpu->esp + 0x18u); const double lift_right=0.800000011920929; if (lift_left>lift_right) goto label_0005DA36; }
    cpu->eax = g_sfera_window_runtime.clip_vector_count;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    g_sfera_window_runtime.clip_vector_count = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0005D99D;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D99Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5D99Du));
    label_0005D99D:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity) goto label_0005D9B1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D9B1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D9B1u));
    label_0005D9B1:
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFF8u);
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = g_sfera_window_runtime.clip_vector_count;
    cpu->edi = cpu->eax;
    ++cpu->eax;
    g_sfera_window_runtime.clip_vector_count = cpu->eax;
    if ((int32_t)cpu->edi >= 0) goto label_0005D9E8;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D9E8u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5D9E8u));
    label_0005D9E8:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_scene_array_runtime.clip_vectors.capacity) goto label_0005D9FC;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.clip_vectors.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5D9FCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5D9FCu));
    label_0005D9FC:
    x87_v0 = (double)*(float*)(cpu->esi + 0xFFFFFFF8u);
    cpu->ecx = g_sfera_scene_array_runtime.clip_vectors.data;
    x87_v0 = -x87_v0;
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esi + 0xFFFFFFFCu);
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    x87_v0 = -x87_v0;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    x87_v0 = -x87_v0;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    label_0005DA36:
    cpu->esi += 0xCu;
    if ((--cpu->ebx) != 0u) goto label_0005D964;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045DA60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi >= 0) goto label_0005DA80;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DA80u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5DA80u));
    label_0005DA80:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005DA94;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5DA94u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5DA94u));
    label_0005DA94:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ebx = cpu->esi + 0x3Cu;
    if (*(uint8_t*)(cpu->esi + 0x138u) != 1u) goto label_0005DB52;
    { const double lift_right=(double)*(float*)(cpu->esi + 8u); const double lift_left=(double)*(float*)(cpu->esi + 0x2D8u); if (lift_left!=lift_right) goto label_0005DB1C; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0xCu); const double lift_left=(double)*(float*)(cpu->esi + 0x2DCu); if (lift_left!=lift_right) goto label_0005DB1C; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x10u); const double lift_left=(double)*(float*)(cpu->esi + 0x2E0u); if (lift_left!=lift_right) goto label_0005DB1C; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x14u); const double lift_left=(double)*(float*)(cpu->esi + 0x2E4u); if (lift_left!=lift_right) goto label_0005DB1C; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + 0x2E8u); if (lift_left!=lift_right) goto label_0005DB1C; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x1Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x2ECu); if (lift_left==lift_right) goto label_0005DC42; }
    label_0005DB1C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x2D8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x2DCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->esi + 0x2E0u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x2E4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2E8u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2ECu) = cpu->eax;
    label_0005DB52:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DB62u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45DB62u));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x6Cu);
    if (cpu->eax == 0u) goto label_0005DBD5;
    if (cpu->eax == 3u) goto label_0005DBD5;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DB7Du)); sfera_sub_0044E2B0(cpu, LIFT_CODE_TOKEN_VA(0x45DB7Du));
    cpu->esi = cpu->ebx + 0x58u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    cpu->edi += 0x88u;
    cpu->ebp = 8u;
    (void)cpu;
    label_0005DB90:
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DBA9u)); sfera_sub_0041AE60(cpu, LIFT_CODE_TOKEN_VA(0x45DBA9u));
    cpu->edi += 0xCu;
    cpu->esi += 0xCu;
    if ((--cpu->ebp) != 0u) goto label_0005DB90;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->ebx + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebx + 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45DBC2u)); sfera_sub_0044F870(cpu, LIFT_CODE_TOKEN_VA(0x45DBC2u));
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005DBD5:
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->edi + 0x70u))) + (((double)*(float*)(cpu->esi + 8u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->edi + 0x74u))) + (((double)*(float*)(cpu->esi + 0xCu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x78u);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x10u)));
    *(uint32_t*)(cpu->ebx + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x44u) = cpu->ecx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebx + 0x48u) = cpu->edx;
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esi + 8u))) + (((double)*(float*)(cpu->edi + 0x7Cu))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->edi + 0x80u))) + (((double)*(float*)(cpu->esi + 0xCu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x84u);
    cpu->edi = lift_pop32(cpu);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x10u)));
    *(uint32_t*)(cpu->ebx + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0x50u) = cpu->ecx;
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->ebx + 0x54u) = cpu->edx;
    label_0005DC42:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
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
    lift_trap(cpu, 0x45DCC4u, "INT3"); return;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    ++cpu->edx;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E132u)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x45E132u));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E365u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x45E365u));
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E4EFu)); sfera_sub_004D8970(cpu, LIFT_CODE_TOKEN_VA(0x45E4EFu));
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
__declspec(noinline) void sfera_sub_0045E660(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->edi + 0xCu);
    cpu->esp -= 0xCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi)));
    cpu->eax = cpu->esp;
    cpu->esi = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 4u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 8u)));
    cpu->edx = 6u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E6ADu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45E6ADu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E6DFu)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E6DFu));
    if (cpu->eax != 0u) goto label_0005E6EB;
    label_0005E6E3:
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005E6EB:
    x87_v0 = (double)*(float*)(cpu->edi + 0x24u);
    cpu->esp -= 0xCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi)));
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x28u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 4u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x2Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 8u)));
    cpu->edx = 7u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E72Fu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45E72Fu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E761u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E761u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    x87_v0 = (double)*(float*)(cpu->edi + 0x3Cu);
    cpu->esp -= 0xCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi)));
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x40u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 4u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x44u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->edi + 8u)));
    cpu->edx = 8u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E7ADu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45E7ADu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E7DFu)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E7DFu));
    if (cpu->eax == 0u) goto label_0005E6E3;
    x87_v0 = (double)*(float*)(cpu->esi + 0xCu);
    cpu->esp -= 0xCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->edx = 9u;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E82Bu)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45E82Bu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E85Du)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E85Du));
    if (cpu->eax == 0u) goto label_0005E6E3;
    x87_v0 = (double)*(float*)(cpu->esi + 0x24u);
    cpu->esp -= 0xCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x2Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->edx = 0xAu;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E8A9u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45E8A9u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E8DBu)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E8DBu));
    if (cpu->eax == 0u) goto label_0005E6E3;
    x87_v0 = (double)*(float*)(cpu->esi + 0x3Cu);
    cpu->esp -= 0xCu;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->eax = cpu->esp;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x40u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 4u)));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v0 = (double)*(float*)(cpu->esi + 0x44u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 8u)));
    cpu->edx = 0xBu;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E927u)); sfera_sub_0045A8E0(cpu, LIFT_CODE_TOKEN_VA(0x45E927u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E959u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E959u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E973u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45E973u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E991u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E991u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E9ABu)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45E9ABu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E9C9u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45E9C9u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45E9E3u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45E9E3u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EA01u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EA01u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EA1Bu)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45EA1Bu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EA39u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EA39u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EA53u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45EA53u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EA71u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EA71u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EA8Bu)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45EA8Bu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EAA9u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EAA9u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EAC3u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45EAC3u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EAE1u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EAE1u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EAFBu)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45EAFBu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EB19u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EB19u));
    if (cpu->eax == 0u) goto label_0005E6E3;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EB33u)); sfera_sub_0044C1D0(cpu, LIFT_CODE_TOKEN_VA(0x45EB33u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EB51u)); sfera_sub_0044FA70(cpu, LIFT_CODE_TOKEN_VA(0x45EB51u));
    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_0045ED20(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if ((int32_t)cpu->edi >= 0) goto label_0005ED44;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ED44u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5ED44u));
    label_0005ED44:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005ED58;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ED58u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5ED58u));
    label_0005ED58:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (*(uint8_t*)(cpu->esi + 0x138u) != 1u) goto label_0005EE13;
    { const double lift_right=(double)*(float*)(cpu->esi + 8u); const double lift_left=(double)*(float*)(cpu->esi + 0x2B4u); if (lift_left!=lift_right) goto label_0005EDDD; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0xCu); const double lift_left=(double)*(float*)(cpu->esi + 0x2B8u); if (lift_left!=lift_right) goto label_0005EDDD; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x10u); const double lift_left=(double)*(float*)(cpu->esi + 0x2BCu); if (lift_left!=lift_right) goto label_0005EDDD; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x14u); const double lift_left=(double)*(float*)(cpu->esi + 0x2C0u); if (lift_left!=lift_right) goto label_0005EDDD; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x18u); const double lift_left=(double)*(float*)(cpu->esi + 0x2C4u); if (lift_left!=lift_right) goto label_0005EDDD; }
    { const double lift_right=(double)*(float*)(cpu->esi + 0x1Cu); const double lift_left=(double)*(float*)(cpu->esi + 0x2C8u); if (lift_left==lift_right) goto label_0005EF02; }
    label_0005EDDD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esi + 0x2B4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esi + 0x2B8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->esi + 0x2BCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x2C0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2C4u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x2C8u) = cpu->eax;
    label_0005EE13:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EE1Cu)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x45EE1Cu));
    x87_v0 = (double)*(float*)(cpu->esi + 0x7Cu);
    x87_v1 = 2.0;
    x87_v0 = (x87_v0) - (x87_v1);
    x87_v2 = 0.11999999731779099;
    x87_v0 = (x87_v0) * (x87_v2);
    x87_v3 = 100000.0;
    x87_v0 = (x87_v0) + (x87_v3);
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    x87_v3 = (double)*(float*)(cpu->esi + 0x84u);
    x87_v3 = (x87_v3) - (x87_v1);
    cpu->ebp = cpu->eax + 0xFFFE7960u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v3 = (x87_v3) + (x87_v0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    x87_v3 = (double)*(float*)(cpu->esi + 0x88u);
    x87_v3 = (x87_v3) + (x87_v1);
    cpu->eax -= 0x186A0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v3 = (x87_v3) * (x87_v2);
    x87_v3 = (x87_v3) + (x87_v0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    x87_v3 = (double)*(float*)(cpu->esi + 0x90u);
    x87_v1 = x87_v1 + x87_v3; 
    cpu->edi = cpu->eax + 0xFFFE7960u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    x87_v1 = x87_v1 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->ebx = cpu->eax + 0xFFFE7960u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == 0xF4240u) goto label_0005EEBE;
    if (cpu->eax != cpu->ebp) goto label_0005EEB5;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->esi + 0x2Cu) != cpu->ecx) goto label_0005EEB5;
    if (*(uint32_t*)(cpu->esi + 0x28u) != cpu->edi) goto label_0005EEB5;
    if (*(uint32_t*)(cpu->esi + 0x30u) == cpu->ebx) goto label_0005EF00;
    label_0005EEB5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EEBEu)); sfera_sub_00455D80(cpu, LIFT_CODE_TOKEN_RVA(0x5EEBEu));
    label_0005EEBE:
    ++g_sfera_world_load_runtime.live_object_count;
    if ((int32_t)cpu->ebp > (int32_t)cpu->edi) goto label_0005EEF0;
    label_0005EEC8:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0005EEE1;
    label_0005EED0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45EEDCu)); sfera_sub_004898B0(cpu, LIFT_CODE_TOKEN_VA(0x45EEDCu));
    ++cpu->edi;
    if ((int32_t)cpu->edi <= (int32_t)cpu->ebx) goto label_0005EED0;
    label_0005EEE1:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp <= (int32_t)*(uint32_t*)(cpu->esp + 0x18u)) goto label_0005EEC8;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0005EEF0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    label_0005EF00:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0005EF02:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_world_objects.extended_object_count;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = 0u;
    if ((int32_t)cpu->ebp <= 0) goto label_0005F007;
    lift_push32(cpu, cpu->esi);
    label_0005EF50:
    if ((int32_t)cpu->edi >= 0) goto label_0005EF5E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EF5Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EF5Eu));
    label_0005EF5E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_0005EF72;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EF72u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EF72u));
    label_0005EF72:
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) != 0u) goto label_0005EF80;
    ++cpu->edi;
    goto label_0005EF50;
    label_0005EF80:
    if ((int32_t)cpu->edi >= 0) goto label_0005EF8E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EF8Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EF8Eu));
    label_0005EF8E:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_0005EFA2;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EFA2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EFA2u));
    label_0005EFA2:
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    if ((int32_t)cpu->esi >= 0) goto label_0005EFB9;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EFB9u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5EFB9u));
    label_0005EFB9:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005EFCD;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EFCDu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5EFCDu));
    label_0005EFCD:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (cpu->eax == 0u) goto label_0005EFE3;
    if (*(uint8_t*)(cpu->eax + 0x138u) == 0u) goto label_0005F01F;
    label_0005EFE3:
    if (*(uint8_t*)(cpu->eax + 0x141u) == 0u) goto label_0005EFFC;
    if (*(uint32_t*)(cpu->eax + 0x184u) != 0u) goto label_0005EFFC;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5EFFCu)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_RVA(0x5EFFCu));
    label_0005EFFC:
    ++cpu->ebx;
    ++cpu->edi;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_0005EF50;
    cpu->esi = lift_pop32(cpu);
    label_0005F007:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005F01F:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F02Eu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45F02Eu));
    if (cpu->eax != 0u) goto label_0005F037;
    cpu->eax = (uintptr_t)"<none>";
    label_0005F037:
    lift_push32(cpu, 0x31AEu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45F04Cu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F05Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x45F05Eu));
    lift_trap(cpu, 0x45F05Eu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0045F060(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x64u;
    sub_pred[0] = (uint32_t)(g_sfera_client_config_runtime.state_15) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if (sub_pred[0]) goto label_0005F744;
    if (cpu->esi == g_sfera_world_objects.controlled_object_handle) goto label_0005F744;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F092u)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x45F092u));
    if ((int32_t)cpu->esi >= 0) goto label_0005F0A0;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F0A0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5F0A0u));
    label_0005F0A0:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005F0B4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F0B4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5F0B4u));
    label_0005F0B4:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F0CBu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45F0CBu));
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x6Cu);
    if (cpu->eax == 1u) goto label_0005F0DE;
    if (cpu->eax != 2u) goto label_0005F44D;
    label_0005F0DE:
    cpu->edi = 0xFF00FF00u;
    if (cpu->eax != 2u) goto label_0005F0ED;
    cpu->edi = 0xFFFF0000u;
    label_0005F0ED:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x94u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x98u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F135u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F135u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xACu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F17Du)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F17Du));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xBCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xACu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F1C5u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F1C5u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x94u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x98u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xBCu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F20Du)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F20Du));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F255u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F255u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD0u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F29Du)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F29Du));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xE8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xDCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xE0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F2E5u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F2E5u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F32Du)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F32Du));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC8u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCCu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xBCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F375u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F375u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x94u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x98u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F3BDu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F3BDu));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xDCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xE4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA0u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F405u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F405u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0xE8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xACu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB0u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F44Du)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x5F44Du));
    label_0005F44D:
    if (*(uint32_t*)(cpu->ebx + 0x6Cu) != 0u) goto label_0005F73A;
    cpu->ecx = cpu->esi + 0x7Cu;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F463u)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x45F463u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F4A2u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F4A2u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F4D5u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F4D5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F514u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F514u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F54Fu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F54Fu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F58Eu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F58Eu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F5CDu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F5CDu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F60Cu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F60Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x70u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F64Eu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F64Eu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F68Du)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F68Du));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F6C8u)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F6C8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F6FBu)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_VA(0x45F6FBu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x78u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->ecx = 0xFF0000FFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F73Au)); sfera_sub_0045ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x5F73Au));
    label_0005F73A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F73Fu)); sfera_sub_00451EB0(cpu, LIFT_CODE_TOKEN_VA(0x45F73Fu));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F744u)); sfera_sub_00451E00(cpu, LIFT_CODE_TOKEN_RVA(0x5F744u));
    label_0005F744:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045F760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_0005F8A9;
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F79C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F797u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x45F797u));
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F79C:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) == 0u) goto label_0005F8A9;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F7C1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F7BCu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x45F7BCu));
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F7C1:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->ecx + 0x138u) != 0u) goto label_0005F814;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F7E3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F7E3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5F7E3u));
    label_0005F7E3:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005F814:
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F824;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F824u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5F824u));
    label_0005F824:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005F861;
    label_0005F830:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x190u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x194u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x198u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005F861:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005F830;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F879u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45F879u));
    if (cpu->eax != 0u) goto label_0005F882;
    cpu->eax = (uintptr_t)"<none>";
    label_0005F882:
    lift_push32(cpu, 0x3897u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45F897u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F8A9u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5F8A9u));
    label_0005F8A9:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005F8B7:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005F8B7;
    cpu->esi = (uintptr_t)"GetHandPosL: wrong handle";
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),26u); cpu->esi += 26u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F8D2u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45F8D2u));
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005F8EA;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F8EAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5F8EAu));
    label_0005F8EA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x408u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045F920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_0005FA69;
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F95C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F957u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x45F957u));
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F95C:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) == 0u) goto label_0005FA69;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F981;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45F97Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x45F97Cu));
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005F981:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->ecx + 0x138u) != 0u) goto label_0005F9D4;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F9A3;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F9A3u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5F9A3u));
    label_0005F9A3:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005F9D4:
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005F9E4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5F9E4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5F9E4u));
    label_0005F9E4:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005FA21;
    label_0005F9F0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x19Cu);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1A0u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1A4u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005FA21:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005F9F0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FA39u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45FA39u));
    if (cpu->eax != 0u) goto label_0005FA42;
    cpu->eax = (uintptr_t)"<none>";
    label_0005FA42:
    lift_push32(cpu, 0x38A0u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FA57u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FA69u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5FA69u));
    label_0005FA69:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005FA77:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005FA77;
    cpu->esi = (uintptr_t)"GetHandPosR: wrong handle";
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),26u); cpu->esi += 26u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FA92u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45FA92u));
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005FAAA;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FAAAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FAAAu));
    label_0005FAAA:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x408u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045FAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_0005FC29;
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005FB1C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FB17u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x45FB17u));
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005FB1C:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) == 0u) goto label_0005FC29;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005FB41;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FB3Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x45FB3Cu));
    cpu->eax = g_sfera_world_objects.object_handles.capacity;
    label_0005FB41:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->ecx + 0x138u) != 0u) goto label_0005FB94;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005FB63;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FB63u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FB63u));
    label_0005FB63:
    cpu->edx = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005FB94:
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0005FBA4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FBA4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FBA4u));
    label_0005FBA4:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005FBE1;
    label_0005FBB0:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x228u);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x22Cu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x230u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005FBE1:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005FBB0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FBF9u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45FBF9u));
    if (cpu->eax != 0u) goto label_0005FC02;
    cpu->eax = (uintptr_t)"<none>";
    label_0005FC02:
    lift_push32(cpu, 0x38A9u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FC17u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FC29u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5FC29u));
    label_0005FC29:
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005FC37:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005FC37;
    cpu->esi = (uintptr_t)"GetSwordPos: wrong handle";
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),26u); cpu->esi += 26u; cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FC52u)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_VA(0x45FC52u));
    cpu->edx = 1u;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_0005FC6A;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FC6Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FC6Au));
    label_0005FC6A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x408u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045FCA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_0005FD9F;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FCD7;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FCD7u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FCD7u));
    label_0005FCD7:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005FD9F;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FCFA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FCFAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FCFAu));
    label_0005FCFA:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->edx + 0x138u) == 0u) goto label_0005FDCA;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FD24;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FD24u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FD24u));
    label_0005FD24:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005FD57;
    label_0005FD30:
    cpu->esi += 0x1A8u;
    std::memmove((void*)(cpu->ebx),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005FD57:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005FD30;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FD6Fu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45FD6Fu));
    if (cpu->eax != 0u) goto label_0005FD78;
    cpu->eax = (uintptr_t)"<none>";
    label_0005FD78:
    lift_push32(cpu, 0x38BBu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FD8Du));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FD9Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5FD9Fu));
    label_0005FD9F:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005FDB0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005FDB0;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetHandOrientL: wrong handle"),29u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FDCAu)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x5FDCAu));
    label_0005FDCA:
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45FDCFu));
    x87_v0 = 1.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x418u);
    *(float*)(cpu->ebx + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->ebx + 0x28u) = x87_v0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x14u) = x87_v0;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebx) = x87_v0; 
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045FE00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_0005FEFF;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FE37;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FE37u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FE37u));
    label_0005FE37:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0005FEFF;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FE5A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FE5Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FE5Au));
    label_0005FE5A:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->edx + 0x138u) == 0u) goto label_0005FF2A;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FE84;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FE84u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FE84u));
    label_0005FE84:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0005FEB7;
    label_0005FE90:
    cpu->esi += 0x1E8u;
    std::memmove((void*)(cpu->ebx),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0005FEB7:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005FE90;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x45FECFu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x45FECFu));
    if (cpu->eax != 0u) goto label_0005FED8;
    cpu->eax = (uintptr_t)"<none>";
    label_0005FED8:
    lift_push32(cpu, 0x38C4u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x45FEEDu));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FEFFu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5FEFFu));
    label_0005FEFF:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_0005FF10:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0005FF10;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetHandOrientR: wrong handle"),29u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FF2Au)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x5FF2Au));
    label_0005FF2A:
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x45FF2Fu));
    x87_v0 = 1.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x418u);
    *(float*)(cpu->ebx + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->ebx + 0x28u) = x87_v0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x14u) = x87_v0;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebx) = x87_v0; 
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0045FF60(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    if ((int32_t)cpu->esi < 0) goto label_0006005F;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FF97;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FF97u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FF97u));
    label_0005FF97:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_0006005F;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FFBA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FFBAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FFBAu));
    label_0005FFBA:
    cpu->ecx = g_sfera_world_objects.object_handles.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->edx + 0x138u) == 0u) goto label_0006008A;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0005FFE4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5FFE4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5FFE4u));
    label_0005FFE4:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_00060017;
    label_0005FFF0:
    cpu->esi += 0x234u;
    std::memmove((void*)(cpu->ebx),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00060017:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_0005FFF0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46002Fu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x46002Fu));
    if (cpu->eax != 0u) goto label_00060038;
    cpu->eax = (uintptr_t)"<none>";
    label_00060038:
    lift_push32(cpu, 0x38CDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46004Du));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6005Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6005Fu));
    label_0006005F:
    cpu->edi = (uintptr_t)&g_sfera_window_runtime.diagnostic_message[0];
    (*(uint8_t*)(void*)&g_sfera_window_runtime.diagnostic_message[0]) = 0u;
    --cpu->edi;
    label_00060070:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00060070;
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"GetSwordOrient: wrong handle"),29u); cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6008Au)); sfera_sub_0044F500(cpu, LIFT_CODE_TOKEN_RVA(0x6008Au));
    label_0006008A:
    lift_push32(cpu, 0x40u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x46008Fu));
    x87_v0 = 1.0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x418u);
    *(float*)(cpu->ebx + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->ebx + 0x28u) = x87_v0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x14u) = x87_v0;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebx) = x87_v0; 
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004600C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->esi < 0) goto label_00060105;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_000600DB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x600DBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x600DBu));
    label_000600DB:
    cpu->eax = g_sfera_light_runtime.handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_00060105;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.handles.capacity) goto label_000600FA;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x600FAu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x600FAu));
    label_000600FA:
    cpu->ecx = g_sfera_light_runtime.handles.data;
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00060105:
    cpu->ecx = (uintptr_t)"GetLight: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46010Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x46010Fu));
    lift_trap(cpu, 0x46010Fu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00460110(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->edi != 1u) goto label_0006017E;
    if ((int32_t)cpu->esi >= 0) goto label_00060129;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60129u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x60129u));
    label_00060129:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_0006013D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6013Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6013Du));
    label_0006013D:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 1u) goto label_000601E9;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter;
    ++cpu->eax;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)8u) goto label_000601B2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ActivateLight: num of active lights > 8. Source line = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x46016Bu));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_error_message_scratch_runtime.formatted_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6017Eu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x6017Eu));
    label_0006017E:
    if ((int32_t)cpu->esi >= 0) goto label_0006018C;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6018Cu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6018Cu));
    label_0006018C:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_000601A0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x601A0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x601A0u));
    label_000601A0:
    cpu->edx = g_sfera_light_runtime.active_handles.data;
    if (*(uint32_t*)(cpu->edx + (cpu->esi * 4u)) == 0u) goto label_000601E9;
    g_sfera_main_command_state_runtime.light_update_counter = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.light_update_counter)) - 1u;
    label_000601B2:
    if ((int32_t)cpu->esi >= 0) goto label_000601C0;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x601C0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x601C0u));
    label_000601C0:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_light_runtime.active_handles.capacity) goto label_000601D4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_light_runtime.active_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x601D4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x601D4u));
    label_000601D4:
    cpu->eax = g_sfera_light_runtime.active_handles.data;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = cpu->edi;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x601E9u)); sfera_sub_004D8C60(cpu, LIFT_CODE_TOKEN_RVA(0x601E9u));
    label_000601E9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004601F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    cpu->esi = (uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    label_00060202:
    cpu->ebx = cpu->ecx;
    cpu->ebp = 0x50u;
    label_00060210:
    *(uint16_t*)(cpu->esi + 0x14u) = 0u;
    if (*(uint8_t*)(cpu->ebx) != 0u) goto label_0006022D;
    cpu->eax = *(uint32_t*)((uintptr_t)"fill");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"fill") + 4u));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint8_t*)(cpu->esi + 4u) = cpu->edx & 0xFFu;
    goto label_00060241;
    label_0006022D:
    cpu->edi = cpu->esi;
    cpu->eax = cpu->ebx;
    cpu->edi -= cpu->ebx;
    label_00060233:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edi + cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00060233;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    label_00060241:
    cpu->esi += 0x16u;
    cpu->ebx += 0x6E0u;
    if ((--cpu->ebp) != 0u) goto label_00060210;
    cpu->ecx += 0x16u;
    if ((int32_t)cpu->esi < (int32_t)((uintptr_t)&g_sfera_landscape_map_runtime.records[kLandscapeMapRecordCount])) goto label_00060202;
    cpu->eax = cpu->edi + 0x14u;
    cpu->edi -= cpu->eax;
    cpu->ecx = cpu->edi + 0x15u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    label_00060270:
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    label_00060276:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    if ((cpu->eax & 0xFFu) != 1u) goto label_00060285;
    if (*(uint8_t*)(cpu->ecx + cpu->edi) == (cpu->eax & 0xFFu)) goto label_0006031D;
    label_00060285:
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0006031D;
    cpu->ebp += cpu->edx;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x16u);
    cpu->edx = cpu->ebp + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0].tile_x);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    label_000602A8:
    cpu->ebx = 0u;
    if (*(uint8_t*)(cpu->ecx + cpu->edi) <= (cpu->ebx & 0xFFu)) goto label_000602F7;
    cpu->ebp = cpu->ebp + ((uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->ecx = 0xFFFFFFECu;
    cpu->ecx -= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    goto label_000602C6;
    label_000602C2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    label_000602C6:
    cpu->eax = cpu->ebp;
    cpu->esi = cpu->edx + cpu->ecx;
    label_000602D0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000602D0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x10u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->edx + 1u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    cpu->eax = *(uint8_t*)(cpu->ecx + cpu->edi);
    ++cpu->ebx;
    cpu->edx -= 0x16u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->eax) goto label_000602C2;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000602F7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint8_t*)(cpu->edi);
    ++cpu->eax;
    cpu->edx += 0x6E0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)cpu->esi) goto label_000602A8;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0006031D:
    ++cpu->edx;
    cpu->edi += 0x6E0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)0x50u) goto label_00060276;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += 0x50u;
    cpu->edi += 0x16u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)0x1900u) goto label_00060270;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    label_00060355:
    cpu->ebx = 0u;
    label_00060360:
    cpu->esi = 0u;
    cpu->edi = 0u;
    label_00060364:
    if ((int32_t)(cpu->esi) >= (int32_t)((uint32_t)(g_sfera_recovered_static_runtime.font_renderer_state))) goto label_0006043F;
    if ((int32_t)cpu->esi >= 0) goto label_0006037E;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6037Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6037Eu));
    label_0006037E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_00060392;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60392u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x60392u));
    label_00060392:
    cpu->ecx = g_sfera_landscape_runtime.file_records.data;
    cpu->edx = cpu->ebx + cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16u);
    cpu->edx += ((uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->eax = cpu->edi + cpu->ecx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4603A9u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000603BF;
    ++cpu->esi;
    cpu->edi += 0x6CCu;
    goto label_00060364;
    label_000603BF:
    if ((int32_t)cpu->esi >= 0) goto label_000603CD;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x603CDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x603CDu));
    label_000603CD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_landscape_runtime.file_records.capacity) goto label_000603E1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_landscape_runtime.file_records.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x603E1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x603E1u));
    label_000603E1:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x6CCu);
    cpu->esi += g_sfera_landscape_runtime.file_records.data;
    cpu->eax = cpu->ebx + cpu->ebp;
    ++cpu->ebx;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_landscape_patch_lookup_runtime.patch_records[0])) = cpu->esi;
    if ((int32_t)cpu->ebx < (int32_t)0x50u) goto label_00060360;
    ++*(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 0x50u;
    if ((int32_t)cpu->ebp < (int32_t)0x1900u) goto label_00060355;
    cpu->ecx = (uintptr_t)"landscape\\map.bin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46041Eu)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x46041Eu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x22600u);
    cpu->edx = (uintptr_t)&g_sfera_landscape_map_runtime.records[0];
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460431u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x460431u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    sfera_sub_0042F180(cpu, stop_address); return;
    label_0006043F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->edx <<= 4u;
    cpu->edx += cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16u);
    cpu->edx += ((uintptr_t)&g_sfera_landscape_map_runtime.records[0]);
    cpu->ecx = (uintptr_t)"Patch present in map, but not found in \\landscape. Name: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46045Eu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_VA(0x46045Eu));
    lift_trap(cpu, 0x46045Eu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00460460(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_client_main_scalar_runtime.state_07;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi * 8u;
    cpu->edi -= cpu->esi;
    ++cpu->esi;
    cpu->eax = cpu->edx;
    cpu->edi = (cpu->edi * 8u) + ((uintptr_t)&g_sfera_recovered_static_runtime.grass_patterns[0].id);
    g_sfera_client_main_scalar_runtime.state_07 = cpu->esi;
    if ((int32_t)cpu->esi <= (int32_t)0x1Eu) goto label_00060490;
    cpu->ecx = (uintptr_t)"GRASS_PATTERNS_NUM exeeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60490u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x60490u));
    label_00060490:
    cpu->esi = cpu->edi + 4u;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->esi -= cpu->eax;
    label_00060497:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00060497;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->edi + 9u;
    cpu->edx -= cpu->eax;
    label_000604B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000604B0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->edi + 0xEu;
    cpu->edx -= cpu->eax;
    label_000604C3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000604C3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->edi + 0x13u;
    cpu->edx -= cpu->eax;
    label_000604D6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000604D6;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->edi + 0x18u;
    cpu->edx -= cpu->eax;
    label_000604F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000604F0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->edi + 0x1Du;
    cpu->edx -= cpu->eax;
    label_00060503:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00060503;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->edi + 0x22u;
    cpu->edx -= cpu->eax;
    label_00060516:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00060516;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = cpu->edi + 0x27u;
    cpu->edx -= cpu->eax;
    label_00060530:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00060530;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->edi + 0x2Cu;
    cpu->edx -= cpu->eax;
    label_00060543:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00060543;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = cpu->edi + 0x31u;
    cpu->edx -= cpu->eax;
    label_00060556:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00060556;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00460570(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"014"); lift_push32(cpu, (uintptr_t)"014"); lift_push32(cpu, (uintptr_t)"002");
    lift_push32(cpu, (uintptr_t)"002");
    cpu->edx = (uintptr_t)"002";
    cpu->ecx = 1u;
    g_sfera_client_main_scalar_runtime.state_07 = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4605B6u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4605B6u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_31"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"003"); lift_push32(cpu, (uintptr_t)"006"); lift_push32(cpu, (uintptr_t)"018");
    lift_push32(cpu, (uintptr_t)"018");
    cpu->edx = (uintptr_t)"018";
    cpu->ecx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4605F2u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4605F2u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_61"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"009"); lift_push32(cpu, (uintptr_t)"003");
    lift_push32(cpu, (uintptr_t)"003");
    cpu->edx = (uintptr_t)"003";
    cpu->ecx = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46062Eu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46062Eu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"002"); lift_push32(cpu, (uintptr_t)"002");
    lift_push32(cpu, (uintptr_t)"010");
    cpu->edx = (uintptr_t)"010";
    cpu->ecx = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46066Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46066Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"009");
    lift_push32(cpu, (uintptr_t)"009");
    cpu->edx = (uintptr_t)"009";
    cpu->ecx = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4606A6u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4606A6u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_31"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"011"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"016");
    lift_push32(cpu, (uintptr_t)"016");
    cpu->edx = (uintptr_t)"016";
    cpu->ecx = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4606E2u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4606E2u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_51"); lift_push32(cpu, (uintptr_t)"1_41"); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"007");
    lift_push32(cpu, (uintptr_t)"014");
    cpu->edx = (uintptr_t)"014";
    cpu->ecx = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46071Eu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46071Eu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"013");
    lift_push32(cpu, (uintptr_t)"013");
    cpu->edx = (uintptr_t)"013";
    cpu->ecx = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46075Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46075Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"013"); lift_push32(cpu, (uintptr_t)"003"); lift_push32(cpu, (uintptr_t)"003");
    lift_push32(cpu, (uintptr_t)"007");
    cpu->edx = (uintptr_t)"007";
    cpu->ecx = 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460796u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460796u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_31"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"003"); lift_push32(cpu, (uintptr_t)"009"); lift_push32(cpu, (uintptr_t)"009");
    lift_push32(cpu, (uintptr_t)"002");
    cpu->edx = (uintptr_t)"002";
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4607D2u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4607D2u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"013"); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"005");
    lift_push32(cpu, (uintptr_t)"012");
    cpu->edx = (uintptr_t)"012";
    cpu->ecx = 0xBu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46080Eu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46080Eu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_61"); lift_push32(cpu, (uintptr_t)"009"); lift_push32(cpu, (uintptr_t)"004"); lift_push32(cpu, (uintptr_t)"012");
    lift_push32(cpu, (uintptr_t)"012");
    cpu->edx = (uintptr_t)"012";
    cpu->ecx = 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46084Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46084Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"1_51"); lift_push32(cpu, (uintptr_t)"1_21"); lift_push32(cpu, (uintptr_t)"1_11"); lift_push32(cpu, (uintptr_t)"015"); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"007");
    lift_push32(cpu, (uintptr_t)"007");
    cpu->edx = (uintptr_t)"007";
    cpu->ecx = 0xDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460886u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460886u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"005"); lift_push32(cpu, (uintptr_t)"017");
    lift_push32(cpu, (uintptr_t)"017");
    cpu->edx = (uintptr_t)"017";
    cpu->ecx = 0xEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4608C2u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4608C2u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"007"); lift_push32(cpu, (uintptr_t)"001"); lift_push32(cpu, (uintptr_t)"001");
    lift_push32(cpu, (uintptr_t)"001");
    cpu->edx = (uintptr_t)"001";
    cpu->ecx = 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4608FEu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4608FEu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000");
    lift_push32(cpu, (uintptr_t)"000");
    cpu->edx = (uintptr_t)"000";
    cpu->ecx = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46093Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x46093Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000");
    lift_push32(cpu, (uintptr_t)"000");
    cpu->edx = (uintptr_t)"000";
    cpu->ecx = 0x11u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460976u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460976u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000"); lift_push32(cpu, (uintptr_t)"000");
    lift_push32(cpu, (uintptr_t)"000");
    cpu->edx = (uintptr_t)"000";
    cpu->ecx = 0x12u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4609B2u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4609B2u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uintptr_t)"101");
    cpu->edx = (uintptr_t)"101";
    cpu->ecx = 0x13u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4609EEu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x4609EEu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102");
    lift_push32(cpu, (uintptr_t)"102");
    cpu->edx = (uintptr_t)"102";
    cpu->ecx = 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460A2Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460A2Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uintptr_t)"100");
    cpu->edx = (uintptr_t)"100";
    cpu->ecx = 0x15u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460A66u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460A66u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uintptr_t)"101");
    cpu->edx = (uintptr_t)"101";
    cpu->ecx = 0x16u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460AA2u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460AA2u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uintptr_t)"100");
    cpu->edx = (uintptr_t)"100";
    cpu->ecx = 0x17u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460ADEu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460ADEu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uintptr_t)"100");
    cpu->edx = (uintptr_t)"100";
    cpu->ecx = 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460B1Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460B1Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uintptr_t)"100");
    cpu->edx = (uintptr_t)"100";
    cpu->ecx = 0x19u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460B56u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460B56u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uintptr_t)"101");
    cpu->edx = (uintptr_t)"101";
    cpu->ecx = 0x1Au;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460B92u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460B92u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102");
    lift_push32(cpu, (uintptr_t)"102");
    cpu->edx = (uintptr_t)"102";
    cpu->ecx = 0x1Bu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460BCEu)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460BCEu));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"101"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uintptr_t)"100");
    cpu->edx = (uintptr_t)"100";
    cpu->ecx = 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460C0Au)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460C0Au));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"101");
    lift_push32(cpu, (uintptr_t)"101");
    cpu->edx = (uintptr_t)"101";
    cpu->ecx = 0x1Du;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460C46u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460C46u));
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"102"); lift_push32(cpu, (uintptr_t)"100");
    lift_push32(cpu, (uintptr_t)"100");
    cpu->edx = (uintptr_t)"100";
    cpu->ecx = 0x1Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460C82u)); sfera_sub_00460460(cpu, LIFT_CODE_TOKEN_VA(0x460C82u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460D16u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x460D16u));
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
    lift_trap(cpu, 0x460D46u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00460D50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0, x87_v1;
    cpu->esp -= 0xA8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx = 1u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)g_sfera_world_objects.object_handles.capacity > (int32_t)cpu->edx) goto label_00060D81;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60D81u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x60D81u));
    label_00060D81:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_recovered_static_runtime.flare_clip_vector.x.u32;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = 0.0;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->ecx = g_sfera_recovered_static_runtime.flare_clip_vector.y.u32;
    x87_v0 = (x87_v0) + (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    cpu->edx = g_sfera_recovered_static_runtime.flare_clip_vector.z.u32;
    *(float*)(cpu->esp + 0x58u) = x87_v1; 
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edi;
    x87_v1 = (x87_v1) + (0.10000000149011612);
    *(float*)(cpu->esp + 0x5Cu) = x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x60u) = x87_v0; 
    if ((int32_t)cpu->esi >= 0) goto label_00060DED;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60DEDu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x60DEDu));
    label_00060DED:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_00060E01;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x60E01u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x60E01u));
    label_00060E01:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->ebx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460E1Cu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x460E1Cu));
    cpu->ebp = cpu->eax;
    cpu->ebx += 0x3Cu;
    if (*(uint32_t*)(cpu->ebp + 0x6Cu) == 3u) goto label_00061148;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint8_t*)(cpu->eax + 0x138u) != 1u) goto label_00060E45;
    if (*(uint32_t*)(cpu->eax + 0x184u) != 0u) goto label_00061148;
    label_00060E45:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460E4Cu)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x460E4Cu));
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0x6Cu) == 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    if (!sub_pred[0]) goto label_00060ED1;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = (double)*(float*)(cpu->ebx + 0x40u);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = (double)*(float*)(cpu->ebx + 0x44u);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = (double)*(float*)(cpu->ebx + 0x48u);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = (double)*(float*)(cpu->ebx + 0x4Cu);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = (double)*(float*)(cpu->ebx + 0x50u);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = (double)*(float*)(cpu->ebx + 0x54u);
    goto label_00060FDF;
    label_00060ED1:
    x87_v0 = 0.0;
    cpu->edi = cpu->esp + 0x74u;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32) = x87_v0;
    cpu->edi &= 0xFFFFFFF0u;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->ebp + 0x188u);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32) = x87_v0; 
    cpu->edx = cpu->esp + 0x20u;
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32) = (double)*(float*)(cpu->ebp + 0x18Cu);
    *(float*)((uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32) = (double)*(float*)(cpu->ebp + 0x190u);
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebx),64u);
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460F2Au)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x460F2Au));
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebp + 0x148u),64u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460F4Fu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x460F4Fu));
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebx),64u);
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460F70u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x460F70u));
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebp + 0x148u),64u);
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460F95u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x460F95u));
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebx),64u);
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460FB6u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x460FB6u));
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    cpu->esi = cpu->ebp + 0x148u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u;
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460FDBu)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x460FDBu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    label_00060FDF:
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x460FF1u)); sfera_sub_0044F740(cpu, LIFT_CODE_TOKEN_VA(0x460FF1u));
    if (cpu->eax == 0u) goto label_00061148;
    if (*(uint32_t*)(cpu->ebp + 0x6Cu) == 2u) goto label_00061006;
    label_00060FFF:
    cpu->eax = 0u;
    goto label_0006114D;
    label_00061006:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->ebx),64u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x64u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461053u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x461053u));
    cpu->edi = cpu->esp + 0x74u;
    cpu->edi &= 0xFFFFFFF0u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->edi;
    cpu->esi = cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->esi += 64u; cpu->edi += 64u;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461074u)); sfera_sub_0044B5A0(cpu, LIFT_CODE_TOKEN_VA(0x461074u));
    sub_pred[1] = *(uint32_t*)(cpu->ebp + 0x19Cu) == 0u; sub_pred[2] = (int32_t)(*(uint32_t*)(cpu->ebp + 0x19Cu)) < (int32_t)(0u);
    *(uint32_t*)(cpu->esp + 0x54u) = 0u;
    if ((sub_pred[1]) || (sub_pred[2])) goto label_00061148;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1A0u);
    cpu->eax += 8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    label_00061096:
    cpu->ebx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edi = 0u;
    if ((int32_t)cpu->ebx <= 0) goto label_0006112C;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1A4u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->ecx += cpu->ecx;
    cpu->esi = cpu->edx + (cpu->ecx * 8u) + 0x40u;
    label_000610B4:
    x87_v0 = (double)*(float*)(cpu->esi + 0xFFFFFFFCu);
    cpu->eax = cpu->esp + 0x58u;
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    lift_push32(cpu, cpu->eax);
    x87_v0 = (double)*(float*)(cpu->esi);
    cpu->ecx = cpu->esp + 0x30u;
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    cpu->edx = cpu->esp + 0x28u;
    *(float*)(cpu->esp + 0x48u) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    *(float*)(cpu->esp + 0x54u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4610E8u)); sfera_sub_00451A40(cpu, LIFT_CODE_TOKEN_VA(0x4610E8u));
    if (cpu->eax != 1u) goto label_00061120;
    cpu->ecx = cpu->esi + 0xFFFFFFD8u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0xFFFFFFE4u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    cpu->eax = cpu->esi + 0xFFFFFFF0u;
    lift_push32(cpu, 3u);
    cpu->edx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461118u)); sfera_sub_00451B40(cpu, LIFT_CODE_TOKEN_VA(0x461118u));
    if (cpu->eax != 0u) goto label_00060FFF;
    label_00061120:
    ++cpu->edi;
    cpu->esi += 0x50u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_000610B4;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_0006112C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    ++cpu->ecx;
    cpu->eax += 0xCu;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->ebp + 0x19Cu)) goto label_00061096;
    label_00061148:
    cpu->eax = 1u;
    label_0006114D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xA8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00461170(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->edi = (uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"wrong format of planting.txt\n"),30u); cpu->edi += 30u; cpu->ecx = 0u;
    cpu->ecx = cpu->ebx;
    cpu->eax = cpu->edx;
    cpu->esi = cpu->ecx;
    label_00061190:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00061190;
    cpu->ecx -= cpu->esi;
    cpu->edi = (uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    cpu->ebx = cpu->ecx;
    --cpu->edi;
    label_000611A1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000611A1;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->ebx); cpu->esi += cpu->ebx; cpu->edi += cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    --cpu->ecx;
    label_000611C0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000611C0;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx) = cpu->edx & 0xFFFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->edx & 0xFFu;
    cpu->ecx = cpu->eax;
    label_000611E0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000611E0;
    cpu->edi = (uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_000611F1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_000611F1;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_terrain_diagnostic_runtime.planting_message[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461211u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x461211u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_trap(cpu, 0x461214u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00461220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461259u)); sfera_sub_00480380(cpu, LIFT_CODE_TOKEN_VA(0x461259u));
    lift_push32(cpu, (uintptr_t)"landscape\\planting.txt");
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46126Fu)); sfera_sub_004803B0(cpu, LIFT_CODE_TOKEN_VA(0x46126Fu));
    cpu->eax = *(uint32_t*)((uintptr_t)"a00_00");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"a00_00") + 4u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"a00_00") + 6u));
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)&g_sfera_planting_table_runtime.records[0].descriptor);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, (uintptr_t)"d");
    cpu->eax = cpu->esp + 0x1Cu;
    *(uint16_t*)(cpu->esp + 0x24u) = cpu->ecx & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x303061u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint8_t*)(cpu->esp + 0x2Au) = cpu->edx & 0xFFu;
    g_sfera_window_runtime.input_state = 0u;
    *(uint16_t*)(cpu->esp + 0x25u) = 0x3030u;
    *(uint16_t*)(cpu->esp + 0x21u) = 0x3030u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4612C8u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4612C8u));
    if (cpu->eax == 0u) goto label_00061466;
    label_000612D0:
    if (cpu->eax != 1u) goto label_00061494;
    cpu->ecx = g_sfera_window_runtime.input_state;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x468u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += ((uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].name[0]);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"n");
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x1Cu;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esp + 0x28u) = 0x3030u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461309u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x461309u));
    if (cpu->eax == 0u) goto label_000613EC;
    cpu->esi = 0u;
    label_00061313:
    if (cpu->eax != 1u) goto label_000614A2;
    cpu->eax = g_sfera_window_runtime.input_state;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x468u);
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->eax + cpu->esi + ((uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].value);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"v");
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461344u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x461344u));
    if (cpu->eax != 1u) goto label_000614B0;
    cpu->eax = g_sfera_window_runtime.input_state;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x468u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->eax + cpu->esi + ((uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].radius);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"r");
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461375u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x461375u));
    if (cpu->eax != 1u) goto label_000614BE;
    cpu->esi += 0x1Cu;
    ++cpu->ebx;
    if (cpu->esi == 0x460u) goto label_000614CC;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ebx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->ecx = cpu->eax + 0x30u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = g_sfera_window_runtime.input_state;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x468u);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ebx & 0xFFu) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, 1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = cpu->edx + cpu->esi + ((uintptr_t)&g_sfera_planting_table_runtime.records[0].entries[0].name[0]);
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esp + 0x21u) = cpu->ecx & 0xFFu;
    lift_push32(cpu, (uintptr_t)"n");
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4613E4u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x4613E4u));
    if (cpu->eax != 0u) goto label_00061313;
    label_000613EC:
    cpu->ecx = g_sfera_window_runtime.input_state;
    cpu->edx = cpu->ecx;
    cpu->edx *= 0x468u;
    *(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_planting_table_runtime.records[0].count)) = cpu->ebx;
    ++cpu->ecx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + 0x30u;
    *(uint8_t*)(cpu->esp + 0x15u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x11u) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    g_sfera_window_runtime.input_state = cpu->ecx;
    lift_push32(cpu, 2u);
    cpu->edx = cpu->eax + cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x468u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx += ((uintptr_t)&g_sfera_planting_table_runtime.records[0].descriptor);
    lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esp + 0x1Eu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x1Au) = cpu->eax & 0xFFu;
    lift_push32(cpu, (uintptr_t)"d");
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46145Eu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x46145Eu));
    if (cpu->eax != 0u) goto label_000612D0;
    label_00061466:
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461477u)); sfera_sub_00480390(cpu, LIFT_CODE_TOKEN_VA(0x461477u));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00061494:
    cpu->edx = (uintptr_t)"d";
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x614A2u)); sfera_sub_00461170(cpu, LIFT_CODE_TOKEN_RVA(0x614A2u));
    label_000614A2:
    cpu->edx = (uintptr_t)"n";
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x614B0u)); sfera_sub_00461170(cpu, LIFT_CODE_TOKEN_RVA(0x614B0u));
    label_000614B0:
    cpu->edx = (uintptr_t)"v";
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x614BEu)); sfera_sub_00461170(cpu, LIFT_CODE_TOKEN_RVA(0x614BEu));
    label_000614BE:
    cpu->edx = (uintptr_t)"r";
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x614CCu)); sfera_sub_00461170(cpu, LIFT_CODE_TOKEN_RVA(0x614CCu));
    label_000614CC:
    cpu->ecx = (uintptr_t)"MAX_OBJS_IN_PATTERN exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4614D6u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4614D6u));
    lift_trap(cpu, 0x4614D6u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004614E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi >= 0) goto label_00061506;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61506u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x61506u));
    label_00061506:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006151A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6151Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6151Au));
    label_0006151A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    if (cpu->esi != 0u) goto label_0006152A;
    cpu->edi = 0u;
    goto label_00061574;
    label_0006152A:
    if (*(uint8_t*)(cpu->esi + 0x138u) != 0u) goto label_00061572;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461542u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x461542u));
    if (cpu->eax != 0u) goto label_0006154B;
    cpu->eax = (uintptr_t)"<none>";
    label_0006154B:
    lift_push32(cpu, 0x47EFu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461560u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61572u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x61572u));
    label_00061572:
    cpu->edi = cpu->esi;
    label_00061574:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x13Cu);
    if (cpu->esi == 0xFFFFFFFFu) goto label_000615BD;
    if ((int32_t)cpu->esi >= 0) goto label_0006158D;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6158Du)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6158Du));
    label_0006158D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_000615A1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x615A1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x615A1u));
    label_000615A1:
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    *(uint32_t*)(cpu->eax + (cpu->esi * 4u)) = 0u;
    *(uint32_t*)(cpu->edi + 0x13Cu) = 0xFFFFFFFFu;
    --g_sfera_world_objects.extended_object_count;
    label_000615BD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004615E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->edi >= 0) goto label_00061606;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61606u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x61606u));
    label_00061606:
    if ((int32_t)cpu->edi < (int32_t)g_sfera_world_objects.object_handles.capacity) goto label_0006161A;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6161Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6161Au));
    label_0006161A:
    cpu->eax = g_sfera_world_objects.object_handles.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    if (cpu->eax != 0u) goto label_0006162A;
    cpu->ebx = 0u;
    goto label_00061674;
    label_0006162A:
    if (*(uint8_t*)(cpu->eax + 0x138u) != 0u) goto label_00061672;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461642u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x461642u));
    if (cpu->eax != 0u) goto label_0006164B;
    cpu->eax = (uintptr_t)"<none>";
    label_0006164B:
    lift_push32(cpu, 0x47FDu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\main.cpp"); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"Try to get extended from superstatic: %s, %s:%d"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x461660u));
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61672u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x61672u));
    label_00061672:
    cpu->ebx = cpu->eax;
    label_00061674:
    if (*(uint32_t*)(cpu->ebx + 0x13Cu) != 0xFFFFFFFFu) goto label_000616E8;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    label_00061680:
    if ((int32_t)cpu->esi >= 0) goto label_0006168E;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6168Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x6168Eu));
    label_0006168E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_000616A2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x616A2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x616A2u));
    label_000616A2:
    cpu->eax = g_sfera_world_objects.extended_object_handles.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) == 0u) goto label_000616B0;
    ++cpu->esi;
    goto label_00061680;
    label_000616B0:
    if ((int32_t)cpu->esi >= 0) goto label_000616BE;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x616BEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x616BEu));
    label_000616BE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_world_objects.extended_object_handles.capacity) goto label_000616D2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_world_objects.extended_object_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x616D2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x616D2u));
    label_000616D2:
    cpu->ecx = g_sfera_world_objects.extended_object_handles.data;
    *(uint32_t*)(cpu->ecx + (cpu->esi * 4u)) = cpu->edi;
    ++g_sfera_world_objects.extended_object_count;
    *(uint32_t*)(cpu->ebx + 0x13Cu) = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    label_000616E8:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    g_sfera_graphics_runtime.rebuild_percent = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46174Au)); sfera_sub_004DA310(cpu, LIFT_CODE_TOKEN_VA(0x46174Au));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0006179E;
    cpu->ecx = cpu->esi;
    g_sfera_world_render_runtime.scene_active = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46175Fu)); sfera_sub_004BBE80(cpu, LIFT_CODE_TOKEN_VA(0x46175Fu));
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46176Cu)); sfera_sub_004BAFB0(cpu, LIFT_CODE_TOKEN_VA(0x46176Cu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461771u)); sfera_sub_0045E560(cpu, LIFT_CODE_TOKEN_VA(0x461771u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46177Cu)); sfera_sub_004D8840(cpu, LIFT_CODE_TOKEN_VA(0x46177Cu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461781u)); sfera_sub_0044E020(cpu, LIFT_CODE_TOKEN_VA(0x461781u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device_runtime;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    g_sfera_world_render_runtime.scene_active = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6179Eu)); sfera_sub_004D8880(cpu, LIFT_CODE_TOKEN_RVA(0x6179Eu));
    label_0006179E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004617A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4617CBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4617CBu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->edi = 1u;
    if (cpu->eax == 0u) goto label_000617FC;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x15u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4617FAu)); sfera_sub_004DA880(cpu, LIFT_CODE_TOKEN_VA(0x4617FAu));
    goto label_000617FE;
    label_000617FC:
    cpu->eax = 0u;
    label_000617FE:
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    g_sfera_render_sample_runtime.active_record = cpu->eax;
    if (cpu->eax != 0u) goto label_00061819;
    cpu->ecx = (uintptr_t)"CreateTexture for water reflection failed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61819u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x61819u));
    label_00061819:
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_0006182D;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6182Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6182Du));
    label_0006182D:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061849;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61849u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61849u));
    label_00061849:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->edi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061866;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61866u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61866u));
    label_00061866:
    x87_v0 = (double)*(float*)((uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp");
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0x20u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061889;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61889u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61889u));
    label_00061889:
    x87_v0 = (double)0.4000000059604645f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0x24u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_000618AB;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x618ABu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x618ABu));
    label_000618AB:
    x87_v0 = (double)0.15000000596046448f;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0x28u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_000618CE;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x618CEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x618CEu));
    label_000618CE:
    x87_v0 = (double)0.11999999731779099f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 2u;
    *(float*)(cpu->edx + 0x2Cu) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_000618F6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x618F6u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x618F6u));
    label_000618F6:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->esi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061912;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61912u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61912u));
    label_00061912:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0x34u) = cpu->esi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_0006192F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x6192Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x6192Fu));
    label_0006192F:
    x87_v0 = (double)0.6000000238418579f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0x38u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061952;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61952u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61952u));
    label_00061952:
    x87_v0 = (double)0.20000000298023224f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0x3Cu) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061974;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61974u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61974u));
    label_00061974:
    x87_v0 = (double)0.20000000298023224f;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0x40u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061997;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61997u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61997u));
    label_00061997:
    x87_v0 = (double)0.019999999552965164f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->ebx = 3u;
    *(float*)(cpu->edx + 0x44u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->ebx) goto label_000619BF;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x619BFu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x619BFu));
    label_000619BF:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->edi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->ebx) goto label_000619DB;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x619DBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x619DBu));
    label_000619DB:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0x4Cu) = cpu->esi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->ebx) goto label_000619F8;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x619F8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x619F8u));
    label_000619F8:
    x87_v0 = (double)0.6000000238418579f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0x50u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->ebx) goto label_00061A1B;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61A1Bu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61A1Bu));
    label_00061A1B:
    x87_v0 = (double)0.33000001311302185f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0x54u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->ebx) goto label_00061A3D;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61A3Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61A3Du));
    label_00061A3D:
    x87_v0 = (double)0.23000000417232513f;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0x58u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->ebx) goto label_00061A60;
    cpu->edx = cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61A60u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61A60u));
    label_00061A60:
    x87_v0 = (double)0.07999999821186066f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->edi = 4u;
    *(float*)(cpu->edx + 0x5Cu) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061A88;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61A88u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61A88u));
    label_00061A88:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0x60u) = cpu->esi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061AA4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61AA4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61AA4u));
    label_00061AA4:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0x64u) = cpu->esi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061AC1;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61AC1u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61AC1u));
    label_00061AC1:
    x87_v0 = (double)*(float*)((uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp");
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0x68u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061AE4;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61AE4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61AE4u));
    label_00061AE4:
    x87_v0 = (double)0.3499999940395355f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0x6Cu) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061B06;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61B06u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61B06u));
    label_00061B06:
    x87_v0 = (double)0.20000000298023224f;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0x70u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->edi) goto label_00061B29;
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61B29u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61B29u));
    label_00061B29:
    x87_v0 = (double)0.05999999865889549f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 5u;
    *(float*)(cpu->edx + 0x74u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061B51;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61B51u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61B51u));
    label_00061B51:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0x78u) = cpu->ebx;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061B6D;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61B6Du)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61B6Du));
    label_00061B6D:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0x7Cu) = cpu->ebx;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061B8A;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61B8Au)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61B8Au));
    label_00061B8A:
    x87_v0 = (double)0.800000011920929f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0x80u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061BB0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61BB0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61BB0u));
    label_00061BB0:
    x87_v0 = (double)0.5f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0x84u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061BD5;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61BD5u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61BD5u));
    label_00061BD5:
    x87_v0 = (double)0.10000000149011612f;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0x88u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061BFB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61BFBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61BFBu));
    label_00061BFB:
    x87_v0 = (double)0.07999999821186066f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 6u;
    *(float*)(cpu->edx + 0x8Cu) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061C26;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61C26u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61C26u));
    label_00061C26:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0x90u) = cpu->edi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061C45;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61C45u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61C45u));
    label_00061C45:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0x94u) = cpu->edi;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061C65;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61C65u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61C65u));
    label_00061C65:
    x87_v0 = 1.0;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0x98u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061C87;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61C87u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61C87u));
    label_00061C87:
    x87_v0 = (double)0.44999998807907104f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0x9Cu) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061CAC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61CACu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61CACu));
    label_00061CAC:
    x87_v0 = 0.0;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0xA0u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061CCE;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61CCEu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61CCEu));
    label_00061CCE:
    x87_v0 = (double)0.03999999910593033f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    cpu->esi = 7u;
    *(float*)(cpu->edx + 0xA4u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061CF9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61CF9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61CF9u));
    label_00061CF9:
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->eax + 0xA8u) = cpu->ebx;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061D18;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61D18u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61D18u));
    label_00061D18:
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(uint32_t*)(cpu->ecx + 0xACu) = cpu->ebx;
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061D38;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61D38u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61D38u));
    label_00061D38:
    x87_v0 = (double)0.6000000238418579f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0xB0u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061D5E;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61D5Eu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61D5Eu));
    label_00061D5E:
    x87_v0 = (double)0.4000000059604645f;
    cpu->eax = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->eax + 0xB4u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061D83;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61D83u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61D83u));
    label_00061D83:
    x87_v0 = (double)0.10000000149011612f;
    cpu->ecx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->ecx + 0xB8u) = x87_v0; 
    if ((int32_t)g_sfera_scene_array_runtime.reflection_targets.capacity > (int32_t)cpu->esi) goto label_00061DA9;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_scene_array_runtime.reflection_targets.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61DA9u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x61DA9u));
    label_00061DA9:
    x87_v0 = (double)0.03999999910593033f;
    cpu->edx = g_sfera_scene_array_runtime.reflection_targets.data;
    *(float*)(cpu->edx + 0xBCu) = x87_v0; 
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00461DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x424u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461DF8u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x461DF8u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461DFFu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x461DFFu));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461EABu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x461EABu));
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
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x61F41u)); sfera_sub_00437FF0(cpu, LIFT_CODE_TOKEN_RVA(0x61F41u));
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
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x461F77u)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x461F77u));
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
    lift_trap(cpu, 0x461FA3u, "INT3"); return;
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
    cpu->esi = (uintptr_t)&g_sfera_collision_scratch_runtime.light_candidates[0][4];
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
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4622E8u)); sfera_sub_0045DA60(cpu, LIFT_CODE_TOKEN_VA(0x4622E8u));
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
    lift_trap(cpu, 0x4623FAu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00462400(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 4u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    sub_pred[0] = cpu->ecx == 0x20u;
    if (cpu->ecx > 0x20u) goto label_0006254E;
    if (sub_pred[0]) goto label_000624E8;
    cpu->eax = cpu->ecx;
    if ((cpu->eax -= 0x10u) == 0u) goto label_000624C2;
    if ((--cpu->eax) == 0u) goto label_000624A1;
    if ((cpu->eax -= 0xBu) != 0u) goto label_00062565;
    if (g_sfera_window_runtime.windowed == cpu->eax) goto label_00062466;
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_23 == cpu->eax) goto label_00062466;
    g_sfera_texture_cache_runtime.cache_enabled = 1u;
    goto label_0006246F;
    label_00062466:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    g_sfera_texture_cache_runtime.cache_enabled = cpu->eax;
    label_0006246F:
    lift_native_call(cpu, native_function_address32(&SI_GetStreamVolume), LIFT_CODE_TOKEN_VA(0x46246Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46247Bu)); sfera_sub_004982F0(cpu, LIFT_CODE_TOKEN_VA(0x46247Bu));
    g_sfera_client_config_runtime.scalar_01 = (double)(0.0);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_10) = 1u;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000624A1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4624A6u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x4624A6u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::PostQuitMessage), LIFT_CODE_TOKEN_VA(0x4624A8u));
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000624C2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4624C7u)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x4624C7u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4624CCu)); sfera_sub_0042EB70(cpu, LIFT_CODE_TOKEN_VA(0x4624CCu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::PostQuitMessage), LIFT_CODE_TOKEN_VA(0x4624CEu));
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000624E8:
    if ((((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & (1u)) != 0u) goto label_0006251F;
    g_sfera_cursor_manager_runtime.initialized_flags = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(1u);
    cpu->ecx = (uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46250Au)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x46250Au));
    cpu->eax = register_lifted_finalizer(&sfera_sub_004FA360) ? 0u : 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0xCu) = 0xFFFFFFFFu;
    label_0006251F:
    if (g_sfera_cursor_manager_runtime.active_cursor == 0u) goto label_00062678;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462531u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x462531u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->apply(cpu);
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0006254E:
    cpu->eax = cpu->ecx;
    if ((cpu->eax -= 0x100u) == 0u) goto label_00062619;
    if ((cpu->eax -= 2u) == 0u) goto label_000625D4;
    if ((cpu->eax -= 0x10u) == 0u) goto label_0006258D;
    label_00062565:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DefWindowProcA), LIFT_CODE_TOKEN_VA(0x462575u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0006258D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    cpu->eax &= 0xFFF0u;
    if ((cpu->eax -= 0xF090u) == 0u) goto label_00062678;
    if ((cpu->eax -= 0x70u) == 0u) goto label_00062678;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x112u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::DefWindowProcA), LIFT_CODE_TOKEN_VA(0x4625BCu));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_000625D4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = cpu->ecx;
    cpu->edx <<= 4u;
    if (*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].defined)) != 1u) goto label_00062678;
    cpu->eax = g_sfera_pending_key_runtime.count;
    if ((int32_t)cpu->eax >= (int32_t)0x1Eu) goto label_00062678;
    *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_pending_key_runtime.key_codes[0])) = cpu->ecx;
    ++cpu->eax;
    g_sfera_pending_key_runtime.count = cpu->eax;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00062619:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if ((uint32_t)(g_sfera_client_process_runtime.ui_bridge) == 0u) goto label_0006263F;
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.command_state) = cpu->eax;
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0006263F:
    if ((uint32_t)(g_sfera_texture_cache_runtime.render_gate) == 0u) goto label_0006265F;
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    if (*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_font_runtime.glyphs[0].defined)) == 0u) goto label_0006265F;
    if (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_presence[0])) == 0u) goto label_00062678;
    label_0006265F:
    cpu->ecx = g_sfera_scene_control_runtime.context_count;
    if ((int32_t)cpu->ecx >= (int32_t)0x1Eu) goto label_00062678;
    *(uint32_t*)((cpu->ecx * 4u) + ((uintptr_t)&g_sfera_scene_control_runtime.context_queue[0])) = cpu->eax;
    ++cpu->ecx;
    g_sfera_scene_control_runtime.context_count = cpu->ecx;
    label_00062678:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_00462740(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46275Bu)); sfera_sub_004815D0(cpu, LIFT_CODE_TOKEN_VA(0x46275Bu));
    cpu->ecx = (uintptr_t)"Models\\Materials.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462765u)); sfera_sub_00482170(cpu, LIFT_CODE_TOKEN_VA(0x462765u));
    cpu->ebp = cpu->eax;
    cpu->edx = (uintptr_t)"materials";
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462777u)); sfera_sub_004811B0(cpu, LIFT_CODE_TOKEN_VA(0x462777u));
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462784u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x462784u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uintptr_t)&g_sfera_main_render_runtime.material_count;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462794u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x462794u));
    cpu->ecx = g_sfera_main_render_runtime.material_count;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x88u);
    lift_push32(cpu, 0x64Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4627AFu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4627AFu));
    cpu->ecx = g_sfera_main_render_runtime.material_count;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x28Eu);
    lift_push32(cpu, 0x64Bu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    (*(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4627CFu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4627CFu));
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_main_render_runtime.material_count;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x28Eu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4627EAu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4627EAu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4627F1u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4627F1u));
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if ((int32_t)g_sfera_main_render_runtime.material_count <= (int32_t)cpu->ebx) goto label_00062A39;
    cpu->eax = cpu->esp + 0x34u;
    cpu->eax -= cpu->edi;
    cpu->ebp = 0u;
    cpu->esi = cpu->edi + 0x268u;
    cpu->eax -= 0x28u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_00062820:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = cpu->esi + 0xFFFFFD98u;
    cpu->edx += cpu->ebp;
    label_00062830:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00062830;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, (uintptr_t)"default"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x462848u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0006285B;
    g_sfera_direct_input_runtime.acquire_failure_state = cpu->ebx;
    label_0006285B:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFDBCu);
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x24u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + cpu->ebp + 0x68u) = cpu->edx;
    cpu->eax = cpu->ecx + cpu->ebp + 0x68u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    *(float*)(cpu->edx + cpu->ebp + 0x78u) = x87_v0;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    *(float*)(cpu->eax + cpu->ebp + 0x7Cu) = x87_v0;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    *(float*)(cpu->ecx + cpu->ebp + 0x80u) = x87_v0; 
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edx + cpu->ebp + 0x24u) <= (int32_t)cpu->ebx) goto label_00062932;
    cpu->eax = cpu->esp + 0x34u;
    cpu->eax -= 2u;
    cpu->esi += 0xFFFFFDC0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->edi = cpu->ebp + 0x28u;
    label_000628E0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_000628E4:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000628E4;
    cpu->eax = cpu->esp + 0x34u;
    cpu->ecx = cpu->eax + 1u;
    label_000628F5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000628F5;
    cpu->eax -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->ecx + cpu->eax) = cpu->edx & 0xFFu;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46290Eu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x46290Eu));
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x24u) + (uint64_t)(0u);
    *(uint32_t*)(cpu->edi + cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    ++cpu->ebx;
    cpu->edi += 4u;
    cpu->esi -= 0x24u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->eax + cpu->ebp + 0x24u)) goto label_000628E0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_00062932:
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) <= (int32_t)cpu->ebx) goto label_00062A04;
    label_00062940:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uintptr_t)"materials";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46294Fu)); sfera_sub_00481300(cpu, LIFT_CODE_TOKEN_VA(0x46294Fu));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00062A64;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)"name";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x46296Au)); sfera_sub_00481180(cpu, LIFT_CODE_TOKEN_VA(0x46296Au));
    if (cpu->eax == 0u) goto label_00062A6F;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x46297Fu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00062995;
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00062940;
    goto label_00062A04;
    label_00062995:
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->eax = cpu->edx + cpu->ebp + 0x78u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = (uintptr_t)"rgbRand";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4629AEu)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x4629AEu));
    if (cpu->eax == 0u) goto label_00062A04;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->edx = cpu->ecx + cpu->ebp + 0x7Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->edx = (uintptr_t)"rgbRand";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4629CBu)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x4629CBu));
    if (cpu->eax == 0u) goto label_00062A7A;
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    cpu->ecx = cpu->eax + cpu->ebp + 0x80u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 2u);
    cpu->edx = (uintptr_t)"rgbRand";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4629EEu)); sfera_sub_00481250(cpu, LIFT_CODE_TOKEN_VA(0x4629EEu));
    if (cpu->eax == 0u) goto label_00062A7A;
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_view_state_runtime.view_base_index;
    *(uint8_t*)(cpu->edx + cpu->ebp + 0x84u) = 1u;
    label_00062A04:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) - (uint64_t)(0x28Eu) - (uint64_t)(0u);
    ++cpu->ebx;
    cpu->esi += 0x28Eu;
    cpu->ebp += 0x88u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_main_render_runtime.material_count) goto label_00062820;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00062A39:
    lift_push32(cpu, 0x67Du);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462A4Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x462A4Au));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462A51u)); sfera_sub_004815C0(cpu, LIFT_CODE_TOKEN_VA(0x462A51u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00062A64:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Can't go into material struct %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62A6Fu)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_RVA(0x62A6Fu));
    label_00062A6F:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Field name is absent in material %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x62A7Au)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_RVA(0x62A7Au));
    label_00062A7A:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"Wrong format of rgbRand in material struct %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x462A85u)); sfera_sub_004623C0(cpu, LIFT_CODE_TOKEN_VA(0x462A85u));
    lift_trap(cpu, 0x462A85u, "INT3"); return;
}

} // namespace lifted
