#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT(sandbox,0.0.1,narozaatgmaildotcom)
AM_INIT_AUTOMAKE(gnu dist-bzip2)
AC_PROG_LIBTOOL
dnl LT_PREREQ([2.2])
dnl LT_INIT([dlopen])
AC_LANG([C++])
AC_CONFIG_SRCDIR([common_sandbox.am])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
AM_PROG_CC_C_O

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
dnl AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE

dnl system and posix headers
m4_foreach( [myvar],
            [unistd.h],
            [AC_CHECK_HEADERS( myvar,,
                               AC_MSG_ERROR( missing myvar ) )] )dnl

# c++ library headers
m4_foreach( [myvar],
            [algorithm,fstream,iostream,map,string,vector],
            [AC_CHECK_HEADERS( myvar,,
                               AC_MSG_ERROR( missing stdc++ header myvar ) )] )dnl

# boost headers
dnl m4_foreach( [myvar],
dnl             [asio,assign,date_time,lexical_cast,phoenix,preprocessor,spirit/include/karma,spirit/include/qi,thread],
dnl             [AC_CHECK_HEADERS( boost/myvar.hpp,,
dnl                                AC_MSG_ERROR( missing boost/myvar.hpp ) )] )dnl

AX_BOOST_BASE([1.47],,AC_MSG_ERROR(you need boost 1.47))


dnl AI_CHECK_ORB(,[tao])
dnl if test "x$ORB" = "xno"
dnl then
dnl     AC_MSG_ERROR([an ORB is required])
dnl fi


AC_CONFIG_FILES([Makefile])

AC_OUTPUT

