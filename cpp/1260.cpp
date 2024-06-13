#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

map<int, priority_queue<int, vector<int>, greater<int>>> paths;
int N, M, V;
deque<int> history;
bool traversed[1001] = {false};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> V;

    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        auto it = paths.find(a);
        if(it != paths.end())
        {
            (*it).second.push(b);
        }
        else
        {
            priority_queue<int, vector<int>, greater<int>> newnew;
            newnew.push(b);
            paths.insert(make_pair(a, newnew));
        }

        it = paths.find(b);
        if(it != paths.end())
        {
            (*it).second.push(a);
        }
        else
        {
            priority_queue<int, vector<int>, greater<int>> newnew;
            newnew.push(a);
            paths.insert(make_pair(b, newnew));
        }
    }

    history.push_back(V);
    while(!history.empty())
    {
        if(traversed[history.back()])
        {
            history.pop_back();
            continue;
        }
        
        cout << history.back() << ' ';
        traversed[history.back()] = true;
        auto locs = paths.find(history.back());
        auto locz = (*locs).second;
        vector<int> fuck;
        while (!locz.empty())
        {
            fuck.push_back(locz.top());
            locz.pop();
        }
        history.pop_back();
        for (auto it = fuck.rbegin(); it != fuck.rend(); it++)
        {
            history.push_back(*it);
        }
    }

    cout << '\n';

    fill(traversed, traversed + 1001, false);

    history.push_back(V);
    while(!history.empty())
    {
        if(traversed[history.front()])
        {
            history.pop_front();
            continue;
        }

        traversed[history.front()] = true;
        auto locs = paths.find(history.front());
        auto locz = (*locs).second;
        while (!locz.empty())
        {
            history.push_back(locz.top());
            locz.pop();
        }

        cout << history.front() << ' ';
        history.pop_front();
    }

    return 0;
}