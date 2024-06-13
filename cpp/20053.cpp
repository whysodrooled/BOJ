#include <bits/stdc++.h>

using namespace std;

int minn;
int maxx;
int n;
int m;
int temp;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    while(n > 0)
    {
        cin >> m;
        cin >> minn;
        maxx = minn;
        for(int i = 1; i < m; i++)
        {
            cin >> temp;
            minn = min(minn, temp);
            maxx = max(maxx, temp);
        }

        cout << minn << ' ' << maxx << '\n';

        n--;
    }
    
    return 0;
}