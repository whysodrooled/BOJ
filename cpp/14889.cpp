#include <bits/stdc++.h>

using namespace std;

int S[20][20], N;
int available[20][20] = {0};
int record[10];
int minn = 40001;

void recur(int idx, int depth)
{
    record[depth - 1] = idx;

    for (size_t i = 0; i < N; i++)
    {
        available[i][idx] += 1;
    }
    for (size_t i = 0; i < N; i++)
    {
        available[idx][i] += 1;
    }
    
    if (depth == (N / 2))
    {
        int temp = 0;
        int temp2 = 0;
        for (size_t i = 0; i < depth; i++)
        {
            for (size_t j = i+1; j < depth; j++)
            {
                temp += S[record[i]][record[j]];
                temp += S[record[j]][record[i]];
            }
        }
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if(available[i][j] == 0)
                {
                    temp2 += S[i][j];
                }
            }
        }

        minn = min(minn,
                    abs(temp - temp2));

        for (size_t i = 0; i < N; i++)
        {
            available[i][idx] -= 1;
        }
        for (size_t i = 0; i < N; i++)
        {
            available[idx][i] -= 1;
        }

        return;
    }

    for (size_t i = idx+1; i < N; i++)
    {
        recur(i, depth+1);
    }

    for (size_t i = 0; i < N; i++)
    {
        available[i][idx] -= 1;
    }
    for (size_t i = 0; i < N; i++)
    {
        available[idx][i] -= 1;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> S[i][j];
        }
    }

    for (size_t i = 0; i < (N/2); i++)
    {
        recur(i, 1);
    }

    cout << minn;

    return 0;
}