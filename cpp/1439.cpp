#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    char temp = input[0];
    int temp2 = 0;
    int size = input.size();

    for(int i = 1; i < size; i++)
    {
        if(input[i] != temp)
        {
            temp2++;
            temp = input[i];
        }
    }

    if(temp2 % 2 == 1)
    {
        temp2 = (temp2+1) / 2;
    }
    else
    {
        temp2 /= 2;
    }

    cout << temp2;
    
    return 0;
}