#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M;
int lol[9];

void cancer(int pos)
{
    for (size_t i = 1; i <= N; i++)
    {
        if(pos > 1 && lol[pos - 2] > i)
            continue;
        
        lol[pos - 1] = i;
        if(pos == M)
        {
            for (size_t j = 0; j < M; j++)
            {
                cout << lol[j] << ' ';
            }
            cout << '\n';
        }
        else
        {
            cancer(pos + 1);
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    cancer(1);

    return 0;
}