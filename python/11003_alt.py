import sys
from collections import deque
input = sys.stdin.readline

N, L = map(int, input().split())
result = [0] * N
heappy = deque()

for i, n in enumerate(map(int, input().split())):
    while heappy and (heappy[0][1] <= i):
        heappy.popleft()
    while heappy and (heappy[-1][0] >= n):
        heappy.pop()
    
    heappy.append((n, i+L))
    result[i] = heappy[0][0]

print(*result)