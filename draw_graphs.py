import tracemalloc

from time import time


import matplotlib.pyplot as plt
import numpy

from _splits import remake

from splits import _split



trace = True

m = []
sc = []
tc = []

m1 = []
sc1 = []
tc1 = []


step, start_range, end_range = 100, 10_000, 11_000
# deli = '     ' * 100000
# heavy case
# _s =  'a  ' + ('  ' * 10000)
# deli = ' ' * 10000 
_s = 'a  '
deli = ' '

for i in range(start_range, end_range, step):
    s = _s * i + 'bb'

    # cy_split
    # s = 'a  ' * i

    sc.append(len(s))

    start = time()

    trace and tracemalloc.start()
    # _split(s, deli)
    remake(s, deli)

    trace and m.append(tracemalloc.get_traced_memory()[1])
    trace and tracemalloc.stop()

    tc.append((time() - start) * 1000)


for i in range(start_range, end_range, step):
    s = _s * i + 'bb'

    # split
    sc1.append(len(s))

    start = time()

    trace and tracemalloc.start()
    # numpy.char.split(s, deli)
    s.split(deli)

    trace and m1.append(tracemalloc.get_traced_memory()[1])
    trace and tracemalloc.stop()

    tc1.append((time() - start) * 1000)


if __name__ == '__main__':
    print(tc[0], len(tc), len(tc1), tc1[0])
    print(sc[0], len(sc), len(sc1), sc1[0])
    print(len(m), len(m1))
    avg = sum(tc)/len(tc)
    avg1 = sum(tc1)/len(tc1)
    print('avg: ', ((avg-avg1) / avg1) * 100, '%' )
    plt.plot(sc, tc, label = str(remake))
    plt.plot(sc1, tc1, label = str(''.split))

    plt.ylabel('Time Complexity (' + str(round(((avg-avg1) / avg1) * 100)) + '%' + '), ' + 'separator: ' + '"' + deli + '"' )
    plt.xlabel('Space Complexity')
    plt.legend()
    plt.show()

