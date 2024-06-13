#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using std::cin;
using std::cout;

int N, M;
int numN, numM;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    cin >> N;
    int numN[N];
    for (int i = 0; i < N; i++)
    {
        cin >> numN[i];
    }
    std::sort(numN, numN + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;

        auto res = std::equal_range(numN, numN + N, n);

        cout << res.second - res.first << ' ';
    }

    return 0;
}