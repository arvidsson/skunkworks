CC = clang
CFLAGS = -std=c99 -Weverything -isysteminclude -Wno-poison-system-directories
# LFLAGS = 
LDLIBS = -framework Cocoa -framework QuartzCore -framework OpenGL
SRC = $(wildcard src/*.c src/*.m)
BIN = bin/main

.PHONY: all clean

all:
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(LDLIBS)

clean:
	rm -r bin/*