#include <bits/stdc++.h>

using namespace std;

int fibs[41][2] = {{0, 0}};
int T, N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    fibs[0][0] = 1;
    fibs[1][1] = 1;

    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        for (int i = 2; i <= N; i++)
        {
            fibs[i][0] = fibs[i-2][0] + fibs[i-1][0];
            fibs[i][1] = fibs[i-2][1] + fibs[i-1][1];
        }

        cout << fibs[N][0] << ' ' << fibs[N][1] << '\n';
    }
    

    return 0;
}