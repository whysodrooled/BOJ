#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int x, n;
    cin >> x >> n;

    unsigned int a, b;
    for(unsigned int i = 0; i < n; i++)
    {
        cin >> a >> b;
        x -= a*b;
    }

    if(x == 0) cout << "Yes";
    else cout << "No";
    
    return 0;
}