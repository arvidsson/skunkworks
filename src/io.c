#include "skunk.h"
#include <stdio.h>

#include "log.h"

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
