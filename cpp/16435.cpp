#include <bits/stdc++.h>
using namespace std;

int n, l;
priority_queue<int, vector<int>, greater<int>> fruit;

int main()
{
    cin >> n >> l;

    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        fruit.push(temp);
    }

    for(int i = 0; i < n; i++)
    {
        if(fruit.top() > l) break;
        l++;
        fruit.pop();
    }

    cout << l;
    
    return 0;
}