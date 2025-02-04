#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, K;
char inp[20001];
int res = 0;
bool occupied[20000] = {false};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    cin >> inp;
    for (int i = 0; i < N; i++)
    {
        if(inp[i] == 'P')
        {
            for (int j = max(0, i-K); j <= min(i+K, N-1); j++)
            {
                if(inp[j] == 'H' && !occupied[j])
                {
                    res++;
                    occupied[j] = true;
                    break;
                }
            }
        }
    }

    cout << res;

    return 0;
}