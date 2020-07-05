#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the luckBalance function below.
def luckBalance(k, contests):
    contests.sort(reverse = True)
    answer = 0
    lossCount = 0

    for i in contests:
        if(i[1] == 0):
            answer += i[0]
        else:
            if(lossCount < k):
                answer += i[0]
                lossCount += 1
            else:
                answer -= i[0]
    return answer
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
