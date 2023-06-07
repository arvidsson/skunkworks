// TODO: split up impl into c and m files depending on which system we are compiling on
#define SOKOL_IMPL
#define SOKOL_GLCORE33
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_time.h"
#include "sokol_log.h"
#include "sokol_glue.h"

#define TINYMT64_IMPL
#include "tinymt64.h"
