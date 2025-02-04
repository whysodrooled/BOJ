#include <iostream>

using namespace std;

int N, K;
int divv, restt;

int main()
{
    cin >> N >> K;
    divv = N / K;
    restt = N % K;

    if(restt == 0)
    {
        cout << 1;
    }
    else
    {
        if((divv * (K-1) + restt) > N)
            cout << -1;

        
    }

    return 0;
}