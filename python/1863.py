import sys
from collections import deque

input = sys.stdin.readline

T = int(input().rstrip())
stack = deque([0])
builds = 0

"""
13
1 1
2 2
3 3
4 4
5 5
6 6
7 0
8 6
9 5
10 4
11 3
12 2
13 1
"""

for _ in range(T):
    x, y = list(map(int, input().rstrip().split()))

    if len(stack) > 0:
        if stack[-1] != y:
            while stack[-1] > y:
                stack.pop()
                builds += 1

            if stack[-1] != y:
                stack.append(y)

print(builds + (len(stack) - 1))