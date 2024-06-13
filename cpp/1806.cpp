#include <bits/stdc++.h>

using namespace std;

int N, S;
queue<int> q;
size_t temp = 0;
int lenn = 0;
int res = 100001;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> S;

    for (size_t i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        q.push(n);
        temp += n;
        lenn++;

        while(temp >= S)
        {
            res = min(lenn, res);
            
            temp -= q.front();
            q.pop();
            lenn--;
        }
    }

    while(temp >= S)
    {
        res = min(lenn, res);
        
        temp -= q.front();
        q.pop();
        lenn--;
    }

    if(res == 100001)
        cout << 0;
    else
        cout << res;

    return 0;
}