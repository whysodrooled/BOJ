import sys
input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    vps = input().rstrip()
    stack = []
    stop = False
    for c in vps:
        if c == '(':
            stack.append(c)
        elif c == ')':
            if len(stack) > 0: stack.pop()
            else:
                stop = True
                break
    
    if len(stack) == 0 and stop == False: print("YES")
    else: print("NO")