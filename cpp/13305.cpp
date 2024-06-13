#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unsigned long long pay = 1000000001;
    unsigned long long* length = new unsigned long long[n-1];
    unsigned long long* charge = new unsigned long long[n];
    unsigned long long total = 0;
    for(int i = 0; i < n-1; i++)
    {
        cin >> length[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> charge[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        if(pay > charge[i])
        {
            pay = charge[i];
        }

        total += length[i] * pay;
    }

    cout << total;

    return 0;
}