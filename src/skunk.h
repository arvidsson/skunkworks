#pragma once

// std libs
#include <stdint.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "log.h"
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_time.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "scenes.h"

// macros
#define unused(x) (void)(x)
#define len(array) (sizeof((array)) / (sizeof((array)[0])))

// types
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef float f32;
typedef double f64;

// constants
static const i64 INT_MAX = INT64_MAX;
static const f64 FLOAT_MAX = DBL_MAX;

// io
void ResetInputState(void);
void UpdateInputState(u32 keycode, u32 eventType);
bool IsKeyDown(u32 keycode);
bool IsKeyPressed(u32 keycode);
bool IsKeyReleased(u32 keycode);
char* ReadFile(char* filename);

// random
void SeedRng(u64 seed);
void SeedRngWithTime(void);
// generate integer in range [min, max]
i64 GetRandomInt(i64 min, i64 max);
// generate float in range [min, max]
f64 GetRandomFloat(f64 min, f64 max);

// scene

void TransitionScene(Scenes next);
void UpdateScene(void);
