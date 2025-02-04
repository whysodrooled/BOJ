#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll money[10001];
ll start, endd, mid, sum, result;
ll maxx = 0;
int N, M;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> money[i];
        maxx = max(maxx, money[i]);
    }
    cin >> M;

    start = 0;
    endd = M;
    while (start <= endd)
    {
        sum = 0;
        mid = (start + endd) / 2;

        for (size_t i = 0; i < N; i++)
        {
            sum += min(mid, money[i]);
        }

        if(sum > M)
        {
            endd = mid - 1;
        }
        else
        {
            result = mid;
            start = mid + 1;
        }
    }
    
    if(result == M)
        cout << maxx;
    else
        cout << result;

    return 0;
}