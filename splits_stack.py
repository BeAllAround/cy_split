import sys

from time import time

from _splits import split as cysplit

def join(arr, adder):
    s = '';
    for x in range(len(arr)-1):
        s += arr[x] + adder;
    if len(arr) != 0:
        s += arr[-1];
    return s;


class S:
    def __init__(self, s):
        self.s = s


def _split(s:str, splitter:str):
    # s += splitter; # the last element
    b = True
    c = 0
    i = 0
    stack = [ range(0, len(s)) ]
    arr = []
    # _s = '';
    s_l = len(splitter)
    __s = S('')

    while len(stack) != 0:
        c = 0
        # print(stack, nn)
        # print(stack, nn)
        for i in stack.pop():
            # print(c, i)
            if len(s) - i >= s_l:
                for x in range(s_l):
                    # print(s[i+x] == splitter[x] )
                    if s[i+x] != splitter[x]:
                        # b = False
                        __s.s += s[i]
                        c = 0
                        b = False
                        break
                    else:
                        c += 1
                        # _s += s[i+x];
            else:
                b = False
                __s.s += s[i]

            # print(c, s_l)
            if c == s_l:
                arr.append(__s.s)
                # print(i+c, len(s))
                stack.append(range(i+c, len(s)))
                # i += c-1
                __s.s = ''
                c = 0
                break

            if not b:
                # print(i+1)
                stack.append(range(i+1, len(s)))
                break



        b = True
        # i += 1

    arr.append(__s.s) # the last element final fix

    return arr

def split(s:str, splitter:str=''):
    if not bool(splitter):
        return [ *s ]
    return _split(s, splitter)


# TODO: ADD if __name__ == '__main__' 

str1 = "  A B  C  ";
str2 = "A B C";
str3 = "";
str4 = "ABBBCCDJKBCCDDDBCBCDR.TEABCCVA";
t = 1;

sys.stdout.write("TESTS #" + str(t) + '\n');

print(split('s d1', 'd12') == 's d1'.split('d12'))
print(split(str4, "BCC") == str4.split("BCC"));
print(split(str1, " ") == str1.split(" "));
print(split(str2, " ") == str2.split(" "));
print(split(str3, "d") == str3.split("d"));
print(split(str2, "D") == str2.split("D"));
print(split(' ', ' ') == ' '.split(' '));

t+=1; # the end of the first test block

def double_split(string, _split, *splits):
    a1 = split(string, _split); # string.split(_split); # the python_std version
    a2 = [];
    for one in splits:
        for j in a1:
            a2.extend(split(j, one)); # a2.extend(j.split(one));
        a1 = list(a2);
        a2.clear();
    return a1;

sys.stdout.write("TESTS #" + str(t) + '\n');
print(double_split("aA--b-\ncSuper\nTrial\nSome\n\n\nWorking hours", "-", '\n', 'a', ' '));
print(split("turbo"));


print('#TIMING')



s = 'a  '*100_000

start = time()
split(s, ' ')
print(time() - start)

start = time()
s.split(' ')
print(time() - start)

start = time()
cysplit(s, ' ')
print(time() - start)




