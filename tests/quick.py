from time import time
import re

import numpy
from context import cy

import py


def add_row(s, t, w = 15):
    t = str(t)
    return ( '|' + s + (' ' * (w//2 - len(s))) + '|') + (t + (' ' * (w//2 - len(t))) + '|\n' + '|' + '-' * w + '|')
    

def print_grid(rows, h = 25, w = 45):
    # starting '|'
    if w%2 == 0:
        w+=1 
    else:
        w+=2

    screen = []

    screen.append('|' + '-' * w + '|')
    for row in rows:
        screen.append(add_row(*row, w))

    print( '\n'.join(screen) )

class Program:

    @classmethod
    def main(cls):
        # print(double_split("aA--b-\ncSuper\nTrial\nSome\n\n\nWorking hours", "-", '\n', 'a', ' '));

        rows = []

        s = 'a  '*100_000

        delimiter = ' '
        start = time()
        cy._split(s, delimiter)
        rows.append(['cy._split', time() - start])

        start = time()
        s.split(delimiter)
        rows.append(['<builtin> split', time() - start])

        start = time()
        py._split(s, delimiter)
        rows.append(['py._split', time() - start])

        start = time()
        split_pattern = "\W+"
        re.split(split_pattern, s)
        rows.append([f"re.split(\"{split_pattern}\")", time() - start])



        # s1 = bytes(s, 'utf-8')
        start = time()
        cy.split(s, delimiter)
        rows.append(['cy.split', time() - start])
        # print('a  '.split('a') == list(remake(bytes('a  ', 'utf-8'), bytes('a', 'utf-8') )))


        start = time()
        numpy.char.split(s, delimiter)
        rows.append(['numpy.char.split', time() - start])

        print("#TIMING")
        print_grid(rows)


if __name__ == '__main__':
    Program.main()
