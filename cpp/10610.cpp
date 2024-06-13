#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    string str;
    cin >> str;

    int size = str.size();
    int temp = 0;
    int* n = new int[str.size()];
    for(int i = 0; i < size; i++)
    {
        n[i] = str[i] - '0';
        temp += str[i];
    }

    if(find(n, n+size, 0) == n+size)
    {
        cout << "-1";
        return 0;
    }

    sort(n, n+size, compare);

    if(temp % 3 == 0)
    {
        for(int i = 0; i < size; i++)
        {
            cout << n[i];
        }
    }
    else
    {
        cout << "-1";
    }
    
    return 0;
}