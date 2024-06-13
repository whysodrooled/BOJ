#include <bits/stdc++.h>

using namespace std;

int n;
int frown[500001];
unsigned long long int lol = 0;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> frown[i];
    }

    sort(frown, frown+n);

    for(int i = 0; i < n; i++)
    {
        lol += abs((i+1) - frown[i]);
    }

    cout << lol;
    
    return 0;
}