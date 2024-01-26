import sys
import re
from time import time

from numpy import char

from lib.asserts import Assert
from _splits import split as cysplit
from _splits import remake


def join(arr, adder):
    s = ''
    for x in range(len(arr)-1):
        s += arr[x] + adder
    if len(arr) != 0:
        s += arr[-1]
    return s

def _split(s:str, splitter:str):
    # s += splitter; # the last element
    # b = True
    c = 0
    i = 0
    arr = []
    # _s = '';
    __s = ''
    sp_l = len(splitter)
    s_l = len(s)

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

'''
def split(s:str, splitter:str=''):
    if not bool(splitter):
        return [ *s ]
    return _split(s, splitter)
'''

def split(s: str, delimiter: str =''):
    if not bool(delimiter):
        return [ *s ]
    return remake(s, delimiter)

def asserts():
    str1 = "  A B  C  "
    str2 = "A B C"
    str3 = ""
    str4 = "ABBBCCDJKBCCDDDBCBCDR.TEABCCVA"

    sys.stdout.write("asserts..." + '\n')

    Assert.assert_v(remake('a', 'a'), 'a'.split('a'))
    Assert.assert_v(split('s d1', 'd12'), 's d1'.split('d12'))
    Assert.assert_v(split(str4, "BCC"), str4.split("BCC"))
    Assert.assert_v(split(str1, " "), str1.split(" "))
    Assert.assert_v(split(str2, " "), str2.split(" "))
    Assert.assert_v(split(str3, "dd"), str3.split("dd"))
    Assert.assert_v(split(str2, "D"), str2.split("D"))
    Assert.assert_v(split(' ', ' '), ' '.split(' '))
    Assert.assert_v(split('  ', ' '), '  '.split(' '))
    Assert.assert_v(split('  ', '  '), '  '.split('  '))
    Assert.assert_v(split('aaaaa', 'b'), 'aaaaa'.split('b'))
    Assert.assert_v(split('1,2,,3,', ','), '1,2,,3,'.split(','))

    for w_s in [ ' ', '\t', '\n', '\v', '\f', '\r']:
        Assert.assert_v(split(w_s.join(['1', '2', '3', '4']), w_s), w_s.join(['1', '2', '3', '4']).split(w_s))

def double_split(string, _split, *splits):
    a1 = split(string, _split) # string.split(_split); # the python_std version
    a2 = []
    for one in splits:
        for j in a1:
            a2.extend(split(j, one)) # a2.extend(j.split(one));
        a1 = list(a2)
        a2.clear()
    return a1



if __name__ == '__main__' :
    # print(double_split("aA--b-\ncSuper\nTrial\nSome\n\n\nWorking hours", "-", '\n', 'a', ' '));
    asserts()

    print('#TIMING')

    s = 'a  '*100_000

    delimiter = ' '
    start = time()
    split(s, delimiter)
    print(time() - start)

    start = time()
    s.split(delimiter)
    print("native split: ", time() - start)

    start = time()
    cysplit(s, delimiter)
    print(time() - start)


    start = time()
    re.split('\W+', s)
    print(time() - start)



    # s1 = bytes(s, 'utf-8')
    start = time()
    remake(s, delimiter)
    # print('a  '.split('a') == list(remake(bytes('a  ', 'utf-8'), bytes('a', 'utf-8') )))
    print('remake: ', time() - start)

    start = time()
    char.split(s, delimiter)
    print(time() - start)


