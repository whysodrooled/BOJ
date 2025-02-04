#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

char board[51][51];
int visited[51][51];
int N, M;

bool findCycle(int x, int y)
{
    visited[x][y] = board[x][y] - 'A';

    int same = 0;
    bool skip = false;
    for (int i = max(0, x-1); i < min(N, x+2); i++)
    {
        if(i == x)
            continue;
        
        if(same >= 2 || skip)
        {
            break;
        }
            
        if(visited[i][y] == -1 && (board[x][y] == board[i][y]))
        {
            skip = findCycle(i, y);
        }
        else if(visited[i][y] == visited[x][y])
        {
            same++;
        }
    }
    for (int j = max(0, y-1); j < min(M, y+2); j++)
    {
        if(j == y)
            continue;
        
        if(same >= 2 || skip)
        {
            break;
        }
            
        if(visited[x][j] == -1 && (board[x][y] == board[x][j]))
        {
            skip = findCycle(x, j);
        }
        else if(visited[x][j] == visited[x][y])
        {
            same++;
        }
    }
    
    return (same >= 2 || skip);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    string str;
    for (size_t i = 0; i < N; i++)
    {
        cin >> str;
        for (size_t j = 0; j < M; j++)
        {
            board[i][j] = str[j];
            visited[i][j] = -1;
        }
    }

    bool res = false;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if(visited[i][j] == -1)
            {
                if(findCycle(i, j))
                {
                    res = true;
                    break;
                }
            }
        }

        if(res)
        {
            break;
        }
    }

    cout << (res ? "Yes" : "No");

    return 0;
}