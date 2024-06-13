import sys
input = sys.stdin.readline

lenn = int(input().rstrip())
nums = list(map(int, input().split()))
print(sum(nums) / lenn / max(nums) * 100)