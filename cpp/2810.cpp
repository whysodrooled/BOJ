#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    int result = 1;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'L') i++;

        result++;
    }

    if(result > n) result = n;

    cout << result;
    
    return 0;
}