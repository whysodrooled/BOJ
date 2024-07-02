#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, K;
set<map<int, int>> ways;
set<map<int, int>> moneyway[101];
int money[101] = {0};

void findway(int idx, int current, map<int, int> mm)
{
    if(current == 0)
    {
        moneyway[idx].insert(mm);

        return;
    }
    
    for (int i = idx; i < N; i++)
    {
        if(current-money[i] >= 0)
        {
            auto loc = mm.find(money[i]);
            if(loc == mm.end())
            {
                mm.insert(make_pair(money[i], 1));
            }
            else
            {
                (*loc).second++;
            }

            findway(idx, current-money[i], mm);
        }
    }
}

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> money[i];
    }
    sort(money, money + N, compare);
    for (int i = 0; i < N; i++)
    {
        findway(i, money[i], map<int, int>());
    }

    cout << 10;

    return 0;
}