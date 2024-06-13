import sys
from collections import deque
input = sys.stdin.readline

inp = input().rstrip()
save = deque()
brackets = deque()
prevC = None
count = 0
counts = deque()
res = 0
zero = False

for c in inp:
    if c == '(' or c == '[':
        brackets.append(c)
        counts.append(count)
        count = 0
    elif c == ')':
        if prevC == '(':
            save.append(2)
            count = counts.pop() + 1
            brackets.pop()
        elif len(brackets) == 0:
            zero = True
            break
        elif brackets[-1] == '(':
            items = 0
            while count > 0:
                items += save.pop()
                count -= 1
            save.append(items * 2)
            brackets.pop()
            count = counts.pop() + 1
        else:
            zero = True
            break
    elif c == ']':
        if prevC == '[':
            save.append(3)
            count = counts.pop() + 1
            brackets.pop()
        elif len(brackets) == 0:
            zero = True
            break
        elif brackets[-1] == '[':
            items = 0
            while count > 0:
                items += save.pop()
                count -= 1
            save.append(items * 3)
            brackets.pop()
            count = counts.pop() + 1
        else:
            zero = True
            break

    prevC = c

if zero or len(brackets) > 0:
    print(0)
else:
    while save:
        res += save.pop()

    print(res)