#include <stdlib.h>
#include <string.h>

#include <Python.h>

#include "../lib/str_cmp.h"


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

	char* __i = strstr(s, delimiter);
	// long long _i = str_cmp(s, delimiter);
	// long long _i = -1;

	if(__i == NULL) {
		S2 = s_l;
		// PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
		// Py_INCREF(obj);
		PyList_Append(objarr, str);
		// Py_DECREF(obj);
		return objarr;

	}else {
		/*
		i += _i + sp_l;
		PyObject* obj = PyUnicode_DecodeUTF8(s+0, _i, ERR);
		PyList_Append(objarr, obj);
		S1 = i, S2 = i;
		*/

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

	char* __i = strstr(s, delimiter);
        // long long _i = str_cmp(s, delimiter);
	// long long _i = -1;

        if(__i == NULL) {
                S2 = s_l;
                // PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
                // Py_INCREF(obj);
                PyList_Append(objarr, str);
                // Py_DECREF(obj);
                return objarr;

        }else {
		/*
                i += _i + sp_l;
                PyObject* obj = PyUnicode_DecodeUTF8(s+0, _i, ERR);
                PyList_Append(objarr, obj);
                S1 = i, S2 = i;
		*/
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

extern PyObject* csplit(PyObject*, PyObject*, long long, long long);
extern PyObject* csplit_char(PyObject*, PyObject*, long long, long long);
