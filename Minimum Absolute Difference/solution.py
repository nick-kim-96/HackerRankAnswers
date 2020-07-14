#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(arr):
    arr.sort()
    i = 0
    
    minAbs = abs(arr[0] - arr[1])
    while(i < len(arr) -1):
        if(abs(arr[i] - arr[i+1]) < minAbs):
            minAbs = abs(arr[i] - arr[i+1])
        i+=1
    return minAbs


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = minimumAbsoluteDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
