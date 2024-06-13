#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int counter = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if((counter == 0 && str[i] == 'U')
        || (counter == 2 && str[i] == 'P'))
        {
            counter++;
        }
        else if(counter % 2 == 1 && str[i] == 'C')
        {
            counter++;
            if(counter == 4)
            {
                cout << "I love UCPC";
                return 0;
            }
        }
    }

    cout << "I hate UCPC";
    
    return 0;
}