#include <bits/stdc++.h>

using namespace std;

bool avail[4000001];
vector<int> primes;
int res = 0;
int N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    fill(avail, avail + 4000001, true);

    cin >> N;

    for (size_t i = 2; i <= N; i++)
    {
        if(!avail[i])
            continue;

        primes.push_back(i);
        for (size_t j = i*2; j <= N; j += i)
        {
            avail[j] = false;
        }
    }

    int temp = 0;
    int bacc = 0;
    for (size_t i = 0; i < primes.size(); i++)
    {
        temp += primes[i];
        while(temp > N)
        {
            temp -= primes[bacc];
            bacc++;
        }
        if(temp == N)
        {
            res++;
        }
    }

    cout << res;

    return 0;
}