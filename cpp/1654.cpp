#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll K, N;
ll lans[10001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll start = 1;
    ll end = 0;
    cin >> K >> N;
    for (size_t i = 0; i < K; i++)
    {
        cin >> lans[i];
        end = max(end, lans[i]);
    }

    ll mid, result;
    ll sum;
    while(start <= end)
    {
        sum = 0;
        mid = (start + end) / 2;

        for (size_t i = 0; i < K; i++)
        {
            sum += lans[i] / mid;
        }
        
        if(sum < N)
        {
            end = mid-1;
        }
        else
        {
            result = mid; // 최대 길이라 ==가 아니라 >=
            start = mid + 1;
        }
    }

    cout << result;

    return 0;
}