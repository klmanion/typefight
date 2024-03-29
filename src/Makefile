#!/usr/bin/make -f

SHELL = /bin/sh

topdir = ..
srcdir = $(topdir)/src

CC = clang++
INSTALL = /usr/local/bin/install -c
INSTALLDATA = /usr/local/bin/install -c -m 644

LANG = c++
STD = c++17
CDEBUG = -g
CFLAGS = $(CDEBUG) -Wall -pedantic -O2
DEFS = -DDEBUG
CPPFLAGS = -I. -I$(srcdir) -I$(topdir)/include $(DEFS)
LDFLAGS = 

LIBS = -lncurses

prefix = /usr/local
binprefix = 

bindir = $(prefix)/bin

SRCS_C = main.cpp typefight.cpp model.cpp \
	 keymap.cpp keybind.cpp keyseq.cpp command.cpp \
	 movement.cpp direction.cpp \
	 world.cpp clock.cpp \
	 entity.cpp hero.cpp ball.cpp
SRCS = $(SRCS_C)
OBJS = $(SRCS_C:.cpp=.o)

## add README and LICENSE to this
AUX = LICENSE

.ONESHELL:

.EXPORT_ALL_VARIABLES:

.SUFFIXES:
.SUFFIXES: .cpp .o .h

.cpp.o:
	$(CC) -c -x$(LANG) -std=$(STD) $(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY: all
all: typefight

.PHONY: install
install: all
	$(INSTALL) typefight $(bindir)/$(binprefix)typefight

.PHONY: TAGS tags
TAGS: $(SRCS)
	ctags $^

tags: TAGS

.PHONY: clean realclean distclean
clean:
	rm -f *.o

realclean: clean
	rm -f typefight TAGS tags

distclean: realclean

typefight: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@

main.o: typefight.o

typefight.o: model.o 

model.o: keymap.o world.o clock.o hero.o 

keymap.o: keybind.o

keybind.o: keyseq.o command.o

world.o: entity.o movement.o

entity.o: direction.o

hero.o: entity.o ball.o

ball.o: entity.o

movement.o: direction.o entity.o
