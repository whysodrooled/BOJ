import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    b = 0
    i = int(input())
    res = []
    while (1 << b) <= i:
        if i & (1 << b):
            res.append(b)
        
        b += 1
    
    print(*res)