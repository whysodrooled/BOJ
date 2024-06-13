#include <bits/stdc++.h>

using namespace std;

int t;
int n, m;
int temp;
unsigned long long int lol;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t > 0)
    {
        cin >> n >> m;

        lol = 1;
        temp = 1;
        for(int i = m; i > m-n; i--)
        {
            lol *= i;
            lol /= temp;
            temp++;
        }

        cout << lol << '\n';

        t--;
    }
    
    return 0;
}