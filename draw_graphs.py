import tracemalloc
from time import time


import matplotlib.pyplot as plt
import numpy

import cy

import tests.py as py

class ComplexityGraph:
    def __init__(self):
        self._s = 'a  '
        self.deli = ' '
        self.trace = True
        self.parameters()

    def parameters(self, step=100, start_range=10_000, end_range=11_000):
        self.step = step
        self.start_range = start_range
        self.end_range = end_range

    def mockup_builtin(self, func, deli):
        tc, sc, m = [], [], []
        for i in range(self.start_range, self.end_range, self.step):
            s = self._s * i + 'bb'
            sc.append(len(s))

            start_time = time()

            self.trace and tracemalloc.start()
            s.split(deli)
            # numpy.char.split(s, deli)
            # func(s, deli)
            
            self.trace and m.append(tracemalloc.get_traced_memory()[1])
            self.trace and tracemalloc.stop()

            tc.append((time() - start_time) * 1000)
        return (tc, sc, m)

    def mockup_remake(self, func, deli):
        tc, sc, m = [], [], []
        for i in range(self.start_range, self.end_range, self.step):
            s = self._s * i + 'bb'
            sc.append(len(s))

            start_time = time()

            self.trace and tracemalloc.start()
            cy.split(s, deli)
            # py._split(s, deli)
            # func(s, deli)

            self.trace and m.append(tracemalloc.get_traced_memory()[1])
            self.trace and tracemalloc.stop()

            tc.append((time() - start_time) * 1000)
        return (tc, sc, m)

    def plot(self):
        def builtin_split(s, deli):
            s.split(deli)

        tc, sc, m = self.mockup_remake(cy.split, self.deli)
        tc1, sc1, m1 = self.mockup_builtin(builtin_split, self.deli)

        print(tc[0], len(tc), len(tc1), tc1[0])
        print(sc[0], len(sc), len(sc1), sc1[0])
        print(len(m), len(m1))
        avg = sum(tc)/len(tc)
        avg1 = sum(tc1)/len(tc1)

        f_on_avg = ((avg-avg1) / avg1) * 100
        print('avg: ', f_on_avg, '%' )

        plt.plot(sc, tc, label = str(cy.split))
        plt.plot(sc1, tc1, label = str(''.split))

        plt.ylabel('Time Complexity (' +
                str(round(f_on_avg)) + '%' + '), ' 
                + 'separator: ' + '"' + self.deli + '"' )
        plt.xlabel('Space Complexity')
        plt.legend()
        plt.show()

class Program:
    @classmethod
    def main(cls):
        graph = ComplexityGraph()
        graph.plot()



if __name__ == '__main__':
    Program.main()

