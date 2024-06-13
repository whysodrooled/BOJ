import sys
input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    a = list(map(int, input().rstrip().split()))
    print(a[0]+a[1])