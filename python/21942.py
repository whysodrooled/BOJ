import sys
input = sys.stdin.readline

borrowed = {}
fees = {}

inputs = input().rstrip().split()
T = int(inputs[0])
fee = int(inputs[2])

timestr = inputs[1].split("/")
maxtime = int(timestr[0]) * 1440
timestr = timestr[1].split(":")
maxtime += int(timestr[0]) * 60 + int(timestr[1])

for _ in range(T):
    date, clock, thing, name = input().rstrip().split()
    curtime = date.split()
    if name in borrowed:
        pass
    else:
        borrowed[name] = [[thing, curtime]]

print(fees)