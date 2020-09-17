

check_PROGRAMS = v0
TESTS= $(check_PROGRAMS)

v0_SOURCES = v0.cc
v0_CFLAGS = $(CFLAGS) @CHECK_CFLAGS@ -I$(top_srcdir)/src
v0_CXXFLAGS = $(CXXFLAGS) @CHECK_CFLAGS@ -I$(top_srcdir)/src
v0_CPPFLAGS = $(CPPFLAGS) @CHECK_CFLAGS@ -I$(top_srcdir)/src
v0_LDADD = $(LDFLAGS) @CHECK_LIBS@ $(top_buildir)/liboctetos-coreutils.la