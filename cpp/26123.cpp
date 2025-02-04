#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, D;
int builds[300001] = {0};
unsigned long long res = 0;
int curpoint = 0;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        builds[temp]++;
        curpoint = max(curpoint, temp);
    }

    while (curpoint > 0 && D > 0)
    {
        res += builds[curpoint];
        builds[curpoint - 1] += builds[curpoint];
        curpoint--;
        D--;
    }

    cout << res;

    return 0;
}