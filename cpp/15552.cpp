#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int a, b;
    while(n > 0)
    {
        cin >> a >> b;
        cout << a+b << '\n';

        n--;
    }
    
    return 0;
}