#!/usr/bin/env python

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        words = s.split()
        words.reverse()
        return ' '.join(words)
