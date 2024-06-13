import sys
input = sys.stdin.readline

def rock(n, flip):
    if n > 3:
        return rock(n - 3, not flip)
    elif n == 3:
        return flip
    elif n > 0:
        return rock(n - 1, not flip)
    else:
        return not flip

N = int(input().rstrip())
print("SK" if rock(N, True) else "CY")