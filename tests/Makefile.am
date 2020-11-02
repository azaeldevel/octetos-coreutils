
AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(OCTETOS_COREUTILS_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

check_PROGRAMS = v0
TESTS= $(check_PROGRAMS)

SOURCES = v0.cc $(top_srcdir)/src/shell.cc $(top_srcdir)/src/ls.cc $(top_srcdir)/src/cd.cc $(top_srcdir)/src/mkdir.cc $(top_srcdir)/src/rm.cc $(top_srcdir)/src/touch.cc $(top_srcdir)/src/rename.cc $(top_srcdir)/src/exists.cc

v0_SOURCES = v0.cc
v0_CPPFLAGS = $(CUNIT_CFLAGS) -I$(top_srcdir)/src
v0_LDADD = $(LDFLAGS) $(CUNIT_LIBS) $(top_builddir)/src/liboctetos-coreutils.la