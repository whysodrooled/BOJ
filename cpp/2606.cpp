#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nodes[101];
bool visited[101] = {false};
queue<int> q;
int C, N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> C >> N;

    for (size_t i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    int res = -1;
    q.push(1);
    while(!q.empty())
    {
        int num = q.front();
        q.pop();

        if(visited[num])
            continue;

        res++;
        visited[num] = true;
        for (int i = 0; i < nodes[num].size(); i++)
        {
            if(!visited[nodes[num][i]])
            {
                q.push(nodes[num][i]);
            }  
        }
    }

    cout << res;

    return 0;
}