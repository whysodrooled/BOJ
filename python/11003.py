# slow

import sys
import heapq
input = sys.stdin.readline

N, L = map(int, input().split())
result = [0] * N
heappy = []

for i, n in enumerate(map(int, input().split())):
    while heappy and (heappy[0][1] <= i):
        heapq.heappop(heappy)
    
    heapq.heappush(heappy, (n, i+L))
    result[i] = heappy[0][0]

print(*result)