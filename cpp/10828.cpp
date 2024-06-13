#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>

using std::cin;
using std::cout;

std::stack<int> st;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int ns;
    cin >> ns;

    for (int i = 0; i < ns; i++)
    {
        std::string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int n;
            cin >> n;
            st.push(n);
        }
        else if(cmd == "pop")
        {
            if(st.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            
            cout << st.top() << "\n";
            st.pop();
        }
        else if(cmd == "size")
        {
            cout << st.size() << "\n";
        }
        else if(cmd == "empty")
        {
            cout << st.empty() << "\n";
        }
        else if(cmd == "top")
        {
            if(st.empty())
            {
                cout << -1 << "\n";
                continue;
            }
            
            cout << st.top() << "\n";
        }
    }

    return 0;
}