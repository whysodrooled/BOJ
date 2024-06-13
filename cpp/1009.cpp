#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int a, b;
    int temp;
    int* result = new int[t];
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;
        a %= 10;
        temp = a;
        for(int j = 0; j < b-1; j++)
        {
            temp *= a;
            temp %= 10;
        }

        result[i] = temp == 0 ? 10 : temp;
    }

    for(int i = 0; i < t; i++)
    {
        cout << result[i] << "\n";
    }
}