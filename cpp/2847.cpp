#include <iostream>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    int lvl[100];

    for(int i = 0; i < n; i++)
    {
        cin >> lvl[i];
    }

    int result = 0;

    for(int i = n-1; i >= 1; i--)
    {
        if(lvl[i] <= lvl[i-1])
        {
            result += lvl[i-1] - lvl[i] + 1;
            lvl[i-1] = lvl[i] - 1;
        }
    }

    cout << result;
    
    return 0;
}