
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

v0_SOURCES = v0.cc
v0_CPPFLAGS = $(CUNIT_CFLAGS) -I$(top_srcdir)/src
v0_LDADD = $(LDFLAGS) $(CUNIT_LIBS) ../src/liboctetos-coreutils.la