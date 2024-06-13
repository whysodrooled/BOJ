#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using std::cin;
using std::cout;

std::vector<std::pair<int, int>> arr;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back(std::make_pair(x, y));
    }

    std::sort(arr.begin(), arr.end());
    for (size_t i = 0; i < n; i++)
    {
        int x, y;
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }

    return 0;
}