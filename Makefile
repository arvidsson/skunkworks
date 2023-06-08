CC = clang
CFLAGS = -std=c99 -g -Weverything -isysteminclude -Llib -DMACOS -Wno-poison-system-directories -Wno-declaration-after-statement
LFLAGS = -framework Cocoa -framework QuartzCore -framework OpenGL
SRCDIR = src
BINDIR = bin
TARGET = main
SRC = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*.m)

.PHONY: all clean

all:
	time $(CC) $(SRC) -o $(BINDIR)/$(TARGET) $(CFLAGS) $(LFLAGS)

clean:
	rm -r $(BINDIR)/*