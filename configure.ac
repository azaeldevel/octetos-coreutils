

AC_INIT(octetos-coreutils, 0.16.0-alpha,azael.devel@gmail.com)
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.11])
AM_SILENT_RULES([yes])

AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX



dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
#IT_PROG_INTLTOOL([0.35.0])

#GETTEXT_PACKAGE=octetos-coreutils
#AC_SUBST(GETTEXT_PACKAGE)
#AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])
#AM_GLIB_GNU_GETTEXT



dnl ***************************************************************************
dnl Check for Windows
dnl ***************************************************************************
dnl AC_CANONICAL_HOST

dnl case $host_os in
dnl   *mingw*)
dnl     platform_win32=yes
dnl     native_win32=yes
dnl     ;;
dnl   pw32* | *cygwin*)
dnl     platform_win32=yes
dnl     native_win32=no
dnl     ;;
dnl   *)
dnl     platform_win32=no
dnl     native_win32=no
dnl     ;;
dnl esac
dnl AM_CONDITIONAL(PLATFORM_WIN32, test x"$platform_win32" = "xyes")
dnl AM_CONDITIONAL(NATIVE_WIN32, test x"$native_win32" = "xyes")


LT_INIT


PKG_CHECK_MODULES([CHECK], [check])

#PKG_CHECK_MODULES(CUNIT, [cunit ])

PKG_CHECK_MODULES(OCTETOS_CORE, [octetos-core])

AM_CONDITIONAL(WITH_TESTS, test x"$with_tests" = "xyes")
AC_ARG_WITH([tests], AS_HELP_STRING([--with-tests], [Compilando con soporte para Tests]))
if test "x$with_tests" = "xyes"; then 
	PKG_CHECK_MODULES(CUNIT,cunit)
fi


AC_OUTPUT([
Makefile
src/octetos-coreutils.pc
src/Makefile
tests/Makefile])
