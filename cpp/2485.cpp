#include <bits/stdc++.h>

using namespace std;

int N;
int trees[100001];
vector<int> lenzz;

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    for (size_t i = 1; i < N; i++)
    {
        lenzz.push_back(trees[i] - trees[i - 1]);
    }

    int minn = 1000000000;
    if(lenzz.size() == 1)
    {
        minn = *(lenzz.begin());
    }
    else
    {
        for (auto it = next(lenzz.begin()); it != lenzz.end(); it++)
        {
            if(minn == 1000000000)
                minn = gcd(*(it), *(next(it, -1)));
            else
                minn = gcd(minn, *(it));
        }
    }

    int count = 0;
    for (auto it = lenzz.begin(); it != lenzz.end(); it++)
    {
        count += (*it / minn) - 1;
    }
    cout << count;

    return 0;
}