#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M, K;
bool blocks[101][101] = {{false}};
bool visited[101][101] = {{false}};
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> pq;
int lol[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int lol2[][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int bfs(int xx, int yy)
{
    q.push(make_pair(xx, yy));
    visited[xx][yy] = true;
    int zonez = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        zonez++;
        
        for (size_t a = 0; a < 4; a++)
        {
            int i = lol[a][0];
            int j = lol[a][1];

            if(x+i < 0 || x+i >= N
            || y+j < 0 || y+j >= M)
                continue;
            
            if(!visited[x+i][y+j] && !blocks[x+i][y+j])
            {
                q.push(make_pair(x+i, y+j));
                visited[x + i][y + j] = true;
            }
        }
        for (size_t a = 0; a < 4; a++)
        {
            int i = lol2[a][0];
            int j = lol2[a][1];

            if(x+i < 0 || x+i >= N
            || y+j < 0 || y+j >= M)
                continue;
            
            if(!visited[x+i][y+j] && !blocks[x+i][y+j])
            {
                int wallz = 0;

                for (size_t b = 0; b < 4; b++)
                {
                    int i2 = lol[b][0];
                    int j2 = lol[b][1];

                    if(i+i2 < -1 || i+i2 > 1
                    || j+j2 < -1 || j+j2 > 1)
                        continue;
                    
                    if(blocks[x+i+i2][y+j+j2])
                    {
                        wallz++;
                    }
                }

                if(wallz < 2)
                {
                    q.push(make_pair(x+i, y+j));
                    visited[x + i][y + j] = true;
                }
            }
        }
    }

    return zonez;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N >> K;
    for (; K > 0; K--)
    {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;

        for (int a = x; a < x2; a++)
        {
            for (int b = y; b < y2; b++)
            {
                blocks[a][b] = true;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(!visited[i][j] && !blocks[i][j])
            {
                pq.push(bfs(i, j));
            }
        }
    }
    
    cout << pq.size() << '\n';
    while(!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}