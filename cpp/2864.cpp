#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int min = 0, max = 0;
    int div = 1;

    while(a > 0 || b > 0)
    {
        if(a % 10 == 6 || b % 10 == 6)
        {
            if(a % 10 == b % 10)
            {
                min += (a % 10 + b % 10 - 2) * div;
                max += (a % 10 + b % 10) * div;
            }
            else if(a % 10 == 5 || b % 10 == 5)
            {
                min += (a % 10 + b % 10 - 1) * div;
                max += (a % 10 + b % 10 + 1) * div;
            }
            else
            {
                min += (a % 10 + b % 10 - 1) * div;
                max += (a % 10 + b % 10) * div;
            }
        }
        else if (a % 10 == 5 || b % 10 == 5)
        {
            if(a % 10 == b % 10)
            {
                min += (a % 10 + b % 10) * div;
                max += (a % 10 + b % 10 + 2) * div;
            }
            else
            {
                min += (a % 10 + b % 10) * div;
                max += (a % 10 + b % 10 + 1) * div;
            }
        }
        else
        {
            min += (a % 10 + b % 10) * div;
            max += (a % 10 + b % 10) * div;
        }

        a /= 10;
        b /= 10;
        div *= 10;
    }

    cout << min << ' ' << max;
    
    return 0;
}