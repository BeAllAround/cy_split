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

def double_split(string, _split, *splits):
    a1 = split(string, _split) # string.split(_split); # the python_std version
    a2 = []
    for one in splits:
        for j in a1:
            a2.extend(split(j, one)) # a2.extend(j.split(one));
        a1 = list(a2)
        a2.clear()
    return a1
