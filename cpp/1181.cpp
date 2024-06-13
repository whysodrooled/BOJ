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

std::vector<std::string> strs;

bool compare(std::string a, std::string b)
{
    if(a.size() == b.size())
    {
        return a < b;
    }

    return a.size() < b.size();
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string lol;
        cin >> lol;

        strs.push_back(lol);
    }

    std::sort(strs.begin(), strs.end(), compare);
    strs.erase(std::unique(strs.begin(), strs.end()), strs.end());
    int test = strs.size();
    for (int i = 0; i < strs.size(); i++)
    {
        cout << strs[i] << "\n";
    }

    return 0;
}