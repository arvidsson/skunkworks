#define SOKOL_IMPL

#ifdef WINDOWS
#define SOKOL_GLCORE33
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_glue.h"
#endif

#include "sokol_time.h"
#include "sokol_log.h"

#define TINYMT64_IMPL
#include "tinymt64.h"

#define LOG_IMPL
#include "log.h"
