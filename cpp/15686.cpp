#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool ch[13] = {false};
int minn = 10000001;

void recur(int idx, int depth)
{
    ch[idx] = true;

    if(depth == M)
    {
        int temp = 0;
        for (size_t i = 0; i < house.size(); i++)
        {
            int path = 10000001;
            for (size_t j = 0; j < chicken.size(); j++)
            {
                if(ch[j])
                {
                    path = min(abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second), path);
                }
            }

            temp += path;
            if(temp >= minn)
                break;
        }

        minn = min(minn, temp);
    }
    else
    {
        for (size_t i = idx+1; i < chicken.size(); i++)
        {
            recur(i, depth+1);
        }
    }

    ch[idx] = false;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            switch(temp)
            {
                case 1:
                {
                    house.push_back(make_pair(i, j));
                    break;
                }
                case 2:
                {
                    chicken.push_back(make_pair(i, j));
                    break;
                }
            }
        }
    }
    
    for (size_t i = 0; i <= (chicken.size() - M); i++)
    {
        recur(i, 1);
    }

    cout << minn;

    return 0;
}