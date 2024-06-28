#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int minn = 4;
queue<pair<int, int>> q;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        auto info = q.front();
        q.pop();

        if(info.second >= minn)
        {
            continue;
        }

        if(info.first == 0)
        {
            minn = min(minn, info.second);
            continue;
        }

        for (int i = floor(pow(info.first, 0.5)); i > 0; i--)
        {
            if(info.second + 1 < minn)
                q.push(make_pair(info.first - (i * i), info.second + 1));
        }
    }

    cout << minn;

    return 0;
}