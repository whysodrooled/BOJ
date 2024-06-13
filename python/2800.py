import sys
from collections import deque
from itertools import chain, combinations

input = sys.stdin.readline

#(1+(2*(3+4)))
#(1+(2*2)-(2*(3-3))+1)
#1+(2*2)-(2*(3-3))+1
#(((3)))(2)

def powerset(s):
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

inp = input().rstrip()
paren = deque()
locs = []

for i, c in enumerate(inp):
    if c == '(':
        paren.append(i)
    elif c == ')':
        locs.append((paren.pop(), i))

locs = list(powerset(locs))[1:]

answer = set()
for loc in locs:
    temp = list(inp)
    for l in loc:
        temp[l[0]] = ' '
        temp[l[1]] = ' '
    answer.add(''.join(temp).strip().replace(" ", ""))

answer = sorted(list(answer))
print(*answer, sep='\n')