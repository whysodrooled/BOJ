"""
5 5
10101
01010
10101
01010
10101

5 5
01100
10111
11100
00001
10010

5 6
101010
010101
101010
010101
101010
"""

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [None] * N

for i in range(N):
    arr[i] = []
    for c in input().rstrip():
        if c == '1': arr[i].append(True)
        else: arr[i].append(False)

result = 0
for i in range(M):
    for j in range(i+1):
        y = N-j-1
        x = M-i+j-1

        if y < 0 or x < 0 or x >= M: continue

        if arr[y][x]:
            result += 1
            
            for i2 in range(y+1):
                for j2 in range(x+1):
                    arr[i2][j2] = not arr[i2][j2]

for i in range(N-2, -1, -1):
    for j in range(i+1):
        y = i-j
        x = j

        if y < 0 or x < 0 or x >= M: continue

        if arr[y][x]:
            result += 1
            
            for i2 in range(y+1):
                for j2 in range(x+1):
                    arr[i2][j2] = not arr[i2][j2]

print(result)