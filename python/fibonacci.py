import sys

input = sys.stdin.readline
from collections import deque

N = int(input().rstrip())

dq = deque([0, 1])
for _ in range(N):
    dq.append(dq.popleft() + dq[0])

print(dq.popleft())