#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    int count = 0;
    unsigned long long int tip = 0;
    int temp[100000];

    sort(temp, temp+n, compare);

    for(int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    sort(temp, temp+n, compare);

    for(int i = 0; i < n; i++)
    {
        if(temp[i] <= count) break;

        tip += temp[i] - count;
        count++;
    }

    cout << tip;
    
    return 0;
}