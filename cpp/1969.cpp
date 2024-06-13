#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<string, int>> dna;
vector<pair<char, int>> comp;
string input;
char result[51];
int res2 = 0;
char temp;

bool compare(pair<char, int> a, pair<char, int> b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

bool findfunc(pair< char, int > p)
{
    return p.first == temp;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> input;
        dna.push_back(make_pair(input, 0));
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp = dna[j].first[i];
            auto it = find_if(comp.begin(), comp.end(), findfunc);
            if(it != comp.end())
            {
                (*it).second++;
            }
            else
            {
                comp.push_back(make_pair(temp, 1));
            }
        }

        sort(comp.begin(), comp.end(), compare);

        result[i] = comp[0].first;
        for(int j = 1; j < comp.size(); j++)
        {
            res2 += comp[j].second;
        }
        comp.clear();
    }

    result[m] = 0;

    cout << result << '\n' << res2;
    
    return 0;
}