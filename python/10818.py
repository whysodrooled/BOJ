import sys
input = sys.stdin.readline

N = int(input().rstrip())
res = list(map(int, input().split()))

print(min(res), max(res))