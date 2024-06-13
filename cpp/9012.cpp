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

std::stack<bool> st;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::string str;
        cin >> str;

        bool valid = true;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                st.push(true);
            }
            else
            {
                if(st.empty())
                {
                    valid = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }

        cout << (st.empty() && valid ? "YES" : "NO") << '\n';
        st = std::stack<bool>();
    }
    

    return 0;
}