#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 0;
    while((n % 5) != 0 && n > 0)
    {
        n -= 2;
        result++;
    }

    if(n < 0)
    {
        cout << -1;
    }
    else
    {
        result += n / 5;
        cout << result;
    }
    
    return 0;
}