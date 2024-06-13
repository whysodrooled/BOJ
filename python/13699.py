import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**8)

T = int(input().rstrip())
indexes = [None] * 36
indexes[0] = 1

def loop(t):
    if indexes[t]: return indexes[t]

    ret = 0
    for i in range(t):
        ret += loop(i) * loop(t-i-1)

    indexes[t] = ret
    return ret

print(loop(T))