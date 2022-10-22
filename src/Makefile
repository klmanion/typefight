#!/usr/bin/make -f

SHELL = /bin/sh

topdir = ..
srcdir = $(topdir)/src

CC = clang++
INSTALL = /usr/local/bin/install -c
INSTALLDATA = /usr/local/bin/install -c -m 644

LANG = c++
STD = c++20
CDEBUG = -g
CFLAGS = $(CDEBUG) -Wall -pedantic -O2
DEFS = -DDEBUG
CPPFLAGS = -I. -I$(srcdir) -I$(topdir)/include $(DEFS)
LDFLAGS = 

LIBS = -lncurses

prefix = /usr/local
binprefix = 

bindir = $(prefix)/bin

SRCS_C = main.cpp
SRCS = $(SRCS_C)
OBJS = $(SRCS_C:.c=.o)

## add README and LICENSE to this
AUX = 

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
	rm -f templ TAGS tags

distclean: realclean

typefight: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@

## main.o: templ.o
