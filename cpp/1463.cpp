#include <bits/stdc++.h>

using namespace std;

int n;
int res = 0;
bool visited[1000001] = {false};
queue<pair<int, int>> q;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    q.push(make_pair(n, 0));
    while(!q.empty())
    {
        auto info = q.front();
        q.pop();

        if(info.first == 1)
        {
            cout << info.second;
            break;
        }

        if(visited[info.first])
            continue;

        visited[info.first] = true;
        if(info.first % 3 == 0 && !visited[info.first/3])
            q.push({info.first/3, info.second+1});
        if(info.first % 2 == 0 && !visited[info.first/2])
            q.push({info.first/2, info.second+1});
        
        q.push({info.first-1, info.second+1});
    }

    return 0;
}