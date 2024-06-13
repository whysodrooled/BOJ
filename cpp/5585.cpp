#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int money;
    cin >> money;
    money = 1000 - money;

    int temp;
    int result = 0;

    temp = money / 500;
    if(temp > 0)
    {
        money -= 500 * temp;
        result += temp;
    }

    temp = money / 100;
    if(temp > 0)
    {
        money -= 100 * temp;
        result += temp;
    }

    temp = money / 50;
    if(temp > 0)
    {
        money -= 50 * temp;
        result += temp;
    }

    temp = money / 10;
    if(temp > 0)
    {
        money -= 10 * temp;
        result += temp;
    }

    temp = money / 5;
    if(temp > 0)
    {
        money -= 5 * temp;
        result += temp;
    }

    result += money;

    cout << result;
    
    return 0;
}