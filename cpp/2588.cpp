#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int temp = b;
    do
    {
        cout << a * (temp % 10) << "\n";
        temp /= 10;
    } while (temp > 0);

    cout << a * b << "\n";
    
    return 0;
}