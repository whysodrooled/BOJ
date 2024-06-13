import sys
input = sys.stdin.readline
count = 0
maxx = 0

for _ in range(10):
    a, b = map(int, input().rstrip().split())
    count = count + b - a
    maxx = max(maxx, count)

print(maxx)