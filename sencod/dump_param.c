/*
 +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:yijianlingchen@outlook.com                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_dump_param.h"

/* If you declare any globals in php_dump_param.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(dump_param)
*/

/* True global resources - no need for thread safety here */
static int le_dump_param;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("dump_param.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_dump_param_globals, dump_param_globals)
    STD_PHP_INI_ENTRY("dump_param.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_dump_param_globals, dump_param_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_dump_param_compiled(string arg)
   Return a string to confirm that the module is compiled in */

static void my_zval_dump_real(zval *z, int level)
{
    switch (Z_TYPE_P(z))
    {
        case IS_NULL:
            php_printf("null value = null");
            break;
        
        case IS_TRUE:
            php_printf("bool value = true");
            break;
            
        case IS_FALSE:
            php_printf("bool value = false");
            break;
            
        case IS_LONG:
            php_printf("int value = (" ZEND_LONG_FMT ")\n", Z_LVAL_P(z));
            break;
            
        case IS_STRING:
            php_printf("string value = '%s', len = '%d'\n", Z_STRVAL_P(z), Z_STRLEN_P(z));
            break;
        
        case IS_DOUBLE:
            php_printf("float(%.*G)\n", (int) EG(precision), Z_DVAL_P(z));
            break;
            
        default:
            php_printf("other type\n");
            break;
    }
}


PHP_FUNCTION(dump_param)
{
	zval *args;
	int  argc;
	int 	i;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "+", &args, &argc) == FAILURE) {
		return;
	}

	for (i = 0; i < argc; i++) {
		my_zval_dump_real(&args[i], 1);
	}    	

}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_dump_param_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_dump_param_init_globals(zend_dump_param_globals *dump_param_globals)
{
	dump_param_globals->global_value = 0;
	dump_param_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(dump_param)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(dump_param)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(dump_param)
{
#if defined(COMPILE_DL_DUMP_PARAM) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(dump_param)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(dump_param)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "dump_param support", "enabled");
	php_info_print_table_row(2, "author", "yijianlingchen");
	php_info_print_table_row(2, "email", "yijianlingchen@outlook.com");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ dump_param_functions[]
 *
 * Every user visible function must have an entry in dump_param_functions[].
 */
const zend_function_entry dump_param_functions[] = {
	PHP_FE(dump_param,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in dump_param_functions[] */
};
/* }}} */

/* {{{ dump_param_module_entry
 */
zend_module_entry dump_param_module_entry = {
	STANDARD_MODULE_HEADER,
	"dump_param",
	dump_param_functions,
	PHP_MINIT(dump_param),
	PHP_MSHUTDOWN(dump_param),
	PHP_RINIT(dump_param),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(dump_param),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(dump_param),
	PHP_DUMP_PARAM_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_DUMP_PARAM
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(dump_param)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
