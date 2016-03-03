dnl $Id$
dnl config.m4 for extension dump_param

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(dump_param, for dump_param support,
dnl Make sure that the comment is aligned:
dnl [  --with-dump_param             Include dump_param support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(dump_param, whether to enable dump_param support,
Make sure that the comment is aligned:
[  --enable-dump_param           Enable dump_param support])

if test "$PHP_DUMP_PARAM" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-dump_param -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/dump_param.h"  # you most likely want to change this
  dnl if test -r $PHP_DUMP_PARAM/$SEARCH_FOR; then # path given as parameter
  dnl   DUMP_PARAM_DIR=$PHP_DUMP_PARAM
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for dump_param files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       DUMP_PARAM_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$DUMP_PARAM_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the dump_param distribution])
  dnl fi

  dnl # --with-dump_param -> add include path
  dnl PHP_ADD_INCLUDE($DUMP_PARAM_DIR/include)

  dnl # --with-dump_param -> check for lib and symbol presence
  dnl LIBNAME=dump_param # you may want to change this
  dnl LIBSYMBOL=dump_param # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $DUMP_PARAM_DIR/$PHP_LIBDIR, DUMP_PARAM_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_DUMP_PARAMLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong dump_param lib version or lib not found])
  dnl ],[
  dnl   -L$DUMP_PARAM_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(DUMP_PARAM_SHARED_LIBADD)

  PHP_NEW_EXTENSION(dump_param, dump_param.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
