/*
1
3 3
1 2
1 3
2 2
ans = 3

1
6 5
5 6
4 5
3 4
2 3
2 6
ans = 5

1
6 3
3 4
2 5
1 6
ans = 3
*/

// https://excited-hyun.tistory.com/60

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int T, N, M;
int result;
pair<int, int> books[1001];

bool sortt(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (size_t _ = 0; _ < T; _++)
    {
        cin >> N >> M;
        for (size_t i = 0; i < M; i++)
        {
            cin >> books[i].first >> books[i].second;
        }

        result = 0;
        bool occupied[1001] = {false};
        sort(books, books + M, sortt);

        for (size_t i = 0; i < M; i++)
        {
            for (size_t j = books[i].first; j <= books[i].second; j++)
            {
                if(!occupied[j])
                {
                    occupied[j] = true;
                    result++;
                    break;
                }
            }
            
        }

        cout << result << '\n'; // 😡😡😡😡😡😡
    }

    return 0;
}