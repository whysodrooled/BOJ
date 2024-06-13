#include <bits/stdc++.h>

using namespace std;

int initmoney;
int bnp;
int bnp_s;
int timing;
int timing_s;
int timing_stores = 0;
vector<int> v;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> initmoney;
    for(int i = 0; i < 14; i++)
    {
        cin >> bnp;
        v.push_back(bnp);
    }

    bnp = initmoney;
    bnp_s = 0;
    timing = initmoney;
    timing_s = 0;

    for(int i = 0; i < 13; i++)
    {
        if(bnp >= v[i])
        {
            bnp_s += (bnp / v[i]);
            bnp -= (bnp / v[i]) * v[i];
        }

        if(i > 0)
        {
            if(v[i] > v[i-1])
            {
                if(timing_stores < 0) timing_stores = 0;
                timing_stores++;
            }
            else if(v[i] < v[i-1])
            {
                if(timing_stores > 0) timing_stores = 0;
                timing_stores--;
            }
            else
            {
                timing_stores = 0;
            }
        }

        if(timing_stores >= 3)
        {
            timing += timing_s * v[i];
            timing_s = 0;
        }
        else if(timing_stores <= -3)
        {
            if(timing >= v[i])
            {
                timing_s += (timing / v[i]);
                timing -= (timing / v[i]) * v[i];
            }
        }
    }

    bnp += bnp_s * v[13];
    timing += timing_s * v[13];
    
    if(bnp > timing)
    {
        cout << "BNP";
    }
    else if(bnp < timing)
    {
        cout << "TIMING";
    }
    else
    {
        cout << "SAMESAME";
    }
    
    return 0;
}