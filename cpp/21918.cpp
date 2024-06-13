#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b, c;
bool light[4001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> light[i];
    }

    while(m > 0)
    {
        cin >> a >> b >> c;
        switch(a)
        {
            case 1:
            {
                light[b] = c;
                
                break;
            }
            case 2:
            {
                for(int i = b; i <= c; i++)
                {
                    light[i] = !light[i];
                }
                
                break;
            }
            case 3:
            {
                for(int i = b; i <= c; i++)
                {
                    light[i] = false;
                }
                
                break;
            }
            default:
            {
                for(int i = b; i <= c; i++)
                {
                    light[i] = true;
                }
            }
        }
        
        m--;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << light[i] << ' ';
    }
    
    return 0;
}