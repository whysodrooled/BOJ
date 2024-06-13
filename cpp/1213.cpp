#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char temp;

bool findfunc(pair< char, int > p)
{
    return p.first == temp;
}

bool compare(pair< char, int > a, pair< char, int > b)
{
    return a.first < b.first;
}

int main()
{
    string str;
    vector< pair< char, int > > v;
    cin >> str;

    if(str.size() == 1)
    {
        cout << str;
        return 0;
    }

    for(int i = 0; i < str.size(); i++)
    {
        temp = str[i];
        auto it = find_if(v.begin(), v.end(), findfunc);
        if(it != v.end())
        {
            (*it).second++;
        }
        else
        {
            v.push_back(make_pair(temp, 1));
        }
    }

    bool one = true;
    int odd = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].second != 1) one = false;
        if(v[i].second % 2 == 1) odd++;
    }

    if(one
    || (odd > 0 && str.size() % 2 == 0)
    || (odd != 1 && str.size() % 2 == 1))
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    sort(v.begin(), v.end(), compare);

    int idx = -1;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].second % 2 == 1)
        {
            idx = i;

            break;
        }
    }

    int temp2;
    for(int i = 0; i < v.size(); i++)
    {
        temp2 = v[i].second;

        if(temp2 % 2 == 1)
        {
            temp2--;
        }

        temp2 /= 2;
        v[i].second -= temp2;
        while(temp2 > 0)
        {
            cout << v[i].first;
            temp2--;
        }
    }

    if(idx != -1)
    {
        cout << v[idx].first;
        v[idx].second--;
    }

    for(int i = v.size()-1; i >= 0; i--)
    {
        temp2 = v[i].second;
        while(temp2 > 0)
        {
            cout << v[i].first;
            temp2--;
        }
    }
    
    return 0;
}