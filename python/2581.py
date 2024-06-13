M = int(input())
N = int(input())
primes = [True] * (N+1)
small = None
res = 0

for i in range(2, N+1):
    if not primes[i]: continue
    
    if i >= M:
        if not small: small = i
        res += i

    j = i
    while j < N+1:
        primes[j] = False
        j += i

if small:
    print(res)
    print(small)
else:
    print(-1)