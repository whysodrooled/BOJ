// https://velog.io/@sw801733/C-%EB%B0%B1%EC%A4%80-2579%EB%B2%88-%EA%B3%84%EB%8B%A8-%EC%98%A4%EB%A5%B4%EA%B8%B0
// bottom-up ???

#include <bits/stdc++.h>

using namespace std;

int n;
int stair[300];
int indexx[300] = {0};
int score = 0;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> stair[i];
    }

    indexx[0] = stair[0];
    indexx[1] = stair[0] + stair[1];
    indexx[2] = stair[2] + max(stair[0], stair[1]);

    for(int i = 3; i < n; i++)
    {
        indexx[i] = stair[i] + max(stair[i - 1] + indexx[i - 3], indexx[i - 2]);
    }

    cout << indexx[n-1];

    return 0;
}