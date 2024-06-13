#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    long long int work[10000];

    for(int i = 0; i < n; i++)
    {
        cin >> work[i];
    }

    sort(work, work+n);

    long long int max = 0;
    if(n % 2 == 1)
    {
        for(int i = 0; i < n/2; i++)
        {
            if(max < (work[i] + work[n-i-2]))
                max = (work[i] + work[n-i-2]);
        }

        if(max < (work[n-1]))
                max = (work[n-1]);
    }
    else
    {
        for(int i = 0; i < n/2; i++)
        {
            if(max < (work[i] + work[n-i-1]))
                max = (work[i] + work[n-i-1]);
        }
    }
    
    cout << max;
    
    return 0;
}