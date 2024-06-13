#include <bits/stdc++.h>
using namespace std;

int n;
long long int w;
int s[15];
long long int coin = 0;
int temp;
bool dir;

int main()
{
    cin >> n >> w;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    temp = s[0];
    dir = true;

    for(int i = 1; i < n; i++)
    {
        if(dir)
        {
            if(temp < s[i])
            {
                dir = false;
                coin = w / temp;
                w -= (w / temp) * temp;
            }
            temp = s[i];
        }
        else
        {
            if(temp > s[i])
            {
                dir = true;
                w += coin * temp;
                coin = 0;
            }

            temp = s[i];
        }
    }

    if(coin > 0)
    {
        w += coin * temp;
    }

    cout << w;
    
    return 0;
}