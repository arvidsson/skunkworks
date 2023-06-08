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
    buffer = (char*)malloc(length + 1);

    if (buffer) {
        fread(buffer, 1, length, f);
    }

    fclose (f);
    buffer[length] = '\0';
    return buffer;
}
