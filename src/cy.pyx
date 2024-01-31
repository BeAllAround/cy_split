from time import time

ctypedef unsigned long long INT_size
cdef extern from "csplit.h":
    cdef list csplit(str, str, INT_size, INT_size);
    cdef list csplit_char(str, str, INT_size, INT_size);


def __cy_split(str s, str delimiter):
    if len(delimiter) == 1:
        return csplit_char(s, delimiter, len(s), len(delimiter))
    return csplit(s, delimiter, len(s), len(delimiter))

def split(str s, str delimiter = ''):
    if not len(delimiter):
        return [ *s ]
    return __cy_split(s, delimiter)

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
