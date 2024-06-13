#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool visited[100][100] = {{false}};
bool mapz[100][100] = {{false}};
int N, M;
int res = 10001;

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
                mapz[i][j] = true;
            }
        }
    }

    queue<pair<pair<int,int>, int>> q;
    q.push(make_pair(make_pair(0, 0), 0));
    while (!q.empty())
    {
        pair<pair<int,int>, int> info = q.front();
        q.pop();

        int x = info.first.first;
        int y = info.first.second;
        int count = info.second;

        if(visited[x][y])
            continue;

        if(x == N-1 && y == M-1)
        {
            res = min(count, res);
            continue;
        }

        visited[x][y] = true;

        if(x > 0 && mapz[x-1][y] && !visited[x-1][y])
            q.push(make_pair(make_pair(x-1, y), count+1));
        if(x < N-1 && mapz[x+1][y] && !visited[x+1][y])
            q.push(make_pair(make_pair(x+1, y), count+1));
        if(y > 0 && mapz[x][y-1] && !visited[x][y-1])
            q.push(make_pair(make_pair(x, y-1), count+1));
        if(y < M-1 && mapz[x][y+1] && !visited[x][y+1])
            q.push(make_pair(make_pair(x, y+1), count+1));
    }

    cout << res+1;

    return 0;
}