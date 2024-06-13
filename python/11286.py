import sys
import heapq
input = sys.stdin.readline

T = int(input().rstrip())
hq = []

for _ in range(T):
    inp = int(input().rstrip())
    if inp == 0:
        if len(hq) > 0:
            print(heapq.heappop(hq)[1])
        else:
            print(0)
    else:
        heapq.heappush(hq, (abs(inp), inp))