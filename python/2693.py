T = int(input())

for _ in range(T):
    nums = sorted(list(map(int, input().rstrip().split())), reverse=True)
    print(nums[2])