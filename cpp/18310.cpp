#include <bits/stdc++.h>

using namespace std;

int n;
int house[200000];
priority_queue<int> q;
int result = 0;
int temp;

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> house[i];
    }

    sort(house, house+n);

    temp = (n - 1) / 2;
    cout << house[temp];
    
    return 0;
}