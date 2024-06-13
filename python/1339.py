import sys
#from collections import deque
#import heapq
input = sys.stdin.readline

N = int(input().rstrip())
words = []
alphas = [0] * 10

for i in range(N):
    word = input().rstrip()
    for i, c in enumerate(reversed(word)):
        alphas[ord(c) - ord('A')] = max(i+1, alphas[ord(c) - ord('A')])

print(alphas)