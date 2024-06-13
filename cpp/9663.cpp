#include <bits/stdc++.h>

using namespace std;

char chess[15][15] = {0};
int N;
int result = 0;

void recur(int y, int x, int count)
{
    if(count == N)
    {
        result++;
        return;
    }

    for (int i = x+1; i < N; i++)
    {
        chess[y][i] += 1;
    }
    for (int i = 1; x+i < N; i++)
    {
        if(y+i < N)
        {
            chess[y+i][x+i] += 1;
        }
        if(y-i >= 0)
        {
            chess[y-i][x+i] += 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if(chess[i][x+1] == 0)
            recur(i, x+1, count + 1);
    }

    for (int i = x+1; i < N; i++)
    {
        chess[y][i] -= 1;
    }
    for (int i = 1; x+i < N; i++)
    {
        if(y+i < N)
        {
            chess[y+i][x+i] -= 1;
        }
        if(y-i >= 0)
        {
            chess[y-i][x+i] -= 1;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        recur(i, 0, 1);
    }

    cout << result;

    return 0;
}