import sys
input = sys.stdin.readline

N, M, T = map(int, input().split())
K, a, b = map(int, input().split())
grid = [[False for _ in range(M)] for _ in range(N)]
grid2 = [[False for _ in range(M)] for _ in range(N)]
flip = False

for _ in range(N):
    for i, c in enumerate(input().rstrip()):
        if c == '*':
            grid[_][i] = True
            grid2[_][i] = True

for _ in range(T):
    if flip:
        for i in range(N):
            for j in range(M):
                count = 0
                
                for i2 in range(i-K, i+K+1):
                    for j2 in range(j-K, j+K+1):
                        if i == i2 and j == j2: continue
                        if i2 < 0 or i2 >= N or j2 < 0 or j2 >= M: continue
                        if grid2[i2][j2]:
                            count += 1
                
                if count > a:
                    if count > b:
                        grid[i][j] = False
                    else:
                        grid[i][j] = True
                elif count != a:
                    grid[i][j] = False
                else:
                    grid[i][j] = grid2[i][j]
    else:
        for i in range(N):
            for j in range(M):
                count = 0
                
                for i2 in range(i-K, i+K+1):
                    for j2 in range(j-K, j+K+1):
                        if i == i2 and j == j2: continue
                        if i2 < 0 or i2 >= N or j2 < 0 or j2 >= M: continue
                        if grid[i2][j2]:
                            count += 1
                
                if count > a:
                    if count > b:
                        grid2[i][j] = False
                    else:
                        grid2[i][j] = True
                elif count != a:
                    grid2[i][j] = False
                else:
                    grid2[i][j] = grid[i][j]
    
    flip = not flip

if flip:
    for i in range(N):
        for j in range(M):
            if grid2[i][j]:
                print('*', end='')
            else:
                print('.', end='')
        print('\n', end='')
else:
    for i in range(N):
        for j in range(M):
            if grid[i][j]:
                print('*', end='')
            else:
                print('.', end='')
        print('\n', end='')