import sys
input = sys.stdin.readline

N, A, D = map(int, input().rstrip().split())
notes = map(int, input().rstrip().split())

temp = A
res = 0
for n in notes:
    if n == temp:
        temp += D
        res += 1

print(res)