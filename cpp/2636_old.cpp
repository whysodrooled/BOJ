// https://www.acmicpc.net/board/view/51272

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M;
int cheese[101][101] = {{0}};
bool visited[101][101] = {{false}};
int mark[101][101] = {{0}};
queue<pair<int, int>> q;
int checc[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int checc2[][2] = {{1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
int totals = 0;

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
            if(cheese[i][j] == 1)
            {
                totals++;
            }
        }
    }

    int curtot = 0;
    int curlev = 1;
    while(totals > 0)
    {
        curtot = totals;

        q.push(make_pair(curlev-1, curlev-1));
        q.push(make_pair(curlev-1, M-curlev));
        q.push(make_pair(N-curlev, curlev-1));
        q.push(make_pair(N-curlev, M-curlev));
        visited[curlev-1][curlev-1] = true;
        visited[curlev-1][M-curlev] = true;
        visited[N-curlev][curlev-1] = true;
        visited[N-curlev][M-curlev] = true;

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (size_t l = 0; l < 4; l++)
            {
                int i = checc[l][0];
                int j = checc[l][1];

                if(x+i < 0 || x+i >= N
                || y+j < 0 || y+j >= M
                || (i == 0 && j == 0) || visited[x+i][y+j])
                    continue;
                
                if(cheese[x+i][y+j] == 1)
                {
                    if(mark[x + i][y + j] == 0)
                        mark[x + i][y + j] = curlev;
                }
                else
                {
                    q.push(make_pair(x + i, y + j));
                }

                visited[x + i][y + j] = true;
            }
            for (size_t l = 0; l < 4; l++)
            {
                int i = checc2[l][0];
                int j = checc2[l][1];

                if(x+i < 0 || x+i >= N
                || y+j < 0 || y+j >= M
                || (i == 0 && j == 0) || visited[x+i][y+j])
                    continue;
                
                int surround = 0;
                for (size_t l2 = 0; l2 < 4; l2++)
                {
                    int i2 = checc[l2][0];
                    int j2 = checc[l2][1];

                    if(i+i2 < -1 || i+i2 > 1
                    || j+j2 < -1 || j+j2 > 1)
                        continue;
                    
                    if(cheese[x+i+i2][y+j+j2] == 1)
                        surround++;
                }

                if(surround < 2)
                {
                    if(cheese[x+i][y+j] == 1)
                    {
                        if(mark[x + i][y + j] == 0)
                            mark[x + i][y + j] = curlev;
                    }
                }
                else
                {
                    visited[x + i][y + j] = true;
                }
            }
        }

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                if(mark[i][j] == curlev)
                {
                    q.push(make_pair(i, j));
                    totals--;
                    cheese[i][j] = 0;
                }
                visited[i][j] = false;
            }
        }

        curlev++;
    }

    cout << curlev-1 << '\n'
         << curtot;

    return 0;
}