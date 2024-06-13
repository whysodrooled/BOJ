#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int temp;
int temp2;
int lol = 10;

int main()
{
    for(int i = 1; i <= 10000; i++)
    {
        temp = i;
        temp2 = 0;
        while(temp > 0)
        {
            temp2 += temp%lol;
            temp /= lol;
        }

        temp2 += i;
        
        if(find(v.begin(), v.end(), temp2) == v.end())
        {
            v.push_back(temp2);
        }
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(find(v.begin(), v.end(), i) == v.end())
        {
            cout << i << '\n';
        }
    }
    
    return 0;
}