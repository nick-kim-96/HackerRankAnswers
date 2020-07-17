#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
    stack = []
    answer = ""
    for char in s:
        print(stack)
        if(char == '{'):
            stack.append('}')
        elif(char == '('):
            stack.append(')')
        elif(char == '['):
            stack.append(']')
        elif(len(stack) == 0 or stack.pop() != char):
            return "NO"
        
    return "YES"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
