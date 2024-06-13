#include <bits/stdc++.h>

using namespace std;

int sudoku[9][9];
bool freeze = false;

void recur(int x, int y)
{
    if(freeze)
        return;

    while (x < 9)
    {
        if(y < 9 && sudoku[x][y] == 0)
            break;

        if(y >= 9)
        {
            x++;
            y = 0;
        }
        else
        {
            y++;
        }
    }

    if(x >= 9)
    {
        freeze = true;
        return;
    }

    bool available[9];
    fill(available, available + 9, true);

    for (size_t i = 0; i < 9; i++)
    {
        if(sudoku[x][i] != 0)
            available[sudoku[x][i]-1] = false;
        if(sudoku[i][y] != 0)
            available[sudoku[i][y]-1] = false;
    }
    for (size_t i = (x/3) * 3; i < ((x/3) * 3 + 3); i++)
    {
        for (size_t j = (y/3) * 3; j < ((y/3) * 3 + 3); j++)
        {
            if(sudoku[i][j] != 0)
                available[sudoku[i][j]-1] = false;
        }
    }
    
    for (int i = 0; i < 9; i++)
    {
        if(available[i])
        {
            sudoku[x][y] = i + 1;
            recur(x, y+1);
            if(freeze)
                break;
            
            sudoku[x][y] = 0;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    recur(0, 0);
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}