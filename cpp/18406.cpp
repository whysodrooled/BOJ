#include <bits/stdc++.h>

using namespace std;

string n;
int num1 = 0;
int num2 = 0;

int main()
{
    cin >> n;
    int len = n.length();

    for(int i = 0; i < len / 2; i++)
    {
        num1 += n[i] - '0';
    }

    for(int i = len / 2; i < len; i++)
    {
        num2 += n[i] - '0';
    }

    if(num1 == num2)
        cout << "LUCKY";
    else
        cout << "READY";
    
    return 0;
}