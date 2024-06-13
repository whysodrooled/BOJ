// https://chanhuiseok.github.io/posts/baek-16/
// looked

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll N, M;
char powzz[125001] = {0};
ll res = 0;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    res = M-N;
    ll lol = 0;

    for (ll i = 2; i*i <= res; i++)
    {
        if(powzz[i/8] & (1 << (i%8)))
            continue;

        ll start = N / (i * i);
        start *= (i * i);

        if(start < N)
        {
            start += (i * i);
        }

        for (ll j = start; j <= M; j+=i*i)
        {
            if(!(powzz[(j-start)/8] & (1 << ((j-start)%8))))
            {
                powzz[(j-start) / 8] |= (1 << ((j-start) % 8));
                lol++;
                //cout << (j-start+(i*i)) << ' ';
            }
        }

        //cout << "\n";
    }

    cout << res-lol+1 << ' ' << lol;

    return 0;
}