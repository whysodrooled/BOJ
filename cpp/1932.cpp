#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int pyramid[125001];
int N;
queue<int> numz;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    int n;
    cin >> n;
    numz.push(n);
    int count = 0;

    for (size_t i = 2; i <= N; i++)
    {
        cin >> n;
        int og = numz.front();
        numz.pop();
        numz.push(og + n);

        for (size_t j = 0; j < i-2; j++)
        {
            cin >> n;
            int cool = og + n;

            og = numz.front();
            numz.pop();
            cool = max(cool, og + n);
            numz.push(cool);
        }

        cin >> n;
        numz.push(og + n);
    }

    int res = 0;
    while (!numz.empty())
    {
        res = max(res, numz.front());
        numz.pop();
    }

    cout << res;

    return 0;
}