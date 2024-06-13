a, b = map(int, input().rstrip().split())

def gcd(i, j):
    if j > 0:
        return gcd(j, i % j)
    else:
        return i

big = gcd(max(a, b), min(a, b))
print(big)
print(a*b // big)