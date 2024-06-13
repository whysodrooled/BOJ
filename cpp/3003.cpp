#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[6];
    
    for(int i = 0; i < 6; i++)
    {
        cin >> arr[i];

        switch(i)
        {
            case 0: case 1:
            {
                arr[i] = 1 - arr[i];
                break;
            }
            case 5:
            {
                arr[i] = 8 - arr[i];
                break;
            }
            default:
            {
                arr[i] = 2 - arr[i];
            }
        }
    }

    for(int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }
    
    return 0;
}