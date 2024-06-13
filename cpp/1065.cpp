#include <bits/stdc++.h>

using namespace std;

int t;
int result = 0;
int diff;
bool skip;
int temp = 0;

int main()
{
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        if(i >= 100)
        {
            skip = false;
            diff = (i % 10) - ((i / 10) % 10);
            temp = i / 10;
            while(temp >= 10)
            {
                if(((temp % 10) - ((temp / 10) % 10)) != diff)
                {
                    skip = true;
                    break;
                }
                temp /= 10;
            }

            if(!skip) result++;
        }
        else
        {
            result++;
        }
    }
    
    cout << result;
    return 0;
}