#!/usr/bin/env python

import sys

solution = __import__('reverse_words_in_a_string_' + sys.argv[1]).Solution()

def test():
    assert(solution.reverseWords('the sky is blue') == 'blue is sky the')
    assert(solution.reverseWords(' b  a  ') == 'a b')
    assert(solution.reverseWords('  ') == '')


def main():
    test()


if __name__ == '__main__':
    main();
