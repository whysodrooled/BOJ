import sys
input = sys.stdin.readline

def bridge(bridges, dest):
    if bridges == 1:
        return dest
    else:
        ways = 0
        for i in range(dest - bridges + 1):
            ways += bridge(bridges - 1, dest - i - 1)
        
        return ways

T = int(input().rstrip())

for _ in range(T):
    start, dest = map(int, input().rstrip().split())
    print(bridge(start, dest))