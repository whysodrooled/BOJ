#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, K;
int needed[100001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        needed[i] = max(0, b - a);
    }
    sort(needed, needed + N);
    cout << needed[K - 1];

    return 0;
}