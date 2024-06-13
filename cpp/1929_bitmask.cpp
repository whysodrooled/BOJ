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

char primes[125001] = {0};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    for (size_t i = 2; i <= n; i++)
    {
        if ((primes[i/8] & (1 << (i%8))) != (1 << (i%8)))
        {
            if(i >= m)
                cout << i << '\n';

            for (size_t j = i*2; j <= n; j += i)
            {
                primes[j / 8] |= (1 << (j % 8));
            }
        }
    }

    return 0;
}