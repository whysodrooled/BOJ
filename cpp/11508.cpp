#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    int c[100000];

    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c, c+n);

    unsigned int result = 0;
    int skip = n/3;
    int skip2 = n % 3;
    if(skip2 == 1)
    {
        result += c[0];
    }
    else if(skip2 == 2)
    {
        result += c[0];
        result += c[1];
    }
    for(int i = skip2; i < n; i++)
    {
        if((i - skip2) % 3 == 0 && skip > 0)
        {
            skip--;
            continue;
        }

        result += c[i];
    }

    cout << result;
    
    return 0;
}