import sys
from collections import deque
input = sys.stdin.readline

N = int(input().rstrip())

sim = deque()
res = deque()
curNum = 0
count = 0
endEarly = False

for i in range(N):
    top = int(input().rstrip())
    count += 1
    if curNum < top:
        while curNum != (top - 1):
            curNum += 1
            sim.appendleft(curNum)
            res.append('+')

        res.append('+')
        res.append('-')
        curNum += 1

    elif top == sim[0]:
        sim.popleft()
        res.append('-')

if sim: print("NO")
else:
    while res:
        print(res.popleft())