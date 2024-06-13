import sys
input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    length = int(input().rstrip())
    in1 = input().rstrip()
    in2 = input().rstrip()

    diff = []
    for i in range(length):
        if in1[i] != in2[i]:
            diff.append(in1[i])
    
    print(max(diff.count('B'), diff.count('W')))