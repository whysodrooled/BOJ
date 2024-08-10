// https://danidani-de.tistory.com/5

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, K;
int money[101] = {0};
int ways[10001] = {0};

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> money[i];
    }
    sort(money, money + N);

    ways[0] = 1;

    for (int n = 0; n < N; n++)
    {
        for (int i = money[n]; i <= K; i++)
        {
            ways[i] += ways[i - money[n]];
        }
    }

    cout << ways[K];

    return 0;
}