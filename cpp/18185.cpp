#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    cin >> n;

    int* a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = 0;
    for(int i = 0; i < n - 2;)
    {
        if(a[i] > 0 && a[i+1] > 0 && a[i+2] > 0
        && a[i] >= a[i+1])
        {
            result += 7;
            a[i]--;
            a[i+1]--;
            a[i+2]--;
        }
        else i++;
    }
    for(int i = 0; i < n - 1;)
    {
        if(a[i] > 0 && a[i] == a[i+1])
        {
            result += 5 * a[i];
            a[i] = 0;
            a[i+1] = 0;

            i+=2;
        }
        else i++;
    }
    for(int i = 0; i < n - 1;)
    {
        if(a[i] > 0 && a[i+1] > 0)
        {
            result += 5;
            a[i]--;
            a[i+1]--;
        }
        else i++;
    }
    for(int i = 0; i < n;)
    {
        if(a[i] > 0)
        {
            result += 3;
            a[i]--;
        }
        else i++;
    }

    cout << result;
    
    return 0;
}