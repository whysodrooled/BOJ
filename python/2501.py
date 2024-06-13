import sys
input = sys.stdin.readline

n, k = map(int, input().split())
things = [1, n]
for i in range(2, n):
    if n % i == 0:
        things.append(i)

if len(things) < k: print(0)
else: print(sorted(things)[k-1])