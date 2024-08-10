#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int prices[1001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i/2; j++)
        {
            prices[i-1] = max(prices[i-1], prices[i-j-1] + prices[j-1]);
        }
    }

    cout << prices[N-1] << ' ';

    return 0;
}