import sys
from collections import deque
input = sys.stdin.readline

T = int(input().rstrip())

arr = deque()

for _ in range(T):
    cmd = list(input().rstrip().split())

    if cmd[0] == "push_front":
        arr.appendleft(int(cmd[1]))
    elif cmd[0] == "push_back":
        arr.append(int(cmd[1]))
    elif cmd[0] == "pop_front":
        if arr: print(arr.popleft())
        else: print(-1)
    elif cmd[0] == "pop_back":
        if arr: print(arr.pop())
        else: print(-1)
    elif cmd[0] == "size":
        print(len(arr))
    elif cmd[0] == "empty":
        if arr: print(0)
        else: print(1)
    elif cmd[0] == "front":
        if arr:
            val = arr.popleft()
            print(val)
            arr.appendleft(val)
        else: print(-1)
    elif cmd[0] == "back":
        if arr:
            val = arr.pop()
            print(val)
            arr.append(val)
        else: print(-1)