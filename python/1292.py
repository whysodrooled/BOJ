a, b = map(int, input().split())

res = 0
num = 0
num_ceil = 1
count = 0
for i in range(b):
    if num >= num_ceil:
        num_ceil += 1
        num = 0

    if i+1 >= a:
        count += num_ceil
    
    num += 1

print(count)