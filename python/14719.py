import sys
from collections import deque
input = sys.stdin.readline

"""
# 4
2 10
2 0 0 1 0 1 0 1 0 0

# 4
2 10
0 0 1 0 1 0 1 0 0 2

# 5
3 10
0 1 1 1 2 1 1 1 0 3
"""

H, W = map(int, input().split())
blocks = list(map(int, input().rstrip().split()))
res = 0

prevs = deque()
for i, b in enumerate(blocks):
    if prevs:
        if prevs[0] <= b:
            for i in range(len(prevs) - 1):
                popped = prevs.pop()
                res += min(prevs[0], b) - popped
            
            prevs = deque()

    prevs.append(b)

if prevs:
    while len(prevs) > 1 and prevs[-1] <= prevs[-2]:
        prevs.pop()

if len(prevs) > 1:
    prev = prevs.pop()
    wall = prev
    temp = 0
    hor = 0
    while prevs:
        if wall <= prevs[-1]:
            res += (hor * wall) - temp
            wall = prevs.pop()
            prev = wall
            temp = 0
            hor = 0
        else:
            temp += prevs[-1]
            hor += 1
            prev = prevs.pop()

print(res)