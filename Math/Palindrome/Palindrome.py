#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Palindrome():
    input_string = ''
    def __init__(self, input_string: str):
        self.input_string = input_string

    def Check(self):
        """
        Check if the given string is a palindrome.
        """
        return self.input_string == self.input_string[::-1]

if __name__ == '__main__':
    print( Palindrome('robinhood').Check() );
    print( Palindrome('malayalam').Check() );
