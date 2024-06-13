#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> weight;
int temp;
int result = 0;

int main()
{
    cin >> n >> m;
    /*if(n == 0)
    {
        cout << 0;
        return 0;
    }*/

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        weight.push(temp);
    }

    temp = 0;
    while(weight.size() > 0)
    {
        if(temp < weight.front())
        {
            temp = m;
            result++;
        }
        temp -= weight.front();
        weight.pop();
    }

    cout << result;
    
    return 0;
}