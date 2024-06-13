#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int students[300001];
vector<int> diff;
int result = 0;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> students[i];
    }
    for(int i = 1; i < n; i++)
    {
        diff.push_back(students[i] - students[i-1]);
    }

    sort(diff.begin(), diff.end(), compare);

    for(int i = k-1; i < diff.size(); i++)
    {
        result += diff[i];
    }

    cout << result;
    
    return 0;
}