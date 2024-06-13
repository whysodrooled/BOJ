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

std::deque<char> result;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        result.push_back(str[i]);
    }

    int cmds;
    int pos = str.size();
    cin >> cmds;
    for (int i = 0; i < cmds; i++)
    {
        char cmd;
        cin >> cmd;

        if(cmd == 'P')
        {
            cin >> cmd;
            result.push_back(cmd);
            pos++;
        }
        else if(cmd == 'B')
        {
            if(pos <= 0)
                continue;

            result.pop_back();
            pos--;
        }
        else if(cmd == 'L')
        {
            if(pos <= 0)
                continue;

            result.push_front(result.back());
            result.pop_back();
            pos--;
        }
        else if(cmd == 'D')
        {
            if(pos >= result.size())
                continue;

            result.push_back(result.front());
            result.pop_front();
            pos++;
        }
    }

    std::rotate(result.begin(), result.end() - pos, result.end());
    
    std::string ress(result.begin(), result.end());
    cout << ress;

    return 0;
}