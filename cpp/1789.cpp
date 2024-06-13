#include <iostream>

using namespace std;

int main()
{
    long long s;
    cin >> s;

    int i = 0;
    while(s > 0)
    {
        i++;
        s -= i;
    }
    if(s < 0) i--;
    cout << i;

    return 0;
}