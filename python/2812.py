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

for c in input().rstrip():
    numbers.append(int(c))

found = False

for i in range(K):
    found = False
    count = 0
    for j in range(len(numbers) - 1):
        if numbers[0] < numbers[1]:
            numbers.popleft()
            found = True
            break

        count += 1
        numbers.rotate(-1)
    
    if not found:
        numbers.rotate(-1)
        break

    numbers.rotate(count)

for i in range(len(numbers) - (N - K)):
    numbers.popleft()

print(*list(numbers), sep='')