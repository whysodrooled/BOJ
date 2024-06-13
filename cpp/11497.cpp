#include <bits/stdc++.h>

using namespace std;

int t, n;
int l[10000];
int result = 0;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> t;

    while(t > 0)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        
        sort(l, l+n, compare);

        result = 0;
        for(int i = 2; i < n; i++)
        {
            result = max(result, l[i-2] - l[i]);
        }

        cout << result << '\n';
        
        t--;
    }
    
    return 0;
}