import math
import os
import random
import re
import sys

# Complete the matrixRotation function below.
def matrixRotation(matrix, r):
    m, n = len(matrix), len(matrix[0])
    b = [[None]*n for _ in range(m)]
    indices = []

    for c in range(min(m,n)//2):
        index = []
        for i in range(c,n-c): index.append((c,i))
        for i in range(c+1,m-1-c): index.append((i,n-1-c))
        for i in range(c,n-c)[::-1]: index.append((m-1-c,i))
        for i in range(1+c,m-1-c)[::-1]: index.append((i,c))
        if not index:
            break
        indices.append(index)

    rotated = []
    for index in indices:
        k = r%len(index)
        rotated.append(index[k:]+index[:k])

    for (x,y) in zip(indices,rotated):
        for ((c,d),(e,f)) in zip(x,y):
            b[c][d] = matrix[e][f]

    return b
    m, n = len(matrix), len(matrix[0])
    b = [[None]*n for _ in range(m)]
    indices = []

    for c in range(min(m,n)//2):
        index = []
        for i in range(c,n-c): index.append((c,i))
        for i in range(c+1,m-1-c): index.append((i,n-1-c))
        for i in range(c,n-c)[::-1]: index.append((m-1-c,i))
        for i in range(1+c,m-1-c)[::-1]: index.append((i,c))
        if not index:
            break
        indices.append(index)

    rotated = []
    for index in indices:
        k = r%len(index)
        rotated.append(index[k:]+index[:k])

    for (x,y) in zip(indices,rotated):
        for ((c,d),(e,f)) in zip(x,y):
            b[c][d] = matrix[e][f]

    return b
m,n,r = map(int,input().split())
matrix = [input().split() for i in range(m)]
for i in matrixRotation(matrix,r):
    print(*i)
