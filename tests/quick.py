from time import time
import re

import numpy
from context import cy

import py

class Program:

    @classmethod
    def main(cls):
        # print(double_split("aA--b-\ncSuper\nTrial\nSome\n\n\nWorking hours", "-", '\n', 'a', ' '));

        print("#TIMING")

        s = 'a  '*100_000

        delimiter = ' '
        start = time()
        cy._split(s, delimiter)
        print('cy._split', time() - start)

        start = time()
        s.split(delimiter)
        print("native split", time() - start)

        start = time()
        py._split(s, delimiter)
        print('py._split', time() - start)

        start = time()
        split_pattern = "\W+"
        re.split(split_pattern, s)
        print(f"re.split(\"{split_pattern}\")", time() - start)



        # s1 = bytes(s, 'utf-8')
        start = time()
        cy.split(s, delimiter)
        # print('a  '.split('a') == list(remake(bytes('a  ', 'utf-8'), bytes('a', 'utf-8') )))
        print("cy.split", time() - start)

        start = time()
        numpy.char.split(s, delimiter)
        print("numpy.char.split", time() - start)

if __name__ == '__main__':
    Program.main()
