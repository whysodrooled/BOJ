#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, K;
queue<pair<int, int>> q;
bool visited[100001] = {false};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    q.push(make_pair(N, 0));
    pair<int, int> pops;
    while(!q.empty())
    {
        pops = q.front();
        q.pop();

        if(visited[pops.first])
            continue;

        if(pops.first == K)
        {
            cout << pops.second;
            break;
        }

        visited[pops.first] = true;

        if(pops.first+1 <= 100000 && !visited[pops.first+1])
            q.push(make_pair(pops.first+1, pops.second+1));
        if(pops.first-1 >= 0 && !visited[pops.first-1])
            q.push(make_pair(pops.first-1, pops.second+1));
        if(pops.first*2 <= 100000 && !visited[pops.first*2])
            q.push(make_pair(pops.first*2, pops.second+1));
    }

    return 0;
}