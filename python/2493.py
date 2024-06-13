import sys
from collections import deque
input = sys.stdin.readline

"""
6
6 9 5 7 4 8
ans = 0 0 2 2 4 2

10
6 1 8 5 9 2 4 3 7 10
ans = 0 1 0 3 0 5 5 7 5 0

30
1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 10 10 10
ans = 0 0 0 0 0 0 0 0 0 0 10 11 12 13 14 15 16 17 18 17 16 15 14 13 12 11 10 0 0 0

0 0 0 0 0 0 0 0 0 0 10 11 12 13 14 15 16 17 18 17 16 15 14 13 12 11 10 0 0 0
0 0 0 0 0 0 0 0 0 0 10 11 12 13 14 15 16 17 18 18 17 16 15 14 13 12 11 10 28 29
"""

T = int(input().rstrip())
towers = map(int, input().rstrip().split())

maxes = deque()
locs = [0] * T
answer = []
rotated = 0
maxes.append((100000001, 0))

for i, tower in enumerate(towers):
    while maxes and maxes[-1][0] <= tower:
        maxes.pop()

    if maxes:
        counter = len(maxes)
        while maxes[-1][0] < tower and counter > 0:
            maxes.rotate()
            rotated -= 1
            counter -= 1
        
        if locs[maxes[-1][1]] != 0:
            answer.append(locs[maxes[-1][1]])
            locs[i] = locs[maxes[-1][1]]
        else:
            answer.append(maxes[-1][1])
            locs[i] = maxes[-1][1]
        
        maxes.rotate(rotated)
        rotated = 0
    else:
        answer.append(0)
        locs[i] = 0

    maxes.append((tower, i+1))

print(*answer)