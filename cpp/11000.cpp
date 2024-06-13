#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> inuse;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
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
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++)
    {
        inuse.push(v[i].second);

        if(inuse.top() <= v[i].first)
        {
            inuse.pop();
        }
    }

    cout << inuse.size();
    
    return 0;
}