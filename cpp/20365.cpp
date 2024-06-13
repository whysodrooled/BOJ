#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char color[500001]; // 500000 + 1 for reserving 0...

    cin >> n;
    cin >> color;

    unsigned int red = 0;
    unsigned int blue = 0;

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            if(color[i] == 'R')
            {
                red++;
            }
            if(color[i] == 'B')
            {
                blue++;
            }
        }
        else
        {
            if(color[i] == 'R' && color[i-1] == 'B')
            {
                red++;
            }
            if(color[i] == 'B' && color[i-1] == 'R')
            {
                blue++;
            }
        }
    }

    cout << min(red, blue) + 1;
    
    return 0;
}