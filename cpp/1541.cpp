#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    bool minus = false;
    int input = 0;
    int temp = 0;

    for(int i = 0; i < str.size(); i++)
    {
        switch(str[i])
        {
            case '-':
            {
                if(minus)
                {
                    input -= temp;
                }
                else
                {
                    minus = true;
                    input += temp;
                }

                temp = 0;
                break;
            }
            case '+':
            {
                if(minus) input -= temp;
                else input += temp;

                temp = 0;
                break;
            }
            default:
            {
                temp *= 10;
                temp += str[i] - '0';
            }
        }
    }

    if(minus) input -= temp;
    else input += temp;

    cout << input;
    
    return 0;
}