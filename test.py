from time import time
import tracemalloc

from numpy import char

import cy


# start = time()
# char.split(s, ' ')
# s1 = bytes(s, 'utf-8')
# print(time() - start)

deli = ' '
# deli = '   '

s = 'a  '*100_000
def _remake(**kwargs):
    trace = kwargs.get('trace') == True

    start = time()

    trace and tracemalloc.start()

    cy.split(s, deli)

    # print('a  '.split('a') == list(remake(bytes('a  ', 'utf-8'), bytes('a', 'utf-8') )))

    trace and print(tracemalloc.get_traced_memory())

    print('cy_split: ', time() - start)

    trace and tracemalloc.stop()


def _native(**kwargs):
    trace = kwargs.get('trace') == True

    start = time()

    trace and tracemalloc.start()

    s.split(deli)

    trace and print(tracemalloc.get_traced_memory())

    print('split: ', time() - start)

    trace and tracemalloc.stop()

def _why():
    pass

if __name__ == '__main__':
    _why()
    _native(trace=True)
    _remake(trace=True)
    _remake(trace=True)
    _native(trace=True)
