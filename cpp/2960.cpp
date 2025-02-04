#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool mark[1001] = {false};
int N, K;
int fuck = 0;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 2; i <= N; i++)
    {
        if(!mark[i])
        {
            mark[i] = true;
            fuck++;

            if(fuck >= K)
            {
                cout << i;
                break;
            }
            
            for (int j = i*2; j <= N; j += i)
            {
                if(!mark[j])
                {
                    mark[j] = true;
                    fuck++;
                    if(fuck >= K)
                    {
                        cout << j;
                        break;
                    }
                }
            }

            if(fuck >= K)
            {
                break;
            }
        }
    }

    return 0;
}