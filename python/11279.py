import sys
import heapq
input = sys.stdin.readline

N = int(input().rstrip())
heap = []

for _ in range(N):
    inp = int(input().rstrip())

    if inp == 0:
        if len(heap) > 0:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (-inp, inp))