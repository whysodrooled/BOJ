#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool sortt(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int N, L, P;
int result = 0;
pair<int, int> stations[10000];
priority_queue<int, vector<int>, less<int>> pq;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> stations[i].first >> stations[i].second;
    }
    cin >> L >> P;

    sort(stations, stations + N, sortt);

    int i = 0;
    while(i < N)
    {
        while(!pq.empty() && stations[i].first > P)
        {
            P += pq.top();
            pq.pop();
            result++;
        }
        if(stations[i].first <= P)
            pq.push(stations[i].second);

        i++;
    }

    while(!pq.empty() && L > P)
    {
        P += pq.top();
        pq.pop();
        result++;
    }

    cout << ((L <= P) ? result : -1);

    return 0;
}