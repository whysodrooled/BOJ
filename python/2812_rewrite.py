import sys
from collections import deque
input = sys.stdin.readline

"""
5 2
99919
answer: 999

8 2
15446321
answer = 546321
"""

N, K = map(int, input().split())
numbers = deque()
index = []

for i, c in enumerate(input().rstrip()):
    num = int(c)
    numbers.append(num)

    index.append([num, i])

index.sort(key=lambda x : (x[0], -x[1]))
print(numbers)
print(index)