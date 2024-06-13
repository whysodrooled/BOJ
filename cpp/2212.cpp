#include <bits/stdc++.h>

using namespace std;

int n, k;
int temp;
vector<int> sensor;
priority_queue<int> diff;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        sensor.push_back(temp);
    }

    sort(sensor.begin(), sensor.end());

    for(int i = 1; i < n; i++)
    {
        diff.push(sensor[i] - sensor[i-1]);
    }

    temp = 0;
    if(!diff.empty())
    {
        for(int i = 0; i < k-1; i++)
        {
            diff.pop();
        }

        while(!diff.empty())
        {
            temp += diff.top();
            diff.pop();
        }
    }

    cout << temp;
    
    return 0;
}