inputt = int(input())
inputs = []
for z in range(inputt):
    a = list(map(int, input().split()))
    inputs.append(a)

ones = [[],
    [],
    [4,8,6],
    [9,7,1],
    [6],
    [],
    [],
    [9,3,1],
    [4,2,6],
    [1]]

for a in inputs:
    a[0] %= 10
    if a[0] == 0: print(10)
    else:
        idx = ((a[1]-1) % (len(ones[a[0]])+1))-1
        print(ones[a[0]][idx]
            if (idx > -1) else a[0])