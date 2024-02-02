# cy_split - re-implementation of built-in Python split function in C, Cython

This is, of course, an experimental project that shows how efficient your functions can be if properly implemented in the C programming language.

Best Case `O(n)`

Worst Case `O(n*m)`

to build, run the test and draw up the graph:

`bash ./src/build.sh && bash test.sh && python3 draw_graphs.py`
```
python3 draw_graphs.py --help
usage: DrawGraph [-h] [--string STRING] [--sep SEP] [--trace TRACE]
                 [--start_range START_RANGE] [--end_range END_RANGE]
                 [--step STEP]

Draw the Time Complexity Graph

options:
  -h, --help            show this help message and exit
  --string STRING
  --sep SEP
  --trace TRACE
  --start_range START_RANGE
  --end_range END_RANGE
  --step STEP

help
```

# Quick Example as C API

```c
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

	// PyObject_Print(slist, stdout, Py_PRINT_RAW);
	// printf("\n");

	Py_DECREF(s), Py_DECREF(delimiter), Py_DECREF(slist);

}

int main(int argc, char* argv[]) {
	Py_Initialize();

	example();

	Py_Finalize();
	return 0;
}
```

# Quick Example in Python

```py
import cy

cy.split('a-a-a', '-')

```

# Time, Space Complexity Charts

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/Figure_1.png)

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/Figure_2.png)

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/Figure_3.png)

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/Figure_4.png)

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/Figure_5.png)

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/Figure_6.png)

# Memory Usage Chart

![alt text](https://github.com/BeAllAround/cy_split/blob/main/benchmarks/graphs/MemoryUsage_Figure.png)
