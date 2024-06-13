import sys
import heapq
input = sys.stdin.readline

N = int(input().rstrip())
hq = []

for _ in range(N):
    for i in map(int, input().rstrip().split()):
        heapq.heappush(hq, i)
    
    while len(hq) > N: heapq.heappop(hq)

print(hq[0])