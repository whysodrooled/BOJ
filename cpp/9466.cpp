// https://www.acmicpc.net/board/view/143387 ;)

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int T, N;
int students[100001];
bool traversed[100001];
bool solo[100001];
int avail;

void check(int st)
{
    deque<int> q;
    q.push_back(st);
    int curAv = 0;

    while(!q.empty())
    {
        if(traversed[q.back()])
        {
            while(q.back() != q.front())
            {
                q.pop_front();
            }
            avail -= q.size()-1;
            
            break;
        }

        traversed[q.back()] = true;

        q.push_back(students[q.back()]);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T > 0)
    {
        cin >> N;
        for (size_t i = 0; i < N; i++)
        {
            cin >> students[i];
            students[i]--;
            traversed[i] = false;
            solo[i] = false;
        }

        avail = N;

        for (size_t i = 0; i < N; i++)
        {
            if(traversed[i]) continue;

            check(i);
        }

        cout << avail << '\n';

        T--;
    }

    return 0;
}