#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool compare2(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    int n;
    vector<pair<int, int>> v;
    int a, b;
    int result;
    int temp;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }

        sort(v.begin(), v.end(), compare);

        result = 1;
        b = v.at(0).second;
        for(int j = 1; j < n; j++)
        {
            if(v.at(j).second <= b)
            {
                b = v.at(j).second;
                result++;
            }
        }

        sort(v.begin(), v.end(), compare2);

        temp = 1;
        a = v.at(0).first;
        for(int j = 1; j < n; j++)
        {
            if(v.at(j).first <= a)
            {
                a = v.at(j).first;
                temp++;
            }
        }
        if(temp > result) result = temp;
        cout << result << '\n';

        v.clear();
    }
    
    return 0;
}