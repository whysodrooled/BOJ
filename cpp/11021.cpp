#include <bits/stdc++.h>

using namespace std;

int t;
int a, b;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a+b << '\n';
    }
    
    return 0;
}