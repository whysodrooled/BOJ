import sys
from collections import deque

input = sys.stdin.readline
        
T = int(input().rstrip())
parents = list(map(int, input().split()))
delete = int(input().rstrip())
connection = {}

for i, v in enumerate(parents):
    if i == delete: continue
    if v in connection:
        connection[v].append(i)
    else:
        connection[v] = [i]

res = 0
dq = deque([-1])

while dq:
    temp = dq.popleft()
    if temp in connection:
        for v in connection[temp]:
            dq.append(v)
    else:
        if temp != -1:
            res += 1

print(res)