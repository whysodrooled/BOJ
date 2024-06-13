#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using std::cin;
using std::cout;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N;
    int A[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    std::sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;

        cout << std::binary_search(A, A+N, n) << "\n";
    }

    return 0;
}