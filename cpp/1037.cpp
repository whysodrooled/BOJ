#include <bits/stdc++.h>

using namespace std;

int N;
int nums[50];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums+N);
    cout << nums[0] * nums[N - 1];

    return 0;
}