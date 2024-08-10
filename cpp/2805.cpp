// thanks geeaeecode

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M;
int tree[1000001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int start = 0;
    int end = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> tree[i];
        end = max(end, tree[i]);
    }

    int loc;
    while (start <= end)
    {
        ll temp = 0;
        int mid = (end + start) / 2;

        for (size_t i = 0; i < N; i++)
        {
            if(tree[i] > mid)
            {
                temp += tree[i] - mid;
            }
        }

        if(temp < M)
        {
            end = mid - 1;
        }
        else
        {
            loc = mid;
            start = mid + 1;
        }
    }
    

    cout << loc;

    return 0;
}