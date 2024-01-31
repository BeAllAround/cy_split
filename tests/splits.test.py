import sys
import re
import unittest
from time import time

import numpy
from context import cy

from lib.asserts import Assert

class TestSplit(unittest.TestCase):
    def __init__(self, *args):
        super().__init__(*args)
        self.ctx = {}
        self.input = [
                [ 'a', 'a' ],
                [ 's d1', 'd12' ],
                [ 'ABBBCCDJKBCCDDDBCBCDR.TEABCCVA', 'BCC' ],
                [ '  A B  C  ', ' ' ],
                [ 'A B C', ' ' ],
                [ '', 'dd' ],
                [ 'A B C', 'D' ],
                [ ' ', ' ' ],
                [ '  ', ' ' ],
                [ '  ', '  ' ],
                [ 'aaaaa', 'b' ],
                [ '1,2,,3,', ',']
        ]

    def test_correctness(self):
        for s, deli in self.input:
            self.assertEqual(cy.split(s, deli), s.split(deli))

    def test_whitespace(self):
        for w_s in [ ' ', '\t', '\n', '\v', '\f', '\r']:
            self.assertEqual(cy.split(w_s.join(['1', '2', '3', '4']), w_s), w_s.join(['1', '2', '3', '4']).split(w_s))


if __name__ == '__main__' :
    unittest.main()
