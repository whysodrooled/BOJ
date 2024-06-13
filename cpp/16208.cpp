#include <bits/stdc++.h>
using namespace std;

int n;
//int length[500000];
unsigned long long int lenmax = 0;
unsigned long long int temp;
unsigned long long int result = 0;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(i >= 1)
        {
            result += lenmax * temp;
            lenmax += temp;
        }
        else
        {
            lenmax = temp;
        }
    }

    if(n == 1)
    {
        cout << 0;
        return 0;
    }

    cout << result;
    
    return 0;
}