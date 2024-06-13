import sys
input = sys.stdin.readline

N, K = map(int, input().split())

if K < 5:
    print(0)
    quit()

counts = {}

for _ in range(N):
    word = input().rstrip()[4:-4]
    temp = list(dict.fromkeys(list(word)))
    temp = sorted([c for c in temp if c not in ['a', 'c', 'i', 'n', 't']])

    counts[''.join(temp)] = counts.get(''.join(temp), 0) + 1

counts2 = list(counts.items())
counts2 = sorted(counts2, key=lambda x : -len(x[0]))
remain = K - 5
default = 0

for i in counts2:
    if len(i[0]) > remain: continue

    alpha = sorted([*i[0]])

default = counts.get('', 0)
condense = []
for k, v in counts.items():
    temp = v
    isSub = False

    for k2, v2 in counts.items():
        if len(k) < len(k2):
            going = True
            for c in k:
                if c not in k2:
                    going = False
            
            if going:
                isSub = True
                break

        if (k != k2):
            going = True
            for c in k2:
                if c not in k:
                    going = False

            if going:
                temp += v2

    condense.append([temp, len(k)])

condense.sort(reverse=True)
res = 0
limit = 0
for v in condense:
    limit += v[1]
    if limit > remain:
        limit -= v[1]
        continue

    res += v[0]

print(condense)
print(res + default)