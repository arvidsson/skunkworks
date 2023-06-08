#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_time.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "skunk.h"

static struct {
    sg_pipeline pipeline;
    sg_bindings bindings;
    sg_pass_action passAction;
} state;

static float vertices[] = {
    // positions            // colors
    0.0f,  0.5f, 0.5f,      1.0f, 0.0f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f,      0.0f, 1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f,     0.0f, 0.0f, 1.0f, 1.0f
};

static void Init(void)
{
    stm_setup();

    sg_setup(&(sg_desc) {
        .context = sapp_sgcontext(),
        .logger.func = slog_func,
    });

    state.bindings.vertex_buffers[0] = sg_make_buffer(&(sg_buffer_desc) {
        .data = SG_RANGE(vertices),
        .label = "triangle-vertices"
    });

    sg_shader shader = sg_make_shader(&(sg_shader_desc) {
        .vs.source = ReadFile("shaders/triangle.vs"),
        .fs.source = ReadFile("shaders/triangle.fs")
    });

    // create a pipeline object (default render states are fine for triangle)
    state.pipeline = sg_make_pipeline(&(sg_pipeline_desc) {
        .shader = shader,
        // if the vertex layout doesn't have gaps, don't need to provide strides and offsets
        .layout = {
            .attrs = {
                [0].format = SG_VERTEXFORMAT_FLOAT3,
                [1].format = SG_VERTEXFORMAT_FLOAT4
            }
        },
        .label = "triangle-pipeline"
    });

    state.passAction = (sg_pass_action) {
        .colors[0] = { .load_action=SG_LOADACTION_CLEAR, .clear_value={0.0f, 0.0f, 0.0f, 1.0f} }
    };
}

static void Update(void)
{
    sg_begin_default_pass(&state.passAction, sapp_width(), sapp_height());
    sg_apply_pipeline(state.pipeline);
    sg_apply_bindings(&state.bindings);
    sg_draw(0, 3, 1);
    sg_end_pass();
    sg_commit();
}

static void Shutdown(void)
{
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[])
{
    unused(argc);
    unused(argv);

    return (sapp_desc){
        .init_cb = Init,
        .frame_cb = Update,
        .cleanup_cb = Shutdown,
        .width = 400,
        .height = 300,
        .window_title = "skunkworks",
        .logger.func = slog_func,
    };
}
