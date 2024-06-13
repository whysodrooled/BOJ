import sys
input = sys.stdin.readline

int(input().rstrip())
sets = {}

for i in list(map(int, input().split())):
    sets[i] = True

int(input().rstrip())
for i in list(map(int, input().split())):
    if i in sets: print(1)
    else: print(0)