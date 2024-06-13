import sys
input = sys.stdin.readline

l, r = map(str, input().split())
res = 0

l = l[::-1]
r = r[::-1]

res = 0

for i in range(len(r)):
    if i >= len(l):
        res = 0
        break
    elif l[i] == r[i] == '8':
        res += 1
    elif l[i] != r[i]:
        res = 0

print(res)
# 818 888
# 1800 2899