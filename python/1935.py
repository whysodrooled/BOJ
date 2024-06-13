import sys
from collections import deque
input = sys.stdin.readline

T = int(input().rstrip())
formula = input().rstrip()
nums = [int(input().rstrip()) for _ in range(T)]
arr = deque()
res = 0
#ord('A') = 65

for c in formula:
    if c == '+':
        arr.append(arr.pop() + arr.pop())
    elif c == '-':
        val1 = arr.pop()
        val2 = arr.pop()
        arr.append(val2 - val1)
    elif c == '*':
        arr.append(arr.pop() * arr.pop())
    elif c == '/':
        val1 = arr.pop()
        val2 = arr.pop()
        arr.append(val2 / val1)
    else:
        arr.append(nums[ord(c) - 65])

print('{:.2f}'.format(arr[0]))