#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int curCount;
bool builds[25][25] = {false};
bool visited[25][25] = {false};
priority_queue<int, vector<int>, greater<int>> pq;

void recur(int i, int j)
{
    if(i < 0 || i >= N
    || j < 0 || j >= N
    || visited[i][j] || !builds[i][j])
        return;

    visited[i][j] = true;
    curCount++;

    recur(i, j-1);
    recur(i, j+1);
    recur(i-1, j);
    recur(i+1, j);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            if(str[j] == '1')
            {
                builds[i][j] = true;
            }
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(builds[i][j])
            {
                curCount = 0;
                recur(i, j);
                if(curCount > 0)
                    pq.push(curCount);
            }
        }
    }

    cout << pq.size() << '\n';

    while(!pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}