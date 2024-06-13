import sys
input = sys.stdin.readline

T = int(input().rstrip())

peoples = []
people_sum = 0

for _ in range(T):
    loc, people = map(int, list(input().rstrip().split()))
    people_sum += people
    peoples.append([loc, people])

p_sort = sorted(peoples)

people_sum /= 2
temp = 0

for p in p_sort:
    temp += p[1]
    if temp >= people_sum:
        print(p[0])
        break