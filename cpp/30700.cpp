#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

string S;
string korea = "KOREA";
int pos = 0;
int res = 0;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> S;
    for (size_t i = 0; i < S.size(); i++)
    {
        if(S[i] == korea[pos])
        {
            res++;
            pos = (pos + 1) % 5;
        }
    }

    cout << res;

    return 0;
}