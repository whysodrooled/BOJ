#include <iostream>

using namespace std;

int n, m;
int x = 0, y = 0;
int result1 = 0;
int result2 = 0;
int state = 0;

int main()
{
    cin >> n >> m;

    state = 0;
    while(x < m-4 && y < n)
    {
        switch(state)
        {
            case 0:
            {
                y += 2;
                x++;
                
                break;
            }
            case 1:
            {
                y -= 1;
                x++;
                
                break;
            }
            case 2:
            {
                x += 2;
                y++;
                
                break;
            }
            case 3:
            {
                x += 1;
                y--;

                break;
            }
        }

        result1++;

        state++;
        if(state >= 4) state = 0;
    }

    cout << result1;
    
    return 0;
}