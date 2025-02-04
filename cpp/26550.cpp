#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int T, N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (size_t _ = 0; _ < T; _++)
    {
        cin >> N;
        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            res += i * (N - i + 1);
        }

        cout << res << '\n';
    }

    return 0;
}