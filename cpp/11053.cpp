#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using std::cin;
using std::cout;

std::vector<int> vec;

int findLong(int idx)
{
    int curcount = 1;
    int curcount2 = 0;
    int num = vec[idx];
    std::vector<int> nums;
    for (size_t i = idx+1; i < vec.size(); i++)
    {
        if(num < vec[i])
        {
            num = vec[i];
            curcount++;
        }
        else if(num > vec[i])
        {
            std::max(curcount2, findLong(i));
        }
    }

    return std::max(curcount, curcount2);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    cout << findLong(0);

    return 0;
}