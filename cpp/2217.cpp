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
    cin >> n;

    int result = 10001;
    int temp;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
        if(result > temp) result = temp;
    }

    result *= n;
    sort(arr, arr+n, compare);

    for(int i = 0; i < (n-1); i++)
    {
        temp = arr[i] * (i+1);
        if(temp > result) result = temp;
    }

    cout << result;
}