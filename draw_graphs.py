import tracemalloc

from time import time


import matplotlib.pyplot as plt

from _splits import remake



trace = True

m = []
sc = []
tc = []

m1 = []
sc1 = []
tc1 = []


step, start_range, end_range = 100, 100_000, 102_000
# deli = '     ' * 100000
deli = 'b'

for i in range(start_range, end_range, step):
    s = 'a  ' * i

    sc1.append(len(s))

    start = time()

    trace and tracemalloc.start()
    s.split(deli)

    trace and m1.append(tracemalloc.get_traced_memory()[1])
    trace and tracemalloc.stop()

    tc1.append((time() - start) * 1000)

for i in range(start_range, end_range, step):
    s = 'a  ' * i
    
    sc.append(len(s))

    start = time()

    trace and tracemalloc.start()
    remake(s, deli)

    trace and m.append(tracemalloc.get_traced_memory()[1])
    trace and tracemalloc.stop()

    tc.append((time() - start) * 1000)

if __name__ == '__main__':
    print(tc[0], len(tc), len(tc1), tc1[0])
    print(sc[0], len(sc), len(sc1), sc1[0])
    print(len(m), len(m1))
    avg = sum(tc)/len(tc)
    avg1 = sum(tc1)/len(tc1)
    print('avg: ', ((avg-avg1) / avg1) * 100, '%' )
    plt.plot(sc, tc, label = '<cy_split>')
    plt.plot(sc1, tc1, label = '<built-in method split>')

    plt.ylabel('Time Complexity')
    plt.xlabel('Space Complexity')
    plt.legend()
    plt.show()

