#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int X, Y, E;
int x[1001], y[1001], e[1001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> X >> Y >> E;
    int res = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> e[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        int temp = max(0, (E - (abs(X-x[i]) + abs(Y-y[i]))));

        for (size_t j = 0; j < N; j++)
        {
            temp -= max(0, (e[j] - (abs(x[j]-x[i]) + abs(y[j]-y[i]))));
            if(temp <= 0)
                break;
        }

        res = max(res, temp);
    }
    
    if(res == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << res;
    }

    return 0;
}