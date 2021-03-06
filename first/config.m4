dnl $Id$
dnl config.m4 for extension hello_world

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl Otherwise use enable:

PHP_ARG_ENABLE(hello_world, whether to enable hello_world support,
Make sure that the comment is aligned:
[  --enable-hello_world           Enable hello_world support])

if test "$PHP_HELLO_WORLD" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-hello_world -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/hello_world.h"  # you most likely want to change this
  dnl if test -r $PHP_HELLO_WORLD/$SEARCH_FOR; then # path given as parameter
  dnl   HELLO_WORLD_DIR=$PHP_HELLO_WORLD
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for hello_world files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HELLO_WORLD_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HELLO_WORLD_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the hello_world distribution])
  dnl fi

  dnl # --with-hello_world -> add include path
  dnl PHP_ADD_INCLUDE($HELLO_WORLD_DIR/include)

  dnl # --with-hello_world -> check for lib and symbol presence
  dnl LIBNAME=hello_world # you may want to change this
  dnl LIBSYMBOL=hello_world # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HELLO_WORLD_DIR/$PHP_LIBDIR, HELLO_WORLD_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HELLO_WORLDLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong hello_world lib version or lib not found])
  dnl ],[
  dnl   -L$HELLO_WORLD_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HELLO_WORLD_SHARED_LIBADD)

  PHP_NEW_EXTENSION(hello_world, hello_world.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
