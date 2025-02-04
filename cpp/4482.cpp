#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int T;
int side, total, temp;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> side;
        total = 1;
        temp = 1;
        for (int j = 2; j <= side; j++)
        {
            temp += j;
            total += temp;
        }

        cout << i + 1 << ": " << side << ' ' << total << '\n';
    }
    
    return 0;
}