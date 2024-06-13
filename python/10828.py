import sys

T = int(sys.stdin.readline().rstrip())
stack = []
for _ in range(T):
    a = list(sys.stdin.readline().rstrip().split())

    if a[0] == 'push':
        stack.insert(0, int(a[1]))
    elif a[0] == 'pop':
        if len(stack) == 0: print(-1)
        else: print(stack.pop(0))
    elif a[0] == 'size':
        print(len(stack))
    elif a[0] == 'empty':
        if len(stack) > 0: print(0)
        else: print(1)
    elif a[0] == 'top':
        if len(stack) == 0: print(-1)
        else: print(stack[0])