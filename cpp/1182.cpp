#include <bits/stdc++.h>

using namespace std;

/*
15 -7
6 -4 1 3 -8 5 -4 -3 7 -4 9 -9 -3 -4 -4

정답: 1203
출력: 1201


15 17
9 -2 2 -2 1 -3 5 -3 -4 1 0 -9 0 7 1

정답: 328
출력: 327


19 6
-8 2 -8 -8 -7 -8 -5 2 1 4 5 7 -6 7 4 8 -3 -5 -4

정답: 6921
출력: 6918
*/

int result = 0;
int N, S;

void recur(int idx, int sums, int* nums)
{
    if(idx != 0 && sums == S)
    {
        result++;
    }

    for (size_t i = idx; i < N; i++)
    {
        sums += nums[i];
        recur(i+1, sums, nums);
        sums -= nums[i];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> S;
    int nums[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    recur(0, 0, nums);
    cout << result;

    return 0;
}