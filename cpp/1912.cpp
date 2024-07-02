#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int maxx;
int N, n;
int nums[100001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> nums[0];
    maxx = nums[0];
    for (int i = 1; i < N; i++)
    {
        cin >> nums[i];

        nums[i] = max(nums[i], nums[i]+nums[i-1]);

        maxx = max(nums[i], maxx);
    }

    cout << maxx;

    return 0;
}