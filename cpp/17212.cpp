#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
bool visited[100001];
int minn = 100001;

void loopp(int cur, int cnt)
{
    if(cur == 0)
    {
        if(cur == 0)
            minn = min(minn, cnt);

        return;
    }
    if(visited[cur])
    {
        return;
    }

    visited[cur] = true;
    cnt++;
    if(cur >= 7)
    {
        loopp(cur - 7, cnt);
    }
    if(cur >= 5)
    {
        loopp(cur - 5, cnt);
    }
    if(cur >= 2)
    {
        loopp(cur - 2, cnt);
    }
    if(cur >= 1)
    {
        loopp(cur - 1, cnt);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    loopp(N, 0);
    cout << minn;

    return 0;
}