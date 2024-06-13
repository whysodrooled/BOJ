import sys
from collections import deque

input = sys.stdin.readline

T = int(input().rstrip())

for _ in range(T):
    cmds = input().rstrip()
    size = int(input().rstrip())
    nums_str = input().rstrip()[1:-1]

    nums = []
    if size > 0: nums = list(map(int, nums_str.split(',')))
    nums = deque(nums)

    flip = True
    for c in cmds:
        if c == 'R':
            flip = not flip
        else:
            if len(nums) == 0:
                nums = "error"
                break

            if flip:
                nums.popleft()
            else:
                nums.pop()

    if type(nums) == deque:
        if not flip: nums.reverse()
        print('[{}]'.format(''.join(str(v) + ',' for v in nums)[:-1]))
    else:
        print(nums)