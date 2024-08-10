// V = Ax - (B-1)x

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int A, B, V;
ll start = 0;
ll endd = 1000000000;
ll midd, sum;
ll result;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> A >> B >> V;

    while (start <= endd)
    {
        midd = (start + endd) / 2;
        sum = (A-B)*midd + B;

        if(sum < V)
        {
            start = midd + 1;
        }
        else
        {
            result = midd;
            endd = midd - 1;
        }
    }

    cout << result;

    return 0;
}