#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int single = 1000, pack = 1000;
    int temp, temp2;

    for(int i = 0; i < m; i++)
    {
        cin >> temp >> temp2;

        if(temp < pack)
            pack = temp;
        if(temp2 < single)
            single = temp2;
    }
    
    unsigned int result = n * single;

    if(result > (n/6) * pack)
    {
        result = (n/6) * pack;

        if(pack <= (n % 6) * single)
        {
            result += pack;
        }
        else
        {
            result += (n % 6) * single;
        }
    }

    cout << result;

    return 0;
}