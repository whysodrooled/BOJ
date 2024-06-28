#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int ways[1001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    ways[1] = 1;
    ways[2] = 3;
    for (size_t i = 3; i <= N; i++)
    {
        ways[i] = (ways[i-1] + (ways[i-2])*2) % 10007;
    }

    cout << ways[N];

    return 0;
}