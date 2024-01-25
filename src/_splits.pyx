from time import time

cdef extern from "array.h":
    cdef list csplit(str, str, long long, long long);
    cdef list csplit_char(str, str, long long, long long);



def callback():
    pass


def remake(str s, str delimiter):
    if len(delimiter) == 1:
        return _remake_char(s, delimiter, len(s), len(delimiter))

    # if delimiter not in s:
     #    return [ s ]
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

def split(s:str, splitter:str=''):
    if not bool(splitter):
        return [*s]
    return _split(s, splitter)
