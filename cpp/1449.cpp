#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n, l;
    cin >> n >> l;

    int holes[1000];
    for(int i = 0; i < n; i++)
    {
        cin >> holes[i];
    }

    sort(holes, holes+n, compare);
    int temp = holes[0];
    l--;
    int result = 1;

    for(int i = 1; i < n; i++)
    {
        if(temp - holes[i] > l)
        {
            result++;
            temp = holes[i];
        }
    }

    cout << result;
    
    return 0;
}