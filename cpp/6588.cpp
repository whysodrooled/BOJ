#include <bits/stdc++.h>

using namespace std;

int N;
bool prime[1000001];
vector<int> primes;
int history = 2;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    fill(prime, prime + 1000001, true);
    for (size_t i = 2; i <= 1000000; i++)
    {
        if(prime[i])
        {
            for (size_t j = i*2; j <= 1000000; j+=i)
            {
                prime[j] = false;
            }

            primes.push_back(i);
        }
    }
    
    while(true)
    {
        cin >> N;
        if(N == 0)
            break;

        int fuck = 0;
        for (size_t i = 0; i < primes.size(); i++)
        {
            if(N <= primes[i])
            {
                break;
            }
            
            if(prime[N - primes[i]])
            {
                fuck = N - primes[i];
                break;
            }
        }

        if(fuck == 0)
        {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
        else
        {
            cout << N << " = " << N-fuck << " + " << fuck << '\n';
        }
        
    }

    return 0;
}