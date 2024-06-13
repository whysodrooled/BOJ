import sys
from collections import deque

sys.setrecursionlimit(10000000)

input = sys.stdin.readline

T = int(input().rstrip()) - 1

tree = {}
parents = [None] * (T)

for _ in range(T):
    a, b = map(int, list(input().rstrip().split()))
    if b == 1: a, b = b, a

    if a in tree:
        tree[a].append(b)
    else:
        tree[a] = [b]
    
    if b in tree:
        tree[b].append(a)
    else:
        tree[b] = [a]

dq = deque([1])

while dq:
    temp = dq.popleft()
    for v in tree[temp]:
        if v == 1 or parents[v-2]: continue

        parents[v-2] = temp
        dq.append(v)

print(*parents, sep='\n')