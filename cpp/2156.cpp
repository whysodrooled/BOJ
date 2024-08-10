// https://www.acmicpc.net/board/view/139143
// https://beginnerdeveloper-lit.tistory.com/109

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int wine[10001];
int maxx[10003] = {0};
int N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> wine[i];
    }

    maxx[0] = wine[0];
    maxx[1] = wine[0] + wine[1];
    maxx[2] = max(maxx[1], max(maxx[0] + wine[2], wine[1] + wine[2]));

    for (size_t i = 3; i < N; i++)
    {
        maxx[i] = max(maxx[i-1], max(maxx[i-2] + wine[i], maxx[i-3] + wine[i-1] + wine[i]));
    }
    
    cout << maxx[N-1];

    return 0;
}