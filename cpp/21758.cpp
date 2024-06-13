#include <bits/stdc++.h>

using namespace std;

int n;
int honey[100002];
int summ[100001] = {0};
int result = 0;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> honey[i];
        summ[i] = summ[i-1] + honey[i];
    }

    for(int i = 2; i < n; i++)
    {
        result = max(result,
        (summ[i] - summ[1]) + (summ[n - 1] - summ[i - 1]));
    }
    for(int i = 2; i < n; i++)
    {
        result = max(result,
        (summ[n] - summ[1] - honey[i]) + (summ[n] - summ[i]));
    }
    for(int i = 2; i < n; i++)
    {
        result = max(result,
        (summ[n-1] - honey[i]) + summ[i - 1]);
    }

    cout << result;
    
    return 0;
}