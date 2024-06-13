import sys
input = sys.stdin.readline
from collections import deque

items = deque()
temp = deque()

T = int(input())
for i in range(T):
    items.append(float(input()))

res = max(items)
first = True

while first or len(temp) > 1:
    if first:
        lol = len(items) - 1
        for i in range(lol):
            popped = items.popleft()
            temp.append(popped * items[0])
            items.append(popped)
    else:
        for i in range(len(temp)):
            temp[i] *= items[i]
    
    res = max(res, max(temp))
    temp.pop()

    if first:
        items.append(items.popleft())
        items.popleft()
    items.popleft()

    first = False

print("%.3f" % res)