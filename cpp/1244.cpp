#include <bits/stdc++.h>

using namespace std;

bool lights[101];
int n;
int students;
int cmd;
int student;

int main()
{
    /*cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);*/

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> lights[i];
    }

    cin >> students;
    while(students > 0)
    {
        cin >> student >> cmd;
        if(student == 1)
        {
            for(int i = cmd; i-1 < n; i+=cmd)
            {
                lights[i-1] = !lights[i-1];
            }
        }
        else
        {
            cmd--;
            lights[cmd] = !lights[cmd];
            
            for(int i = 1; i < n/2; i++)
            {
                if((cmd+i >= n || cmd-i < 0)
                || lights[cmd+i] != lights[cmd-i])
                    break;
                
                lights[cmd+i] = !lights[cmd+i];
                lights[cmd-i] = !lights[cmd-i];
            }
        }
        
        students--;
    }

    for(int i = 0; i < n; i++)
    {
        if(i % 20 == 19) cout << lights[i] << '\n';
        else cout << lights[i] << ' ';
    }
    
    return 0;
}