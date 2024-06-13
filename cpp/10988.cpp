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

std::string str;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    cin >> str;
    std::string latter(str.substr(0, str.size() / 2));
    std::reverse(latter.begin(), latter.end());

    cout << (str.substr(str.size() / 2 + str.size() % 2, str.size()) == latter) << '\n';

    return 0;
}