import sys
input = sys.stdin.readline

for i in range(int(input())):
    name = input().rstrip()

    answer = 0

    for c in name:
        sum = (ord(c) - ord('A'))
        if sum > 13:
            sum = 26 - sum
        
        answer += sum

    move = len(name) - 1
    for i in range(len(name)):
        a = i + 1
        if (a + 1) < len(name) and name[a] == 'A':
            while (a + 1) < len(name) and name[a + 1] == 'A':
                a += 1
            
            #print("lol", (i) * 2 + len(name) - a - 1, (len(name) - a - 1) * 2 + i)
            move = min(move,
                    (i) * 2 + len(name) - a - 1,
                    (len(name) - a - 1) * 2 + i)

    print(answer + move)