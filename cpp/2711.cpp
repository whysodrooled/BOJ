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

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int loop;
    cin >> loop;
    for (size_t i = 0; i < loop; i++)
    {
        int idx;
        std::string str;
        cin >> idx >> str;
        str.erase(str.begin() + idx - 1);
        cout << str << '\n';
    }
    

    return 0;
}