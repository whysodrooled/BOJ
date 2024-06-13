#include <bits/stdc++.h>

using namespace std;

string s;
vector<pair<char, int>> v;
char fuck;

bool findfunc(pair<char, int> item)
{
    return fuck == item.first;
}

int main()
{
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        fuck = s[i];
        if(find_if(v.begin(), v.end(), findfunc) == v.end())
        {
            v.push_back(make_pair(s[i], i));
        }
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        fuck = i;
        auto it = find_if(v.begin(), v.end(), findfunc);
        if(it != v.end())
        {
            cout << (*it).second;
        }
        else
        {
            cout << -1;
        }

        cout << ' ';
    }

    return 0;
}