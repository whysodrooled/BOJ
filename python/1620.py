import sys
input = sys.stdin.readline
print = sys.stdout.write

N, M = map(int, input().rstrip().split())
poke = {}

for i in range(N):
    inp = input().rstrip()
    poke[i+1] = inp
    poke[inp] = i+1

item = poke.items()
for _ in range(M):
    ques = input().rstrip()
    if ques.isdigit():
        print(poke[int(ques)] + '\n')
    else:
        print('{0}{1}'.format(poke[ques], '\n'))