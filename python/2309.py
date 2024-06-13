import sys
input = sys.stdin.readline

heights = []

for _ in range(9):
    heights.append(int(input().rstrip()))

heights = sorted(heights)
summ = sum(heights)
exclude = []

for i in range(9):
    temp = summ - 100 - heights[i]
    if temp in heights:
        exclude.append(temp)
        exclude.append(heights[i])
        break

for i in range(9):
    if heights[i] not in exclude:
        print(heights[i])