#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, M, T, A, B, K;
map<pair<int, int>, int> counts;
map<pair<int, int>, bool> cellz;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> T;
    cin >> K >> A >> B;
    for (size_t i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (size_t j = 0; j < M; j++)
        {
            if(str[j] == '*')
            {
                cellz.insert(make_pair(make_pair(i, j), true));
            }
        }
    }

    for (size_t _ = 0; _ < T; _++)
    {
        for (auto it = cellz.begin(); it != cellz.end(); it++)
        {
            auto coord = (*it).first;
            int i = coord.first;
            int j = coord.second;

            for (int i2 = -K; i2 <= K; i2++)
            {
                for (int j2 = -K; j2 <= K; j2++)
                {
                    if((i2 == 0 && j2 == 0)
                    || i2+i < 0 || i2+i >= N
                    || j2+j < 0 || j2+j >= M)
                        continue;

                    auto cnt = counts.find(make_pair(i2+i, j2+j));
                    if(cnt != counts.end())
                    {
                        (*cnt).second++;
                    }
                    else
                    {
                        counts.insert(make_pair(make_pair(i2+i, j2+j), 1));
                    }
                }
            }
        }

        for (auto it = cellz.begin(); it != cellz.end();)
        {
            auto current = it++;
            auto coord = (*current).first;
            auto cnt = counts.find(coord);

            if(cnt == counts.end())
            {
                cellz.erase(current);
            }
        }

        for (auto it = counts.begin(); it != counts.end(); it++)
        {
            auto coord = (*it).first;
            int i = coord.first;
            int j = coord.second;

            auto cell = cellz.find(coord);

            bool exist = true;
            if(cell == cellz.end())
                exist = false;

            if((*it).second >= A && (*it).second <= B)
            {
                if((*it).second > A && !exist)
                {
                    cellz.insert(make_pair(make_pair(i, j), true));
                }
            }
            else
            {
                if(exist)
                {
                    cellz.erase(cell);
                }
            }
        }

        counts = map<pair<int, int>, int>();
    }
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            auto it = cellz.find(make_pair(i, j));
            if(it != cellz.end())
            {
                cout << '*';
            }
            else
            {
                cout << '.';
            }
        }

        cout << '\n';
    }
    

    return 0;
}