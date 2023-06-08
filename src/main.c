#include "skunk.h"

static void Init(void)
{
    stm_setup();

    sg_setup(&(sg_desc) {
        .context = sapp_sgcontext(),
        .logger.func = slog_func,
    });

    TransitionScene(TriangleScene);
}

static void Event(const sapp_event* ev)
{
    switch (ev->type) {
        case SAPP_EVENTTYPE_KEY_DOWN:
            UpdateInputState(ev->key_code, SAPP_EVENTTYPE_KEY_DOWN);
            if (ev->key_code == SAPP_KEYCODE_ENTER && ev->modifiers & SAPP_MODIFIER_ALT) {
                sapp_toggle_fullscreen();
            }
            break;
        case SAPP_EVENTTYPE_KEY_UP:
            UpdateInputState(ev->key_code, SAPP_EVENTTYPE_KEY_UP);
            break;
    }
}

static void Frame(void)
{
    UpdateScene();
}

static void Cleanup(void)
{
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[])
{
    unused(argc);
    unused(argv);

    return (sapp_desc){
        .init_cb = Init,
        .frame_cb = Frame,
        .cleanup_cb = Cleanup,
        .event_cb = Event,
        .width = 400,
        .height = 300,
        .window_title = "skunkworks",
        .logger.func = slog_func,
    };
}
