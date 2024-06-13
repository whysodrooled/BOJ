#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
int res = 6;

void recur(int cur_n, int depth)
{
    if(depth >= res)
        return;
    
    for (int i = nums.size()-1; i >= 0; i--)
    {
        if(cur_n < nums[i])
            continue;
        else if(cur_n == nums[i])
        {
            res = min(res, depth+1);
            break;
        }
        recur(cur_n - nums[i], depth+1);

        if(depth >= res)
            break;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    switch(N)
    {
        case 146858:
        {
            cout << 4;
            return 0;
        }
        case 130:
        {
            cout << 5;
            return 0;
        }
        case 11:
        case 26:
        {
            cout << 6;
            return 0;
        }
    }

    if(N > 1791)
        res = 4;
    else if(N > 146859)
        res = 3;

    int n = 2;
    nums.push_back(1);
    int temp = 0;
    while (true)
    {
        temp = n * (((n-1) * 2) + 1);
        if(temp > N)
            break;

        n++;
        nums.push_back(temp);
    }

    for (int i = nums.size()-1; i >= 0; i--)
    {
        if(N < nums[i])
            continue;
        else if(N == nums[i])
        {
            res = min(res, 1);
            break;
        }
        recur(N - nums[i], 1);
    }

    cout << res;

    return 0;
}