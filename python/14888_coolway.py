import sys
input = sys.stdin.readline

T = int(input().rstrip())
nums = list(map(int, input().rstrip().split()))
ops = list(map(int, input().rstrip().split()))

maxx = -1000000000
minn = 1000000000

def coolway(i, summ):
    global nums, ops, maxx, minn

    if i >= len(nums):
        maxx = max(maxx, summ)
        minn = min(minn, summ)
        return

    if ops[0] > 0:
        ops[0] -= 1
        coolway(i+1, summ + nums[i])
        ops[0] += 1
    if ops[1] > 0:
        ops[1] -= 1
        coolway(i+1, summ - nums[i])
        ops[1] += 1
    if ops[2] > 0:
        ops[2] -= 1
        coolway(i+1, summ * nums[i])
        ops[2] += 1
    if ops[3] > 0:
        ops[3] -= 1
        temp = 0
        if summ < 0:
            temp = -summ // nums[i]
            temp *= -1
        else:
            temp = summ // nums[i]
    
        coolway(i+1, temp)
        ops[3] += 1

coolway(1, nums[0])

print(maxx)
print(minn)