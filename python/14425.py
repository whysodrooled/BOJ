import sys
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
words = set()

for _ in range(N):
    words.add(input().rstrip())

res = 0
for _ in range(M):
    if input().rstrip() in words:
        res += 1

print(res)