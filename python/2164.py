import sys
from collections import deque
input = sys.stdin.readline

N = int(input().rstrip())
arr = deque(i for i in range(1, N+1))

while len(arr) > 1:
    arr.popleft()
    arr.rotate(-1)

print(arr[0])