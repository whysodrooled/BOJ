import sys
input = sys.stdin.readline

T = int(input().rstrip())
nums = list(map(int, input().rstrip().split()))
ops = list(map(int, input().rstrip().split()))

def recur2(op, opz, sumz, add):
    temp = 0
    if op == 0:
        temp = sumz + add
    elif op == 1:
        temp = sumz - add
    elif op == 2:
        temp = sumz * add
    else:
        if sumz < 0:
            temp = -sumz // add
            temp *= -1
        else:
            temp = sumz // add

    opop = opz.copy()
    opop[op] -= 1

    return temp, opop

def recur(sumz, opz, idx, results):
    global nums

    if idx == len(nums)-1:
        results.append(sumz)
        return
    
    for i in range(4):
        if opz[i] <= 0: continue
        sumzz, opop = recur2(i, opz, sumz, nums[idx+1])
        recur(sumzz, opop, idx+1, results)
    
    return max(results), min(results)

print(*recur(nums[0], ops, 0, []), sep='\n')