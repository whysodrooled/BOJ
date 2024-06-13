import sys
from collections import deque
input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    n, m = input().rstrip().split(" ")
    n = int(n)
    m = int(m)
    que = deque([int(i), n] for n, i in enumerate(input().rstrip().split(" ")))
    tgtImp = que[m][0]

    res = 0
    curMax = max(que)[0]
    while curMax > tgtImp:
        if que[0][0] == curMax:
            que.popleft()
            curMax = max(que)[0]
            res += 1
        else:
            que.rotate(-1)
    
    while True:
        val = que.popleft()
        if val[0] == tgtImp: res += 1
        if val[1] == m: break
    
    print(res)