#include <bits/stdc++.h>

using namespace std;

int temp[28];
int temp2;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 28; i++)
    {
        cin >> temp[i];
    }

    sort(temp, temp+28);
    temp2 = 0;
    for(int i = 1; i <= 30; i++)
    {
        if(i == temp[temp2] && temp2 < 28)
        {
            temp2++;
        }
        else
        {
            cout << i << '\n';
        }
    }
    
    return 0;
}