/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_hxch.h"




//函数宏 
////
////      目测启动在模块启动之后
////ZEND_INI_MH(name) int name(zend_ini_entry *entry, char *new_value, uint new_value_length, void *mh_arg1, void *mh_arg2, void *mh_arg3, int stage TSRMLS_DC)
//
//
PHP_INI_MH(OnUpdateHxchtest) {

/*      php_printf("number=%s",new_value);
      if(new_value!="hehe"){
		php_printf("cannot set num less than 12");
          return FAILURE;
	 }     

      php_printf("set successful"); 
*/

       return SUCCESS;
}










/* If you declare any globals in php_hxch.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(hxch)
*/

ZEND_DECLARE_MODULE_GLOBALS(hxch);


/* True global resources - no need for thread safety here */
static int le_hxch;






/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("hxch.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_hxch_globals, hxch_globals)
    STD_PHP_INI_ENTRY("hxch.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_hxch_globals, hxch_globals)
PHP_INI_END()
*/
/* }}} */

//需要开启上面的ZEND_DECLARE_MODULE_GLOBALS(hxch)，同时解开php_hxch.h中的ZEND_BEGIN_MODULE_GLOBALS(hxch)
PHP_INI_BEGIN()
    // 第一个参数key，第二个参数默认值，第三个修改全选，第四个该参数被修改时的回调函数
   // STD_PHP_INI_ENTRY("hxch.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_hxch_globals, hxch_globals)
    STD_PHP_INI_ENTRY("hxch.global_value",      "42", PHP_INI_ALL, OnUpdateHxchtest, global_value, zend_hxch_globals, hxch_globals)
    STD_PHP_INI_ENTRY("hxch.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_hxch_globals, hxch_globals)
PHP_INI_END()




/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_hxch_compiled(string arg)
   Return a string to confirm that the module is compiled in */

/* 
PHP_INI_MH(OnUpdateSeparator) {
    //  php_printf("hehe");
        return SUCCESS;
}*/






PHP_FUNCTION(confirm_hxch_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "hxch", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto string self_concat(string str, int n)
    */
PHP_FUNCTION(self_concat)
{
	char *str = NULL;
	int argc = ZEND_NUM_ARGS();
	int str_len;
	long n;

	if (zend_parse_parameters(argc TSRMLS_CC, "sl", &str, &str_len, &n) == FAILURE) 
		return;
       // printf("%s",EG(active_symbol_table)->foo);



	php_error(E_WARNING, "self_concat: not yet implemented");
}
/* }}} */


/* {{{ php_hxch_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_hxch_init_globals(zend_hxch_globals *hxch_globals)
{
	hxch_globals->global_value = 0;
	hxch_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(hxch)
{

 /*	 zval *fooval;
        MAKE_STD_ZVAL(fooval);
       ZVAL_STRING(fooval, "bar", 1);
     ZEND_SET_SYMBOL(EG(active_symbol_table),"foo",fooval);
*/
	 FILE* fstream;
      char s[]="php_minit\n";
      fstream=fopen("/tmp/test.txt","at+");
      fseek(fstream,0,SEEK_END);
      fwrite(s,sizeof(s),1,fstream);

        fclose(fstream);




	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
         //注册配置条目        
	 REGISTER_INI_ENTRIES();


	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(hxch)
{
   //访问INI设置的变量
    long hxch_long=INI_INT("hxch.global_value");



	 FILE* fstream;
      char s[]="php_mshutdown\n";
      fstream=fopen("/tmp/test.txt","at+");
 	fseek(fstream,0,SEEK_END);
 
     fwrite(s,sizeof(s),1,fstream);
        fclose(fstream);


	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_FUNCTION(variable){

        zval* val;
        MAKE_STD_ZVAL(val);    
        ZVAL_STRING(val,"this is siren",1);
        ZEND_SET_SYMBOL(EG(active_symbol_table),"siren",val);
}


/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */

//这是一个宏，不是函数

PHP_RINIT_FUNCTION(hxch)
{
	zval *fooval;
        MAKE_STD_ZVAL(fooval);
       ZVAL_STRING(fooval, "bar", 1);
     //ZEND_SET_SYMBOL(EG(active_symbol_table),"foo",fooval);
     ZEND_SET_SYMBOL(&EG(symbol_table),"foo",fooval);

    zval *new_var;
    MAKE_STD_ZVAL(new_var);
    ZVAL_LONG(new_var,12);
    ZEND_SET_SYMBOL(&EG(symbol_table),"hehe",new_var);

     //数组变量
	zval *array;
    MAKE_STD_ZVAL(array);
    array_init(array);
   char *key="key";
   add_assoc_long(array,key,3);
    ZEND_SET_SYMBOL(&EG(symbol_table),"arr",array);


   //对象变量

      zval *new_object;
    MAKE_STD_ZVAL(new_object);
    if(object_init(new_object)!= SUCCESS){
//	RETURN_NULL();
    }
    add_property_string(new_object,"name","james",1);
    ZEND_SET_SYMBOL(&EG(symbol_table),"obj",new_object);


    





	 FILE* fstream;
      char s[]="php_rinit\n";
      fstream=fopen("/tmp/test.txt","at+");
      fseek(fstream,0,SEEK_END);

       fwrite(s,sizeof(s),1,fstream);
          fclose(fstream);


	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(hxch)
{
      FILE* fstream;
      char s[]="php_rshutdown\n";
      fstream=fopen("/tmp/test.txt","at+");
      fseek(fstream,0,SEEK_END);
 
     fwrite(s,sizeof(s),1,fstream);
     fclose(fstream);
	return SUCCESS;

}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(hxch)
{
	
         FILE* fstream;
      char s[]="php_minfo\n";
      fstream=fopen("/tmp/test.txt","at+");
        fseek(fstream,0,SEEK_END);

     fwrite(s,sizeof(s),1,fstream);
        fclose(fstream);

	php_info_print_table_start();
	php_info_print_table_header(2, "hxch support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
 	*/
       
 	DISPLAY_INI_ENTRIES(); 


}
/* }}} */

/* {{{ hxch_functions[]
 *
 * Every user visible function must have an entry in hxch_functions[].
 */
const zend_function_entry hxch_functions[] = {
	PHP_FE(confirm_hxch_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(self_concat,	NULL)
	PHP_FE(variable,NULL)
	PHP_FE_END	/* Must be the last line in hxch_functions[] */
};
/* }}} */

/* {{{ hxch_module_entry
 */
zend_module_entry hxch_module_entry = {
	STANDARD_MODULE_HEADER,
	"hxch",
	hxch_functions,
	PHP_MINIT(hxch),
	PHP_MSHUTDOWN(hxch),
	PHP_RINIT(hxch),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(hxch),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(hxch),
	PHP_HXCH_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HXCH
ZEND_GET_MODULE(hxch)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
