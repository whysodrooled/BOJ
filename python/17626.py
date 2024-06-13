import math
import sys

input = sys.stdin.readline

powers = [0] * 225
def getsum(n, start):
    global powers

    if start < 0: return 99

    if powers[start - 1] == 0:
        powers[start - 1] = start ** 2

    n -= powers[start - 1]

    if n == 0: return start
    elif n < 0: return 99
    return getsum(n, start - 1)

N = int(input().rstrip())

res = 4
for v in range(min(225, N), 0, -1):
    res = min(res, getsum(N, v))

print(res)