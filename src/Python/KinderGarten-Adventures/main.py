#!/bin/python3

import os
import sys
import collections

def Sort(timesDict):
    od = collections.OrderedDict(sorted(timesDict.items()))
    return od

#
# Complete the solve function below.
#
def solve(t):
    kids = dict()
    for i in range(len(t)):
        kids[t[i]] = i
    sortedTimes = Sort(kids)
    finishers = 0
    for i in range(1,len(kids)):
        if i >= kids.keys()[i]:
            finishers += 1
        else:
            continue
            
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t_count = int(input())

    t = list(map(int, input().rstrip().split()))

    id = solve(t)

    fptr.write(str(id) + '\n')

    fptr.close()

