#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

string cards[1001];
int T;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while (T > 0)
    {
        for (size_t i = 0; i < T; i++)
        {
            cin >> cards[i];
        }
        
        if(T % 2 == 1)
        {
            for (size_t i = 0; i < T/2; i++)
            {
                cout << cards[i] << '\n';
                cout << cards[T/2+i+1] << '\n';
            }
            
            if(T % 2 == 1)
                cout << cards[T / 2] << '\n';
        }
        else
        {
            for (size_t i = 0; i < T/2; i++)
            {
                cout << cards[i] << '\n';
                cout << cards[T/2+i] << '\n';
            }
        }
        
        cin >> T;
    }

    return 0;
}