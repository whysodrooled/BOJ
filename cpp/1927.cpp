#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int lol;
    for (size_t i = 0; i < N; i++)
    {
        cin >> lol;
        if(lol == 0)
        {
            if(pq.empty())
            {
                cout << 0;
            }
            else
            {
                cout << pq.top();
                pq.pop();
            }

            cout << '\n';
        }
        else
        {
            pq.push(lol);
        }
    }

    return 0;
}