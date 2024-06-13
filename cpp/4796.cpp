#include <iostream>

using namespace std;

int main()
{
    unsigned int count = 1;
    int result;
    int l, p, v;

    while(true)
    {
        cin >> l >> p >> v;
        if(l <= 0) break;

        result = l * (v/p);

        if(l > (v%p))
            result += (v%p);
        else
            result += l;

        cout << "Case " << count << ": " << result << '\n';
        count++;
    }

    return 0;
}