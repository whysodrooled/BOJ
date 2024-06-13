import sys
import heapq
input = sys.stdin.readline

T = int(input().rstrip())
probBig = []
probSmall = []
status = [False] * 100001

for _ in range(T):
    num, diff = map(int, input().split())
    heapq.heappush(probSmall, (diff, num))
    heapq.heappush(probBig, (-diff, -num))

T = int(input().rstrip())
for _ in range(T):
    inp = input().split()

    if inp[0] == "add":
        status[int(inp[1])] = False
        heapq.heappush(probSmall, (int(inp[2]), int(inp[1])))
        heapq.heappush(probBig, (-int(inp[2]), -int(inp[1])))
    elif inp[0] == "recommend":
        target = 0
        if int(inp[1]) == 1:
            target = -probBig[0][1]
        else:
            target = probSmall[0][1]
        
        print(target)
    elif inp[0] == "solved":
        status[int(inp[1])] = True
    
    while probBig and status[-probBig[0][1]]:
        heapq.heappop(probBig)
    while probSmall and status[probSmall[0][1]]:
        heapq.heappop(probSmall)