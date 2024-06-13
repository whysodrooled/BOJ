#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int streak = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == 'X')
        {
            streak++;
        }
        else
        {
            if(streak % 2 == 1)
            {
                cout << -1;
                return 0;
            }

            streak = 0;
        }
    }

    if(streak % 2 == 1)
    {
        cout << -1;
        return 0;
    }

    size_t loc = 0;

    while(true)
    {
        loc = input.find("XXXX", loc);
        if(loc == string::npos) break;

        input.replace(loc, 4, "AAAA");
    }

    loc = 0;

    while(true)
    {
        loc = input.find("XX", loc);
        if(loc == string::npos) break;

        input.replace(loc, 2, "BB");
    }

    cout << input;
    
    return 0;
}