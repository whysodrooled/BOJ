#include <bits/stdc++.h>

using namespace std;

int N;
bool prime[2000001];
vector<int> primes;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (size_t i = 3; i < 2000001; i+=2)
    {
        if(prime[i])
            continue;

        primes.push_back(i);
        for (size_t j = i*2; j < 2000001; j += i)
        {
            prime[j] = true;
        }
    }

    cin >> N;
    while(N > 0)
    {
        size_t a, b;
        cin >> a >> b;
        size_t lol = a + b;
        if(lol >= 4 && lol % 2 == 0)
        {
            cout << "YES" << '\n';
        }
        else
        {
            if(lol <= 3)
            {
                cout << "NO" << '\n';
            }
            else
            {
                lol -= 2;
                if(lol <= 0)
                {
                    cout << "NO" << '\n';
                }
                else
                {
                    if(lol <= 2000000 && !prime[lol])
                    {
                        cout << "YES" << '\n';
                    }
                    else
                    {
                        bool av = true;
                        for (size_t i = 0; i < primes.size(); i++)
                        {
                            if(lol % primes[i] == 0)
                            {
                                av = false;
                                break;
                            }
                        }

                        cout << (av ? "YES" : "NO") << '\n';
                    }
                }
            }
            
        }

        N--;
    }

    return 0;
}