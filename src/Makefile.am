## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_COREUTILS_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = liboctetos-coreutils.la

bin_PROGRAMS = develop

develop_SOURCES = develop.cc uname.cc

liboctetos_coreutils_la_SOURCES = \
	lib.c

liboctetos_coreutils_la_LDFLAGS = 

liboctetos_coreutils_la_LIBADD = $(OCTETOS_COREUTILS_LIBS)


if PLATFORM_WIN32
liboctetos_coreutils_la_LDFLAGS += -no-undefined
endif

if NATIVE_WIN32
liboctetos_coreutils_la_LDFLAGS += -export-dynamic
endif

include_HEADERS = \
	octetos_coreutils.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-coreutils.pc

EXTRA_DIST = \
	octetos-coreutils.pc.in
