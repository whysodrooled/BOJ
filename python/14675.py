import sys

input = sys.stdin.readline

visited = {}

T = int(input().rstrip()) - 1
for _ in range(T):
    a, b = map(int, input().split())
    visited[a] = visited.get(a, 0) + 1
    visited[b] = visited.get(b, 0) + 1

T = int(input().rstrip())
for _ in range(T):
    ques, ex = map(int, input().split())
    if ques == 2:
        print("yes")
    else:
        if visited[ex] > 1:
            print("yes")
        else:
            print("no")