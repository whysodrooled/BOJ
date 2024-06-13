// 300a + 60b + 10c = T가 되게 하라.
// 단 a+b+c가 최소가 되야함.

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    if(t % 10 != 0)
    {
        cout << "-1";
        return 0;
    }

    int a, b, c;
    int temp = (t / 300);
    if(temp > 0)
    {
        t -= temp * 300;
        a = temp;
    }
    a = temp;

    temp = t / 60;
    if(temp > 0)
    {
        t -= temp * 60;
    }
    b = temp;

    c = t / 10;

    cout << a << ' ' << b << ' ' << c;

    return 0;
}