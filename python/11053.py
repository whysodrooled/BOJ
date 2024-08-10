import sys
#from collections import deque
#import heapq
input = sys.stdin.readline

N = int(input().rstrip())
nums = list(map(int, input().rstrip().split()))
result = 1

def loopp(pos):
    cnt = 1
    cur = nums[pos]
    global result

    for i in range(pos+1, N):
        if cur < nums[i]:
            cnt += 1
            cur = nums[i]
        else:
            cnt = 1
            cur = nums[pos]

            if cur < nums[i]:
                cnt += 1
                cur = nums[i]
            
            loopp(i)
    
    result = max(result, cnt)

loopp(0)
print(result)