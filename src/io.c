#include "skunk.h"
#include "sokol_app.h"
#include <stdio.h>
#include <string.h>

#include "log.h"

#define MAX_KEYS SAPP_KEYCODE_MENU

static bool keysDown[MAX_KEYS];
static bool keysPressed[MAX_KEYS];
static bool keysReleased[MAX_KEYS];

void ResetInputState(void)
{
    memset(keysPressed, 0, sizeof(keysPressed));
    memset(keysReleased, 0, sizeof(keysReleased));
}

void UpdateInputState(u32 keycode, u32 eventType)
{
    assert(keycode >= 0 && keycode < MAX_KEYS);

    switch (eventType) {
        case SAPP_EVENTTYPE_KEY_DOWN:
            keysDown[keycode] = true;
            keysPressed[keycode] = true;
            break;
        case SAPP_EVENTTYPE_KEY_UP:
            keysDown[keycode] = false;
            keysPressed[keycode] = true;
            break;
    }
}

bool IsKeyDown(u32 keycode)
{
    assert(keycode >= 0 && keycode < MAX_KEYS);
    return keysDown[keycode];
}

bool IsKeyPressed(u32 keycode)
{
    assert(keycode >= 0 && keycode < MAX_KEYS);
    return keysPressed[keycode];
}

bool IsKeyReleased(u32 keycode)
{
    assert(keycode >= 0 && keycode < MAX_KEYS);
    return keysReleased[keycode];
}

char* ReadFile(char* filename)
{
    char *buffer = NULL;
    FILE *f = fopen(filename, "rb");

    if (f == NULL) {
        log_error("Failed to open file %s", filename);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
    u64 size = (u64)length;
    buffer = (char*)malloc(size + 1);

    if (buffer) {
        fread(buffer, 1, size, f);
    }

    fclose (f);
    buffer[size] = '\0';
    return buffer;
}
