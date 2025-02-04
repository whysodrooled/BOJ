#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq_small;
priority_queue<int, vector<int>, greater<int>> pq_big;
stack<int> st;

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

        if(pq_big.empty() || pq_big.top() <= lol)
        {
            pq_big.push(lol);
        }
        else if(pq_small.empty() || pq_small.top() > lol)
        {
            pq_small.push(lol);
        }

        if(!pq_big.empty() && pq_big.size()-1 > pq_small.size())
        {
            pq_small.push(pq_big.top());
            pq_big.pop();
        }
        else if(!pq_small.empty() && pq_small.size()-1 >= pq_big.size())
        {
            pq_big.push(pq_small.top());
            pq_small.pop();
        }

        cout << pq_big.top() << '\n';
    }

    return 0;
}