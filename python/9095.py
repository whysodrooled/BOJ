import sys

input = sys.stdin.readline

sums = [None] * 11
sums[1] = set([(1, 0, 0)])
sums[2] = set([(0, 1, 0), (2, 0, 0)])
sums[3] = set([(0, 0, 1), (2, 1, 0), (3, 0, 0)])

for i in range(4, 11):
    if sums[i]: continue
    sums[i] = set()
    for arr in sums[i - 1]:
        sums[i].add((arr[0]+1, arr[1], arr[2]))
    for arr in sums[i - 2]:
        sums[i].add((arr[0], arr[1]+1, arr[2]))
    for arr in sums[i - 3]:
        sums[i].add((arr[0], arr[1], arr[2]+1))

T = int(input().rstrip())

for _ in range(T):
    num = int(input().rstrip())

    print(sums[num])