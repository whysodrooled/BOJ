#include <bits/stdc++.h>
using namespace std;

int t;
int j, n;
unsigned int a, b;
priority_queue<unsigned int> box;
int result;

int main()
{
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        result = 0;
        cin >> j >> n;
        for(int j2 = 0; j2 < n; j2++)
        {
            cin >> a >> b;
            box.push(a*b);
        }

        while(box.size() > 0)
        {
            if(j <= 0) break;

            j -= box.top();
            result++;
            box.pop();
        }

        box = priority_queue<unsigned int>();
        cout << result << '\n';
    }
    
    return 0;
}