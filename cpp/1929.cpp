#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using std::cin;
using std::cout;

bool primes[1000001] = {false};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    for (size_t i = 2; i <= n; i++)
    {
        if (!primes[i])
        {
            if(i >= m)
                cout << i << '\n';

            for (size_t j = i; j <= n; j += i)
            {
                primes[j] = true;
            }
        }
    }

    return 0;
}