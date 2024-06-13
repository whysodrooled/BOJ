#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int* arr2 = new int[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    sort(arr, arr+n);
    sort(arr2, arr2+n, compare); // :(

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result += arr[i] * arr2[i];
    }

    cout << result;

    return 0;
}