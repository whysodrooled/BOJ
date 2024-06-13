#include <bits/stdc++.h>

using namespace std;

stack<int> st;
queue<char> res;
int N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int n;
    int loc = 1;
    for (size_t i = 0; i < N; i++)
    {
        cin >> n;

        for (; loc <= n; loc++)
        {
            st.push(loc);
            res.push('+');
        }
        while(!st.empty() && n == st.top())
        {
            st.pop();
            res.push('-');
        }
    }

    if(st.empty())
    {
        while(!res.empty())
        {
            cout << res.front() << '\n';
            res.pop();
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}