from time import time
# from libc.stdlib cimport malloc
# import numpy as np
# from cython cimport boundscheck, wraparound

cdef extern from "<stdlib.h>":
    void printf(const char*, ...);

cdef extern from "array.h":
    char** array();
    cdef struct String:
        int r[2];

        # char* s;
        # size_t i;
        # size_t MAX;

    cdef struct myArray:
        String* arr;
        size_t size;
        size_t MAX;

    # myArray createMyArray();
    # cdef list csplit(char*, char*);
    cdef list csplit(str, str, long long, long long);
    cdef list csplit_char(str, str, long long, long long);
    void freeString(String);
    void freeArray(myArray);



def callback():
    pass


def remake(str s, str delimiter):
    # start = time()
    # print('end bytes: ', time() - start)
    # s2 = bytes(delimiter, 'utf-8')
    if len(delimiter) == 1:
        return _remake_char(s, delimiter, len(s), len(delimiter))

    return _remake(s, delimiter, len(s), len(delimiter))

def _remake_char(str sref, str delimiter, long long s_l, long long sp_l):
    cdef list arr1 = csplit_char(sref, delimiter, s_l, sp_l)
    return arr1

def _remake(str sref, str delimiter, long long s_l, long long sp_l):
    # cdef list arr = []

    # start = time()
    cdef list arr1 = csplit(sref, delimiter, s_l, sp_l);
    # print('end: ', time() - start) 
    # print(arr1)

    return arr1

    # print( (arr1.arr[0], arr1.size) );
    # print('size: ', arr1.size);

    # print(arr1)
    # a = [ s[arr1.arr[x].r[0]: arr1.arr[x].r[1]].decode() for x in range(arr1.size) ]
    # cdef int x = 0;

    '''
    class E:
        def __init__(self, ):
            pass
    '''

    '''
    for x in range(arr1.size):
        r = arr1.arr[x].r
        # if r[1] - r[0] <= 0:
            # arr.append('')
            # yield ''

        

        _s = s[r[0] : r[1]].decode()
        try:
            # arr.append(_s)
            # yield _s
            # print(_s)
        except UnicodeDecodeError:
            print(s[r[0] : r[1]])
            print(r[0], r[1])
            print(s[r[0] : r[1]].decode())
        arr.append(_s)

        # yield _s
        # arr.append(0)
        # print(arr1.arr[x])
        # yield ( s[r[0]:  r[1]].decode() )   
        # print(arr1.arr[x].r)
        # yield arr1.arr[x].s.decode();
        # freeString(arr1.arr[x])
        # arr.append(arr1.arr[x].s);
        # print(x)
    
    freeArray(arr1)

    return arr
    '''



def _split(s:str, splitter:str):
    # s += splitter; # the last element
    # b = True
    cdef int c = 0
    cdef int i = 0
    cdef list arr = []
    # _s = '';
    cdef str __s = ''

    cdef int sp_l = len(splitter)
    cdef int s_l = len(s)

    cdef char*a = "BB";

    cdef char**aa = array();


    # printf("%s", "AA" );
    # print(a);
    # print(aa[0]);


    while i < s_l:
        if s_l - i >= sp_l:
            for x in range(sp_l):
                if s[i+x] != splitter[x]:
                    # b = False
                    __s += s[i]
                    c = 0
                    break
                else:
                    c += 1
                    # _s += s[i+x];
        else:
            # b = False
            __s += s[i]

        if c == sp_l:
            arr.append(__s)
            i += c-1
            __s = ''
            c = 0

        # b = True
        i += 1

    arr.append(__s) # the last element final fix

    return arr

def split(s:str, splitter:str=''):
    if not bool(splitter):
        return [*s]
    return _split(s, splitter)
