#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int ans = 4;

void recur(int num, int count)
{
    if(count >= ans)
        return;

    for (int i = 1; i * i <= num; i++)
    {
        if(i*i == num)
        {
            ans = min(ans, count);
            return;
        }
        recur(num - (i * i), count + 1);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    recur(N, 1);
    cout << ans;

    return 0;
}