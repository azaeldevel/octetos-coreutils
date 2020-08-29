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

SOURCES = Apishell.cc ls.cc cd.cc mkdir.cc rm.cc

liboctetos_coreutils_la_LDFLAGS = 
liboctetos_coreutils_la_CPPFLAGS =  $(OCTETOS_CORE_CFLAGS)
liboctetos_coreutils_la_LIBADD = $(CUNIT_LIBS)  $(OCTETOS_CORE_LIBS) -ldl 
if PLATFORM_WIN32
liboctetos_coreutils_la_LDFLAGS += -no-undefined
endif
if NATIVE_WIN32
liboctetos_coreutils_la_LDFLAGS += -export-dynamic
endif
liboctetos_coreutils_la_SOURCES = $(SOURCES)
	

develop_LDADD =  $(OCTETOS_CORE_LIBS)
develop_SOURCES = develop.cc $(SOURCES)

octetos_core_includedir = $(includedir)/octetos/coreutils
octetos_core_include_HEADERS = Apishell.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-coreutils.pc

EXTRA_DIST = \
	octetos-coreutils.pc.in
