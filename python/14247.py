import sys
input = sys.stdin.readline

T = int(input().rstrip())
trees = list(map(int, input().split()))
increments = list(map(int, input().split()))

for i in range(len(trees)):
    trees[i] = [increments[i], trees[i]]

trees.sort()
total = 0

for i, t in enumerate(trees):
    total += t[1] + (t[0] * i)

print(total)