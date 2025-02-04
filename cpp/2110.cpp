#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll startt, endd, midd, result, placed, curlen;
int house[200001];
int N, C;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> C;
    for (size_t i = 0; i < N; i++)
    {
        cin >> house[i];
    }
    sort(house, house + N);

    startt = 0;
    endd = 1000000000;
    while (startt <= endd)
    {
        placed = 1;
        curlen = 0;
        midd = (startt + endd) / 2;

        for (size_t i = 1; i < N; i++)
        {
            curlen += house[i] - house[i - 1];
            if(curlen >= midd)
            {
                placed++;
                curlen = 0;
            }
        }

        if(placed < C)
        {
            endd = midd - 1;
        }
        else
        {
            result = midd;
            startt = midd + 1;
        }
    }

    cout << result;

    return 0;
}