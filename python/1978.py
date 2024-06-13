T = int(input())
nums = list(map(int, input().rstrip().split()))
primes = [True] * (max(nums) + 1)
count = 0

for i in range(2, max(nums) + 1):
    if not primes[i]: continue

    if i in nums: count += 1

    j = i
    while j < max(nums) + 1:
        primes[j] = False
        j += i

print(count)