

lib_LTLIBRARIES = liboctetos-coreutils.la


SOURCES = shell.cc ls.cc cd.cc mkdir.cc rm.cc touch.cc rename.cc exists.cc

liboctetos_coreutils_la_LDFLAGS = -shared -fPIC
liboctetos_coreutils_la_CPPFLAGS =  $(OCTETOS_CORE_CFLAGS)
liboctetos_coreutils_la_LIBADD = $(OCTETOS_CORE_LIBS)
liboctetos_coreutils_la_SOURCES = $(SOURCES)


octetos_core_includedir = $(includedir)/octetos/coreutils
octetos_core_include_HEADERS = shell.hh

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = octetos-coreutils.pc

EXTRA_DIST = \
	octetos-coreutils.pc.in
