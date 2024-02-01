#include "../src/csplit.h"

// gcc -O3 -I/usr/include/python3.10 example.c -lpython3.10 -o out.out


void example() {
	PyObject* s = PyUnicode_DecodeUTF8("a-a-a", 5, "ERR");
	PyObject* delimiter = PyUnicode_DecodeUTF8("-", 2, "ERR");
	PyObject* slist = csplit(s, delimiter, 5, 1);
	Py_INCREF(s), Py_INCREF(delimiter), Py_INCREF(slist);

	// printf("%s, %s\n", (char*)PyUnicode_DATA(s), (char*)PyUnicode_DATA(delimiter));
	Py_ssize_t size = PyList_Size(slist);
	printf("[");
	for(Py_ssize_t i = 0; i < size; i++) {
		printf("'%s'", (char*)PyUnicode_DATA(PyList_GetItem(slist, i)));
		if(i < size-1) {
			printf(", ");
		}
	}
	printf("]\n");

	Py_DECREF(s), Py_DECREF(delimiter), Py_DECREF(slist);

}

int main(int argc, char* argv[]) {
	Py_Initialize();

	example();

	Py_Finalize();
	return 0;
}
