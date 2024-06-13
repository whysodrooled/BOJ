import sys
input = sys.stdin.readline

n, k = input().rstrip().split()
n = int(n)
k = int(k) - 1

arr = [i for i in range(1, n+1)]
idx = 0

print("<", end="")
while len(arr) > 1:
    idx += k
    idx %= len(arr)
    print(arr.pop(idx), end=", ")

print(arr[0], end=">")