import sys
from collections import deque
input = sys.stdin.readline

strn = input()
while strn != ".":
    small = deque()
    big = deque()
    res = True

    for c in strn:
        if c == '(':
            small.append(1)
        elif c == '[':
            big.append(1)
        elif c == ')':
            if small:
                if big:
                    res = False
                    break
                small.pop()
            else:
                res = False
                break
        elif c == ']':
            if big:
                if small:
                    res = False
                    break
                big.pop()
            else:
                res = False
                break
    
    res = res and not (small or big)
    print("yes" if res else "no")
    strn = input().rstrip()