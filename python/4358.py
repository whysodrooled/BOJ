import sys
input = sys.stdin.readline

trees = []
dic = {}
count = 0

while True:
    inp = input().rstrip()
    if inp == '': break
    dic[inp] = dic.get(inp, 0) + 100
    count += 1.0

for k, v in sorted(dic.items()):
    print('{0} {1:.4f}'.format(k, v / count))