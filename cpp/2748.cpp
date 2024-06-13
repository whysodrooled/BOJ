#include <bits/stdc++.h>

using namespace std;

unsigned long long int memo[91];
int n;

int main()
{
    cin >> n;

    memo[0] = 0;
    memo[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        memo[i] = memo[i-1] + memo[i-2];
    }

    cout << memo[n];
    
    return 0;
}