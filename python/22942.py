import sys
from collections import deque

input = sys.stdin.readline

T = int(input().rstrip())
result = True
points = deque()

for tt in range(T):
    point, rad = map(int, input().rstrip().split())
    rot = 0

    for i in range(tt):
        if point - rad <= points[-1][0] and point + rad >= points[-1][1]:
            pass
        elif point - rad > points[-1][0] and point + rad < points[-1][1]:
            pass
        elif point + rad < points[-1][0] or point - rad > points[-1][1]:
            pass
        else:
            result = False
        
        points.rotate()

    if not result: break

    points.append((point - rad, point + rad))

print("YES" if result else "NO")