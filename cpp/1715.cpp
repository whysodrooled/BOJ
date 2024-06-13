#include <bits/stdc++.h>

using namespace std;

int n;
int result = 0;
int temp;
priority_queue<int, vector<int>, greater<int>> cards;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        cards.push(temp);
    }

    while(cards.size() > 1)
    {
        temp = 0;
        temp += cards.top();
        cards.pop();
        temp += cards.top();
        cards.pop();
        cards.push(temp);
        result += temp;
    }

    cout << result;
    
    return 0;
}