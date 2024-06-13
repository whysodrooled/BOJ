import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(10**6)
        
T, root = map(int, input().split())
visited = [False] * T
connection = {}

for v in range(T - 1):
    u, v, length = map(int, input().split())

    if u in connection:
        connection[u].append([v, length])
    else:
        connection[u] = [[v, length]]
    
    if v in connection:
        connection[v].append([u, length])
    else:
        connection[v] = [[u, length]]

dq = deque([[root, 0]])
body = 0
branch = 0

def calcBranch(node, length):
    if visited[node - 1]: return length
    visited[node - 1] = True

    if node in connection:
        validLen = 0
        for v in connection[node]:
            if not visited[v[0] - 1]:
                validLen += 1
        
        if validLen > 1:
            nums = []
            for v in connection[node]:
                nums.append(calcBranch(v[0], length + v[1]))
        
            return max(nums)
    
    return length

while dq:
    num = dq.popleft()
    visited[num[0] - 1] = True

    if num[0] in connection:
        body += num[1]

        validLen = 0
        for v in connection[num[0]]:
            if not visited[v[0] - 1]:
                validLen += 1
        
        if validLen > 1:
            for v in connection[num[0]]:
                branch = max(branch, calcBranch(v[0], v[1]))

            break
        
        for v in connection[num[0]]:
            if not visited[v[0] - 1]:
                dq.append(v)

print(body, branch)