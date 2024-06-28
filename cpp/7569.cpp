#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M, H;
int tomato[101][101][101];
int tomatoes = 0;
int days = -1;
queue<pair<pair<pair<int, int>, int>, int>> q;
int lol[] = {0, 0, 1, -1, 0, 0};
int lol2[] = {1, -1, 0, 0, 0, 0};
int lol3[] = {0, 0, 0, 0, 1, -1};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N >> H;
    for (size_t h = 0; h < H; h++)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                string str;
                cin >> str;
                tomato[i][j][h] = stoi(str);
                if(tomato[i][j][h] == 1)
                {
                    q.push(make_pair(make_pair(make_pair(i, j), h), 0));
                }
                else if(tomato[i][j][h] == 0)
                {
                    tomatoes++;
                }
            }
        }
    }
    

    if(tomatoes == 0)
    {
        days = 0;
    }
    
    while(!q.empty())
    {
        int x = q.front().first.first.first;
        int y = q.front().first.first.second;
        int h = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for (size_t i = 0; i < 6; i++)
        {
            int x2 = x + lol[i];
            int y2 = y + lol2[i];
            int h2 = h + lol3[i];
            if(x2 < 0 || x2 >= N
            || y2 < 0 || y2 >= M
            || h2 < 0 || h2 >= H)
                continue;
            
            if(tomato[x2][y2][h2] == 0)
            {
                tomato[x2][y2][h2] = 1;
                tomatoes--;

                if(tomatoes == 0)
                {
                    days = d+1;
                    break;
                }
                q.push(make_pair(make_pair(make_pair(x2, y2), h2), d+1));
            }
        }
        
    }

    cout << days;

    return 0;
}