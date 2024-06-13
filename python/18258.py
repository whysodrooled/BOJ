import sys
from collections import deque
input = sys.stdin.readline

T = int(input().rstrip())

# 일반 리스트는 너무 느렸다
queue = deque()

for _ in range(T):
    cmd = list(input().rstrip().split())

    if cmd[0] == "push":
        queue.append(int(cmd[1]))
    elif cmd[0] == "pop":
        if queue: print(queue.popleft())
        else: print(-1)
    elif cmd[0] == "size":
        print(len(queue))
    elif cmd[0] == "empty":
        if queue: print(0)
        else: print(1)
    elif cmd[0] == "front":
        if queue:
            val = queue.popleft()
            print(val)
            queue.appendleft(val)
        else: print(-1)
    elif cmd[0] == "back":
        if queue:
            val = queue.pop()
            print(val)
            queue.append(val)
        else: print(-1)