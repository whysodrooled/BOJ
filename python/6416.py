import sys

input = sys.stdin.readline

tree = {}
roots = []
loop = True
isTree = True
count = 1

while loop:
    inp = list(map(int, input().rstrip().split()))
    while inp:
        u = inp.pop(0)
        v = inp.pop(0)

        if u == v == 0:
            if len(roots) > 1 and tree: isTree = False
            print("Case {} is {}a tree.".format(count, ('' if isTree else 'not ')))
            count += 1
            tree = {}
            roots = []
            isTree = True
            break
        elif u == v and v < 0:
            loop = False
            break

        if v in tree:
            isTree = False
        else:
            tree[v] = u

            if u not in roots:
                roots.append(u)

            if v in roots:
                root = roots.index(v)
                roots.pop(root)
            elif u in tree:
                root = roots.index(u)
                roots.pop(root)