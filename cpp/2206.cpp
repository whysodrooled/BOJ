// https://kscodebase.tistory.com/66
// why take too long why!!!!!!!!

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M;
int visited[1001][1001][2];
bool walls[1001][1001] = {{false}};
int maxx;
int lol[] = {0, 0, 1, -1};
int lol2[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (size_t j = 0; j < M; j++)
        {
            if(str[j] == '1')
            {
                walls[i][j] = true;
            }
            visited[i][j][0] = 10000001;
            visited[i][j][1] = 10000001;
        }
    }

    q.push(make_pair(0, 0));
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int offs = 0; offs < 4; offs++)
        {
            int x2 = x + lol[offs];
            int y2 = y + lol2[offs];
            if(x2 < 0 || x2 >= N
            || y2 < 0 || y2 >= M)
                continue;

            if(walls[x2][y2])
            {
                if(visited[x2][y2][1] > visited[x][y][0]+1)
                {
                    visited[x2][y2][1] = visited[x][y][0] + 1;
                    q.push(make_pair(x2, y2));
                }
            }
            else
            {
                bool proceed = false;

                if(visited[x2][y2][0] > visited[x][y][0]+1)
                {
                    visited[x2][y2][0] = visited[x][y][0] + 1;
                    proceed = true;
                }
                if(visited[x2][y2][1] > visited[x][y][1]+1)
                {
                    visited[x2][y2][1] = visited[x][y][1] + 1;
                    proceed = true;
                }

                if(proceed)
                {
                    q.push(make_pair(x2, y2));
                }
            }
        }
        
    }

    maxx = min(visited[N-1][M-1][0], visited[N-1][M-1][1]);
    if(maxx == 10000001)
        cout << -1;
    else
        cout << maxx;

    return 0;
}