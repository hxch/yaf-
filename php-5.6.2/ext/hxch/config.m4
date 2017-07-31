dnl $Id$
dnl config.m4 for extension hxch

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(hxch, for hxch support,
dnl Make sure that the comment is aligned:
dnl [  --with-hxch             Include hxch support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(hxch, whether to enable hxch support,
dnl Make sure that the comment is aligned:
[  --enable-hxch           Enable hxch support])

if test "$PHP_HXCH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-hxch -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/hxch.h"  # you most likely want to change this
  dnl if test -r $PHP_HXCH/$SEARCH_FOR; then # path given as parameter
  dnl   HXCH_DIR=$PHP_HXCH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for hxch files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HXCH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HXCH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the hxch distribution])
  dnl fi

  dnl # --with-hxch -> add include path
  dnl PHP_ADD_INCLUDE($HXCH_DIR/include)

  dnl # --with-hxch -> check for lib and symbol presence
  dnl LIBNAME=hxch # you may want to change this
  dnl LIBSYMBOL=hxch # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HXCH_DIR/lib, HXCH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HXCHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong hxch lib version or lib not found])
  dnl ],[
  dnl   -L$HXCH_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HXCH_SHARED_LIBADD)

  PHP_NEW_EXTENSION(hxch, hxch.c, $ext_shared)
fi
