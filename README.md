# skunkworks

adventures in C using single-header libs

## deps

* [sokol](https://github.com/floooh/sokol)

## instructions

### macos

`clang src/main.c src/lib.m -o bin/main -Weverything -isysteminclude -framework Cocoa -framework QuartzCore -framework OpenGL -Wno-poison-system-directories`