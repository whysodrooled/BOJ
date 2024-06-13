#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, pair<int, int>>> v;
int a, b;
int temp;

bool findfunc(pair<int, pair<int, int>> a)
{
    return a.first == temp;
}

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.second > a.second.second;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    while(n > 0)
    {
        cin >> a >> b;
        temp = a;
        auto it = find_if(v.begin(), v.end(), findfunc);
        if(it == v.end())
        {
            v.push_back(make_pair(a, make_pair(b, 0)));
        }
        else if((*it).second.first != b)
        {
            (*it).second.second++;
            (*it).second.first = b;
        }

        n--;
    }

    temp = 0;
    for(int i = 0; i < v.size(); i++)
    {
        temp += v[i].second.second;
    }

    cout << temp;
    
    return 0;
}