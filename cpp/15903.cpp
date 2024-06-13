#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    unsigned long long int cards[1000];
    for(int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    for(int i = 0; i < m; i++)
    {
        sort(cards, cards+n);
        cards[0] += cards[1];
        cards[1] = cards[0];
    }

    unsigned long long int result = 0;
    for(int i = 0; i < n; i++)
    {
        result += cards[i];
    }

    cout << result;
    
    return 0;
}