import sys
input = sys.stdin.readline

T = int(input())

total_x = []
total_y = []

for _ in range(T):
    x, y = map(int, input().split())
    total_x.append(x)
    total_y.append(y)

total_x.sort()
total_y.sort()

loc = [total_x[T // 2], total_y[T // 2]]

result = 0
for i in range(len(total_x)):
    result += abs(loc[0] - total_x[i]) + abs(loc[1] - total_y[i])

print(result)