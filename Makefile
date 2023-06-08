CC = clang
NOWARNINGS = -Wno-switch -Wno-poison-system-directories -Wno-declaration-after-statement
CFLAGS = -std=c99 -g -Weverything -Werror -isysteminclude -Isrc -Llib -DMACOS $(NOWARNINGS)
LFLAGS = -framework Cocoa -framework QuartzCore -framework OpenGL
SRCDIR = src
BINDIR = bin
TARGET = main
SRC = $(wildcard $(SRCDIR)/*.c $(SRCDIR)/*/*.c $(SRCDIR)/*.m)

.PHONY: all clean run

all:
	time $(CC) $(SRC) -o $(BINDIR)/$(TARGET) $(CFLAGS) $(LFLAGS)

clean:
	rm -r $(BINDIR)/*

run:
	$(BINDIR)/$(TARGET)