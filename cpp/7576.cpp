#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M;
int tomato[1001][1001];
int tomatoes = 0;
int days = -1;
queue<pair<pair<int, int>, int>> q;
int lol[] = {0, 0, 1, -1};
int lol2[] = {1, -1, 0, 0};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            string str;
            cin >> str;
            tomato[i][j] = stoi(str);
            if(tomato[i][j] == 1)
            {
                q.push(make_pair(make_pair(i, j), 0));
            }
            else if(tomato[i][j] == 0)
            {
                tomatoes++;
            }
        }
    }

    if(tomatoes == 0)
    {
        days = 0;
    }
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int x2 = x + lol[i];
            int y2 = y + lol2[i];
            if(x2 < 0 || x2 >= N
            || y2 < 0 || y2 >= M)
                continue;
            
            if(tomato[x2][y2] == 0)
            {
                q.push(make_pair(make_pair(x2, y2), d+1));
                tomato[x2][y2] = 1;
                tomatoes--;

                if(tomatoes == 0)
                {
                    days = d+1;
                    break;
                }
            }
        }
        
    }

    cout << days;

    return 0;
}