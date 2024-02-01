#include <stdlib.h>
#include <string.h>

#include <Python.h>

#include "../lib/str_cmp.h"

typedef unsigned long long INT_size;


PyObject* csplit(PyObject* str, PyObject* _delimiter, INT_size s_l, INT_size sp_l) {
        INT_size c = 0;
        INT_size i = 0;


	const char* ERR = "ERROR";

	register char *s = (char*)PyUnicode_DATA(str);
	register char* delimiter = (char*)PyUnicode_DATA(_delimiter);

	PyObject* objarr = PyList_New(0);
	if(sp_l > s_l) {
		PyList_Append(objarr, str);
		return objarr;
	}
	// Py_INCREF(objarr);
	// see: https://docs.python.org/3/c-api/refcounting.html#c.Py_NewRef

	INT_size S1 = 0;
	INT_size S2 = 0;

	// char* __i = strstr(s, delimiter);
	// char* __i = NULL;
	INT_size _i = str_cmp(s, delimiter);
	// INT_size _i = -1;

	if(_i == -1) {
		S2 = s_l;
		PyList_Append(objarr, str);
		return objarr;

	}else {
		i += _i + sp_l;
		PyObject* obj = PyUnicode_DecodeUTF8(s+0, _i, ERR);
		PyList_Append(objarr, obj);
		S1 = i, S2 = i;
	}

        while(i < s_l) {
                if(s_l-i >= sp_l) {
                        for(INT_size x = 0; x < sp_l; x++) {
                                if(s[i+x] != delimiter[x]) {
					S2++;
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
                }

                if(c == sp_l) {
                        
			PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
			
			PyList_Append(objarr, obj);

			Py_DECREF(obj);

			i += c-1;
			
			S1 = i+1;
			S2 = i+1;

                        c = 0;

                }

                i++;
        }

	/*
	if(S2 - S1 == s_l-1) {
		PyList_Append(objarr, str);
		return objarr;
	}
	*/

	PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
	PyList_Append(objarr, obj);
	Py_DECREF(obj);

 	return objarr;
}

PyObject* csplit_char(PyObject* str, PyObject* _delimiter, INT_size s_l, INT_size sp_l) {
        INT_size c = 0;
        INT_size i = 0;

	const char* ERR = "ERROR";

	PyObject* objarr = PyList_New(0);
	// Py_INCREF(objarr);
	// see: https://docs.python.org/3/c-api/refcounting.html#c.Py_NewRef

	char *s = (char*)PyUnicode_DATA(str);
	char* delimiter = (char*)PyUnicode_DATA(_delimiter);

	INT_size S1 = 0;
	INT_size S2 = 0;

	char __char = *delimiter;

	// char* __i = strstr(s, delimiter);
        INT_size _i = str_cmp(s, delimiter);
	// INT_size _i = -1;

        if(_i == -1) {
                S2 = s_l;
                PyList_Append(objarr, str);
                return objarr;

        }else {
                i += _i + sp_l;
                PyObject* obj = PyUnicode_DecodeUTF8(s+0, _i, ERR);
                PyList_Append(objarr, obj);
                S1 = i, S2 = i;
        }



        while(i < s_l) {
		if(s[i] !=  __char) {
			S2++;
                        c = 0;
		}
		else {
			c = 1;
		}

                if(c) {
                        
			PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
			
			PyList_Append(objarr, obj);

			Py_DECREF(obj);

			i += c-1;
			
			S1 = i+1;
			S2 = i+1;
                        c = 0;

                }

                i++;
        }

	PyObject* obj = PyUnicode_DecodeUTF8(s+S1, S2 - S1, ERR);
	PyList_Append(objarr, obj);
	Py_DECREF(obj);

 	return objarr;
}

extern PyObject* csplit(PyObject*, PyObject*, INT_size, INT_size);
extern PyObject* csplit_char(PyObject*, PyObject*, INT_size, INT_size);
