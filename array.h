#include <stdlib.h>
#include <string.h>

#include <Python.h>

#include "str_cmp.h"

char** array(void) {
	char**arr = (char**)malloc(100);

	char* s = malloc(10);
	s[0] = 'c';
	s[1] = 'a';
	s[2] = 0;

	arr[0] = s;
	return arr;


}

struct myArray;
struct String;
void push_char(struct String*, char);
void freeString(struct String);
void freeArray(struct myArray);

struct String {
	int r[2];
	// char* s;
	// size_t i;
	// size_t MAX;
};

struct myArray {
	struct String* arr;
	size_t size;
	size_t MAX;
};

struct String createString(char* s) {
	struct String str;
	/*
	str.MAX = 10;

	// str.s = calloc(str.MAX + 1, sizeof(char));
	str.s = malloc(sizeof(char) * str.MAX + 1);
	str.i = 0;

	while(*s != 0) {
		push_char(&str, *s);
		s++;

	}
	str.s[str.i] = 0;
	*/

	return str;

}

void freeString(struct String str) {
	/*
	if(str.s != NULL) {
		free(str.s);
		str.s = NULL;
		str.i = 0;
		str.MAX = 100;
	}
	*/
}

void freeArray(struct myArray arr) {
	if(arr.arr == NULL) {
		return;
	}

	/*
	size_t i = 0;
	while(i < arr.size) {
		freeString(arr.arr[i]);
		i++;
	}
	*/

	free(arr.arr);
	arr.arr = NULL;
	arr.size = 0;
	arr.MAX = 100;
}

/*
void push_char(struct String* str, char c) {
	if(str->i+2 >= str->MAX) {
		str->MAX = str->MAX * str->MAX;
		char* temp_s = str->s;
		char* new_str = malloc(sizeof(char) * str->MAX + 1);
		size_t i = 0;

		while(*str->s != 0) {
			new_str[i++] = *str->s;
			str->s++;
		}
		new_str[i] = 0;

		free(temp_s);
		str->s = NULL;

		str->s = new_str;
		str->i = i;
	}
	str->s[str->i++] = c;
	str->s[str->i] = 0;


}
*/




struct myArray createMyArray(void) {
	struct myArray my_arr;
	my_arr.MAX = 100;

	// int d[2];
	// printf("\nsize: %d/%d\n", (int)sizeof(struct String), sizeof(d) );

	my_arr.arr = malloc(sizeof(struct String) * my_arr.MAX);

	my_arr.size = 0;


	return my_arr;

}

void push_string(struct myArray* arr, struct String str) {
	if(arr->size >= arr->MAX) {
		arr->MAX = arr->MAX * 2;
		/*
		struct String* new_arr = malloc(sizeof(struct String) * arr->MAX);
		struct String* temp = new_arr;
		size_t size = 0;

		struct String*start = arr->arr+0;
		struct String*end = arr->arr+arr->size;
		while(start != end) {
			new_arr[size++] = *start;
			start++;
			// size++;
		}

		free(arr->arr);
		arr->arr = NULL;

		arr->arr = new_arr;
		arr->size = size;
		*/

		arr->arr = (struct String*)realloc(arr->arr, sizeof(struct String) * arr->MAX);
		// free(arr->arr);

	}
	arr->arr[arr->size++] = str;

	// arr.size = arr.size +1;

	// printf("[%s]\n", str.s);
	// printf("%d\n", (int)arr->size);

}

PyObject* csplit(PyObject* str, PyObject* _delimiter, long long s_l, long long sp_l) {
        long long c = 0;
        long long i = 0;

        // string*arr = (string*)malloc(sizeof(s) * 10);
	// struct myArray arr = createMyArray();
        // int push = 0;

	const char* ERR = "ERROR";

	char *s = (char*)PyUnicode_DATA(str);
	char* delimiter = (char*)PyUnicode_DATA(_delimiter);

	PyObject* objarr = PyList_New(0);
	// Py_INCREF(objarr);
	// see: https://docs.python.org/3/c-api/refcounting.html#c.Py_NewRef

        // struct String __s; //  = createString("");

        // int sp_l = strlen(delimiter);
        // int s_l = strlen(s);
	// printf("d: %d\n", s_l);
	
	long long S1 = 0;
	long long S2 = 0;
	// int single = sp_l == 1;

	long long _i = str_cmp(s, delimiter);

	if(_i == -1) {
		S2 = s_l;
		// PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
		// Py_INCREF(obj);
		PyList_Append(objarr, str);
		// Py_DECREF(obj);
		return objarr;

	}else {
		i += _i + sp_l;
		PyObject* obj = PyUnicode_DecodeUTF8(s+0, _i, ERR);
		PyList_Append(objarr, obj);
		S1 = i, S2 = i;

	}

        while(i < s_l) {
                if(s_l-i >= sp_l) {
                        for(int x = 0; x < sp_l; x++) {
                                if(s[i+x] != delimiter[x]) {
					S2++;
					// push_char(&__s, s[i]);
                                        // __s += s[i];
                                        c = 0;
                                        break;
                                }
                                else {
                                        c++;
                                }
                        }

                }
                else {
			S2 += s_l-i;
			break;
			// S2++;
			
			// push_char(&__s, s[i]);
                        // __s += s[i];
                }
// exit_loop:
                if(c == sp_l) {
                        
			// __s.r[0] = S1;
			// __s.r[1] = S2;

			// push_string(&arr, __s);

			// PyList_Append(objarr, PyTuple_Pack(2, PyLong_FromLong(S1), PyLong_FromLong(S2) ));
                        
			// PyObject* obj = PyBytes_FromStringAndSize(s+S1, S2 - S1);
			PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
			// Py_INCREF(obj);
			
			PyList_Append(objarr, obj);

			Py_DECREF(obj);

			i += c-1;
                        // __s.clear();
			
			/*
			struct String ss;
			ss.s = malloc(sizeof(char) * 1);
			ss.i = 0;
			ss.MAX = 1;
			ss.s[ss.i] = 0;
			__s = ss;
			*/


			// __s = createString("");
			
			S1 = i+1;
			S2 = i+1;



			/*
			__s.r[0] = S1;
			__s.r[1] = S2;
			*/

                        c = 0;

                }

                i++;
        }

	PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
	PyList_Append(objarr, obj);
	Py_DECREF(obj);

	// __s.r[0] = S1;
	// __s.r[1] = S2;
	// printf("%s", __s.s);
	// push_string(&arr, __s);

	// return arr;
 	return objarr;



}

PyObject* csplit_char(PyObject* str, PyObject* _delimiter, long long s_l, long long sp_l) {
        long long c = 0;
        long long i = 0;

        // string*arr = (string*)malloc(sizeof(s) * 10);
	// struct myArray arr = createMyArray();
        // int push = 0;

	const char* ERR = "ERROR";

	PyObject* objarr = PyList_New(0);
	// Py_INCREF(objarr);
	// see: https://docs.python.org/3/c-api/refcounting.html#c.Py_NewRef

        // struct String __s; //  = createString("");

        // int sp_l = strlen(delimiter);
        // int s_l = strlen(s);
	// printf("d: %d\n", s_l);
	
	char *s = (char*)PyUnicode_DATA(str);
	char* delimiter = (char*)PyUnicode_DATA(_delimiter);

	// printf("\"%s\" \n", s);
	
	long long S1 = 0;
	long long S2 = 0;

	// char* _ss = strstr(s, delimiter);

        long long _i = str_cmp(s, delimiter);

        if(_i == -1) {
                S2 = s_l;
                // PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
                // Py_INCREF(obj);
                PyList_Append(objarr, str);
                // Py_DECREF(obj);
                return objarr;

        }else {
                i += _i + sp_l;
                PyObject* obj = PyUnicode_DecodeUTF8(s+0, _i, ERR);
                PyList_Append(objarr, obj);
                S1 = i, S2 = i;

        }


        while(i < s_l) {
                if(s_l-i >= sp_l) {
			/*
			int x = 0;
			char* temp = delimiter;

			while(*delimiter != 0) {
				if(s[i+x] != *delimiter) {
					push_char(__s, s[i]);
					c = 0;
					delimiter = temp;
					break;
				}else {
					c++;
				}
				delimiter++;
				x++;
			}
			delimiter = temp;
			*/
			if(s[i] != *delimiter+0) {
				S2++;
                                c = 0;
			}
			else {
				c++;
			}

                }
                else {
			S2++;
			// push_char(&__s, s[i]);
                        // __s += s[i];
                }
// exit_loop:
                if(c == sp_l) {
                        
			// __s.r[0] = S1;
			// __s.r[1] = S2;

			// push_string(&arr, __s);

			// PyList_Append(objarr, PyTuple_Pack(2, PyLong_FromLong(S1), PyLong_FromLong(S2) ));
                        
			// PyObject* obj = PyBytes_FromStringAndSize(s+S1, S2 - S1);
			PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
			// Py_INCREF(obj);
			
			PyList_Append(objarr, obj);

			// Py_DECREF(obj);

			i += c-1;
                        // __s.clear();
			
			/*
			struct String ss;
			ss.s = malloc(sizeof(char) * 1);
			ss.i = 0;
			ss.MAX = 1;
			ss.s[ss.i] = 0;
			__s = ss;
			*/


			// __s = createString("");
			
			S1 = i+1;
			S2 = i+1;



			/*
			__s.r[0] = S1;
			__s.r[1] = S2;
			*/

                        c = 0;

                }

                i++;
        }

	PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
	PyList_Append(objarr, obj);
	// Py_DECREF(obj);

	// __s.r[0] = S1;
	// __s.r[1] = S2;
	// printf("%s", __s.s);
	// push_string(&arr, __s);

	// return arr;
 	return objarr;



}




extern char**array(void);
extern struct myArray createArray(void);
extern PyObject* csplit(PyObject*, PyObject*, long long, long long);
extern PyObject* csplit_char(PyObject*, PyObject*, long long, long long);
