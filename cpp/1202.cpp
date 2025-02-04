// https://kimjingo.tistory.com/121
// https://www.acmicpc.net/board/view/147286
// jewel and bags dont need pq it seems

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int jewelSort(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int N, K;
pair<int, int> jewels[300000];
priority_queue<int, vector<int>, less<int>> curprice;
int bags[300000];
ll result = 0;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    int lol, lol2;
    for (size_t i = 0; i < N; i++)
    {
        cin >> jewels[i].first >> jewels[i].second;
    }
    for (size_t i = 0; i < K; i++)
    {
        cin >> bags[i];
    }

    sort(bags, bags + K);
    sort(jewels, jewels + N, jewelSort);

    size_t j = 0;
    for (size_t i = 0; i < K; i++)
    {
        while(j < N && jewels[j].first <= bags[i])
        {
            curprice.push(jewels[j].second);
            j++;
        }

        if(!curprice.empty())
        {
            result += curprice.top();
            curprice.pop();
        }
    }
    

    cout << result;

    return 0;
}