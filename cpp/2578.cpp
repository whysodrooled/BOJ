#include <bits/stdc++.h>

using namespace std;

int bingo[25];
int temp;
int calc;
bool indicate;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 25; i++)
    {
        cin >> bingo[i];
    }

    for(int i = 0; i < 25; i++)
    {
        calc = 0;
        
        cin >> temp;
        for(int j = 0; j < 25; j++)
        {
            if(temp == bingo[j])
            {
                bingo[j] = 0;
                break;
            }
        }

        if(!bingo[0] && !bingo[6] && !bingo[12] && !bingo[18] && !bingo[24])
        {
            calc++;
        }
        if(!bingo[4] && !bingo[8] && !bingo[12] && !bingo[16] && !bingo[20])
        {
            calc++;
        }

        for(int j = 0; j < 5; j++)
        {
            if(!bingo[j] && !bingo[j+5] && !bingo[j+10] && !bingo[j+15] && !bingo[j+20])
            {
                calc++;
            }
            if(!bingo[j*5] && !bingo[j*5+1] && !bingo[j*5+2] && !bingo[j*5+3] && !bingo[j*5+4])
            {
                calc++;
            }
        }

        if(calc >= 3)
        {
            cout << i+1;
            break;
        }
    }
    
    return 0;
}