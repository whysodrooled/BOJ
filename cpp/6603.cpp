#include <bits/stdc++.h>

using std::cin, std::cout;

int k;
std::deque<int> st;

void recur(int idx, int* nums)
{
    if(st.size() == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << st[i] << ' ';
        }

        cout << '\n';
        
        return;
    }
    
    for (int i = 0; i <= k - 6; i++)
    {
        if(idx+i >= k || (!st.empty() && nums[idx+i] < st.back()))
            continue;

        st.push_back(nums[idx+i]);
        recur(idx+i+1, nums);
        st.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    cin >> k;
    while (k > 0)
    {
        st = std::deque<int>();
        int nums[k];
        for (size_t i = 0; i < k; i++)
        {
            cin >> nums[i];
        }

        recur(0, nums);

        cin >> k;
        cout << '\n';
    }

    return 0;
}