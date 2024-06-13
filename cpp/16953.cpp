#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int a, b;
    cin >> a >> b;

    if((b % 10) % 2 != 0 && (b % 10) != 1)
    {
        cout << "-1";
        return 0;
    }

    int result = 0;
    do
    {
        if(b % 10 == 1)
        {
            b /= 10;
            result++;
        }
        else if(b % 2 == 0)
        {
            b /= 2;
            result++;
        }
        else
        {
            cout << "-1";
            return 0;
        }
    } while(b > a);

    if(b == a)
    {
        cout << result+1;
    }
    else
    {
        cout << "-1";
    }
    
    return 0;
}