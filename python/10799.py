import sys
#from collections import deque
input = sys.stdin.readline

inp = input().rstrip()

curPiece = 0
res = 0
prevC = ''
for c in inp:
    if c == '(':
        curPiece += 1
    else:
        curPiece -= 1
        if prevC == '(':
            res += curPiece
        else:
            res += 1

    prevC = c

print(res)