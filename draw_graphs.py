import tracemalloc
from time import time

import argparse

import matplotlib.pyplot as plt
import numpy

import cy

import tests.py as py

class ComplexityGraph:
    def __init__(self, s = 'a  ', deli = ' ', trace = False, start_range = 10_000, end_range = 11_000, step = 100):
        self._s = s
        self.deli = deli
        self.trace = trace
        self.parameters(step, start_range, end_range)

    def parameters(self, step=100, start_range=10_000, end_range=11_000):
        self.step = step
        self.start_range = start_range
        self.end_range = end_range

    '''
    def mockup_builtin(self, func, deli):
        tc, sc, m, smtc = [], [], [], 0
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

            t = (time() - start_time) * 1000 # miliseconds
            tc.append(t)
            smtc += t

        return (tc, sc, m, smtc)
    '''

    def mockup(self, func, deli):
        tc, sc, m, smtc = [], [], [], 0
        for i in range(self.start_range, self.end_range, self.step):
            s = self._s * i + 'bb'
            sc.append(len(s))

            start_time = time()

            self.trace and tracemalloc.start()
            # cy.split(s, deli)
            # py._split(s, deli)
            func(s, deli)

            self.trace and m.append(tracemalloc.get_traced_memory()[1])
            self.trace and tracemalloc.stop()

            t = (time() - start_time) * 1000 # miliseconds
            tc.append(t)
            smtc += t

        return (tc, sc, m, smtc)

    def plot(self):

        def builtin_split(s, deli):
            # return numpy.char.split(s, deli)
            return s.split(deli)

        tc_cy, sc_cy, m_cy, smtc_cy = self.mockup(cy.split, self.deli)
        tc_built, sc_built, m_built, smtc_built = self.mockup(builtin_split, self.deli)

        # print(tc[0], len(tc), len(tc1), tc1[0])
        # print(sc[0], len(sc), len(sc1), sc1[0])
        # print(len(m), len(m1))

        avg_cy = smtc_cy/len(tc_cy)
        avg_built = smtc_built/len(tc_built)

        # assert sum(tc_cy) == smtc_cy
        # assert sum(tc_built) == smtc_built

        f_on_avg = ((avg_cy-avg_built) / avg_built) * 100

        print('avg: ', f_on_avg, '%' )

        plt.figure(figsize=(10, 7))
        plt.title('Big O')

        plt.plot(sc_cy, tc_cy, label = str(cy.split))
        plt.plot(sc_built, tc_built, label = str(''.split))

        plt.ylabel('Time Complexity (' +
                str(round(f_on_avg)) + '%' + '), ' 
                + 'separator: ' + '"' + self.deli + '"' )
        plt.xlabel('Space Complexity')
        plt.legend()
        plt.show()


class Program:
    @classmethod
    def main(cls):
        parser = argparse.ArgumentParser(
                    prog='DrawGraph',
                    description='Draw the Time Complexity Graph',
                    epilog='help')
        parser.add_argument('--string', help='s.split where s is the string to split', default='a  ', type=str)
        parser.add_argument('--sep', help="s.split(sep) where sep is the string to split against", default=' ', type=str)
        parser.add_argument('--trace', help="True | False - trace memory usage", default=False, type=bool)
        parser.add_argument('--start_range', help="Space Complexity - starting x", default=10_000, type=int)
        parser.add_argument('--end_range', help="Space Complexity - ending x", default=11_000, type=int)
        parser.add_argument('--step', help="increment between starting x and ending x", default=100, type=int)
        args = parser.parse_args()

        graph = ComplexityGraph(*vars(args).values())
        graph.plot()


if __name__ == '__main__':
    Program.main()

