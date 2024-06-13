#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using std::cin;
using std::cout;

int nums[10001] = {0};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums[n] += 1;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < nums[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}