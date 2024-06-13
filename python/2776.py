import sys
#from collections import deque
#import heapq
input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    N = int(input().rstrip())
    nums = {}
    for i in map(int, input().rstrip().split()):
        nums[i] = 0
    
    M = int(input().rstrip())
    for i in map(int, input().rstrip().split()):
        if i in nums: print(1)
        else: print(0)