#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_time.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "skunk.h"

static sg_pass_action pass_action;

static void Init(void)
{
    stm_setup();

    sg_setup(&(sg_desc){
        .context = sapp_sgcontext(),
        .logger.func = slog_func,
    });
    pass_action = (sg_pass_action) {
        .colors[0] = { .load_action=SG_LOADACTION_CLEAR, .clear_value={1.0f, 0.0f, 0.0f, 1.0f} }
    };
}

static void Update(void)
{
    float g = pass_action.colors[0].clear_value.g + 0.01f;
    pass_action.colors[0].clear_value.g = (g > 1.0f) ? 0.0f : g;
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());
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
        .window_title = "Clear Sample",
        .logger.func = slog_func,
    };
}
