#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool comps[10];
bool used[10];
ll maxx = 0;
ll minn = 10000000000;
int N;

void searc(ll cur, int pos, int prevv)
{
    cur *= 10;

    if(pos < N-1)
    {
        for (int i = 0; i <= 9; i++)
        {
            if(used[i])
                continue;

            if((comps[pos] && prevv >= i)
            || (!comps[pos] && prevv <= i))
                continue;

            cur += i;
            used[i] = true;

            searc(cur, pos + 1, i);

            cur -= i;
            used[i] = false;
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            if(used[i])
                continue;
            
            if((comps[pos] && prevv >= i)
            || (!comps[pos] && prevv <= i))
                continue;

            cur += i;

            maxx = max(maxx, cur);
            minn = min(minn, cur);

            cur -= i;
        }
    }

    cur /= 10;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        char lol;
        cin >> lol;
        if(lol == '<')
            comps[i] = true;
        else
            comps[i] = false;
    }

    for (int i = 0; i <= 9; i++)
    {
        used[i] = true;
        searc(i, 0, i);
        used[i] = false;
    }
    
    cout << std::setfill('0') << std::setw(N+1) << maxx;
    cout << '\n';
    cout << std::setfill('0') << std::setw(N+1) << minn;

    return 0;
}