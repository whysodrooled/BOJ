#include <bits/stdc++.h>

using namespace std;

int T;

int recur(int tgt, int num)
{
    if(num > tgt)
        return 0;
    else if(num == tgt)
        return 1;

    int res = 0;
    res += recur(tgt, num + 1);
    res += recur(tgt, num + 2);
    res += recur(tgt, num + 3);

    return res;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    int nums[T];
    for (size_t i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        cout << recur(n, 0) << '\n';
    }

    return 0;
}