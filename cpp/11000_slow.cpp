#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> v[200000];
vector<int> inuse;
int lol = 0;
int temp;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool findfunc(int a)
{
    return a <= temp;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> n;
    int a, b;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    sort(v, v+n, compare);

    if(n > 50000) n = 50000;

    for(int i = 0; i < n; i++)
    {
        temp = v[i].first;
        auto it = find_if(inuse.begin(), inuse.end(), findfunc);
        if(it == inuse.end())
        {
            inuse.push_back(v[i].second);
        }
        else
        {
            *it = v[i].second;
        }
    }

    cout << inuse.size();
    
    return 0;
}