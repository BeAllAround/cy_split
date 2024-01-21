#include <assert.h>
#include <stdio.h>
#include "str_cmp.h"

#define assert_str_cmp_vv(str, sub, expected) \
	assert(str_cmp(str, sub) == expected)

#define assert_str_cmp_v(str, sub, expected, v) \
	if(v) { \
		printf("%s, %s, %d\n", str, sub, expected); \
	} \
	assert_str_cmp_vv(str, sub, expected);


#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define assert_str_cmp(...) GET_MACRO(__VA_ARGS__, assert_str_cmp_v, assert_str_cmp_vv)(__VA_ARGS__)

#define assert_str_cmp_run(str, strings, expts, v) \
	assert(sizeof(strings)/sizeof(char*) == sizeof(expts)/sizeof(int)); \
	for(size_t i = 0; i < sizeof(strings)/sizeof(char*); i++) { \
		if(v) { \
		  assert_str_cmp(str, strings[i], expts[i], v); \
	 	} \
		else { \
		  assert_str_cmp(str, strings[i], expts[i]); \
		} \
	}


int main(void) {
	const char* strings[] = { "e", "r", "up", "_sup", "superr" };
	const int expts[] = { 3, 4, 1, -1, -1 };

	assert_str_cmp_run("super", strings, expts, 1);

	return 0;
}
