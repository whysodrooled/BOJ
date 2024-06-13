#include <bits/stdc++.h>

using namespace std;

int n;
int stair[300];
unsigned int score;
bool doublestep;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> stair[i];
    }

    score = stair[n-1];
    doublestep = false;
    for(int i = n-1; i <= 0;)
    {
        if(stair[i-1] + stair[])
    }
    
    return 0;
}