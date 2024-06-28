// recoded based on google observation

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M;
bool cheese[101][101] = {{false}};
bool visited[101][101] = {{false}};
bool mark[101][101] = {{false}};
int res = 0;
int total = 0;
int lol[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int lol2[][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
queue<pair<int, int>> q;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> cheese[i][j];
            if(cheese[i][j])
            {
                total++;
            }
            visited[i][j] = false;
        }
    }

    q.push(make_pair(0, 0));
    q.push(make_pair(0, M-1));
    q.push(make_pair(N-1, 0));
    q.push(make_pair(N-1, M-1));
    visited[0][0] = true;
    visited[0][M-1] = true;
    visited[N-1][0] = true;
    visited[N-1][M-1] = true;
    int time = 0;
    int curTotal;
    while(total > 0)
    {
        curTotal = total;

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (size_t a = 0; a < 4; a++)
            {
                int i = lol[a][0];
                int j = lol[a][1];

                if(x+i < 0 || x+i >= N
                || y+j < 0 || y+j >= M)
                    continue;

                if(!visited[x+i][y+j])
                {
                    if((i == 0 || j == 0))
                    {
                        if(cheese[x + i][y + j])
                        {
                            mark[x + i][y + j] = true;
                            visited[x + i][y + j] = true;
                        }
                        else
                        {
                            visited[x + i][y + j] = true;
                            q.push(make_pair(x + i, y + j));
                        }
                    }
                    else if(!cheese[x + i][y + j] && !visited[x + i][y + j])
                    {
                        int walls = 0;
                        for (size_t b = 0; b < 4; b++)
                        {
                            int i2 = lol2[b][0];
                            int j2 = lol2[b][1];

                            if(i+i2 < -1 || i+i2 > 1
                            || j+j2 < -1 || j+j2 > 1)
                                continue;

                            if(cheese[x + i + i2][y + j + j2])
                            {
                                walls++;
                            }
                        }
                        
                        if(walls < 2)
                            q.push(make_pair(x + i, y + j));
                    }
                }
            }
        }

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                visited[i][j] = false;
                
                if(mark[i][j])
                {
                    total--;
                    cheese[i][j] = false;
                    mark[i][j] = false;
                    q.push(make_pair(i, j));
                }
            }
        }

        time++;
    }

    cout << time << '\n'
         << curTotal;

    return 0;
}