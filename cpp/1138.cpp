#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
int peeps[10];
vector<int> lol;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> peeps[i];
    }
    
    for (int i = N; i > 0; i--)
    {
        int loc = 0;
        int bigg = 0;
        for (; loc < N-i; loc++)
        {
            if(bigg >= peeps[i-1])
            {
                break;
            }
            bigg++;
        }

        lol.insert(lol.begin() + loc, i);
    }

    for (size_t i = 0; i < lol.size(); i++)
    {
        cout << lol[i] << ' ';
    }
    
    return 0;
}