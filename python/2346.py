import sys
from collections import deque
input = sys.stdin.readline

T = int(input().rstrip())
nums = deque([int(n), i+1] for i, n in enumerate(input().rstrip().split(" ")))

while T > 0:
    val = nums.popleft()
    top = val[0]
    print(val[1], end=" ")
    if(top > 0):
        top -= 1

    nums.rotate(top * -1)

    T -= 1