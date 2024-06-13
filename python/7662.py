import sys
import heapq
input = sys.stdin.readline

hq_low = []
hq_high = []

T = int(input().rstrip())

for _ in range(T):
    count = int(input().rstrip())
    stats = [False] * count
    hash = 0

    for __ in range(count):
        cmd, cmdNum = input().rstrip().split()
        cmdNum = int(cmdNum)

        if cmd == 'I':
            heapq.heappush(hq_low, [cmdNum, hash])
            heapq.heappush(hq_high, [-cmdNum, hash])
        elif cmd == 'D':
            if cmdNum == -1:
                while hq_low and stats[hq_low[0][1]]:
                    heapq.heappop(hq_low)

                if hq_low:
                    stats[heapq.heappop(hq_low)[1]] = True
            else:
                while hq_high and stats[hq_high[0][1]]:
                    heapq.heappop(hq_high)
                
                if hq_high:
                    stats[heapq.heappop(hq_high)[1]] = True
        
        hash += 1
    
    while hq_low and stats[hq_low[0][1]]:
        heapq.heappop(hq_low)
    while hq_high and stats[hq_high[0][1]]:
        heapq.heappop(hq_high)

    if hq_low:
        print(-hq_high[0][0], hq_low[0][0])
    else:
        print("EMPTY")
    
    hq_low = []
    hq_high = []
    hash = 0