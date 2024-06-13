import sys
input = sys.stdin.readline

r, c, w = map(int, input().split())

result = 0
size = 1
temp = [1]

for i in range(1, r+w):
    newtemp = [1]
    for j in range(len(temp)-1):
        newtemp.append(temp[j] + temp[j+1])
    newtemp.append(1)

    if i >= r and size <= w:
        result += sum(temp[c-1:c+size-1])
        size += 1
    
    temp = newtemp

print(result)