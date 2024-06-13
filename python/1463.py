import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(input().rstrip())
counts = [None] * (10**6 + 1)
counts[1] = 0

for i in range(2, N+1):
    counts[i] = i - 1

    if i >= 3:
        counts[i] = min(counts[i], counts[i // 3] + i % 3 + 1)

    if i >= 2:
        counts[i] = min(counts[i], counts[i // 2] + i % 2 + 1)

print(counts[N])