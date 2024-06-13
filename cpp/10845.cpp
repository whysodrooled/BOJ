#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

using std::cin;
using std::cout;

std::queue<int> qq;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int ns;
    cin >> ns;

    for(int i = 0; i < ns; i++)
    {
        std::string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int n;
            cin >> n;
            qq.push(n);
        }
        else if(cmd == "pop")
        {
            if(qq.empty())
            {
                cout << -1 << "\n";
                continue;
            }

            cout << qq.front() << "\n";
            qq.pop();
        }
        else if(cmd == "size")
        {
            cout << qq.size() << "\n";
        }
        else if(cmd == "empty")
        {
            cout << qq.empty() << "\n";
        }
        else if(cmd == "front")
        {
            if(qq.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            
            cout << qq.front() << "\n";
        }
        else if(cmd == "back")
        {
            if(qq.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            
            cout << qq.back() << "\n";
        }
    }

    return 0;
}