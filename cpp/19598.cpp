#include <bits/stdc++.h>

using namespace std;

/*struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};*/

int n;
int a, b;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> v2;
int result = 0;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++)
    {
        while(!v2.empty() && v2.top() <= v[i].first)
        {
            v2.pop();
        }

        v2.push(v[i].second);
        result = max(result, int(v2.size()));
    }

    cout << result;
    
    return 0;
}