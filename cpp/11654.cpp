#include <bits/stdc++.h>

using namespace std;

int n;
char c;
int result = 0;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        result += c - '0';
    }

    cout << result;

    return 0;
}