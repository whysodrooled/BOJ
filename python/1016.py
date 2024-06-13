import sys
#from collections import deque
#import heapq
input = sys.stdin.readline

minn, maxx = map(int, input().rstrip().split())

includd = [False] * (maxx-minn+1)
halve = round(maxx**0.5)

for i in range(2, halve+1):
    for j in range(i**2, maxx+1, i**2):
        target = j-1-minn
        if target >= 0:
            includd[target] = True

answer = len(includd)
for b in includd:
    if b: answer -= b

print(answer)