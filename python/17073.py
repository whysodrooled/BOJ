import sys
from collections import deque

input = sys.stdin.readline

N, W = map(int, input().split())
nodes = {}
visited = [False] * N

for _ in range(N - 1):
    a, b = map(int, input().split())
    
    if a in nodes:
        nodes[a].append(b)
    else:
        nodes[a] = [b]
    if b in nodes:
        nodes[b].append(a)
    else:
        nodes[b] = [a]

dq = deque([1])
res = 0

while dq:
    val = dq.popleft()
    visited[val - 1] = True
    if val not in nodes:
        continue

    isChild = True
    for v in nodes[val]:
        if visited[v-1]: continue
        dq.append(v)
        isChild = False
    
    if isChild: res += 1

print(W / res)