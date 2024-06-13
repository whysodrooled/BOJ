#include <bits/stdc++.h>

using namespace std;

char mines[101];
char temp;
int around;
int n;
bool fucked = false;
char output[101];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n*n; i++)
    {
        cin >> mines[i];
    }

    for(int i = 0; i < n*n; i += n)
    {
        for(int j = i; j < i+n; j++)
        {
            cin >> temp;

            if(temp != 'x')
            {
                output[j] = '.';
                continue;
            }
            
            around = 0;
            for(int k = j-n; k < j+n+1; k+=n)
            {
                if(k >= n*n) continue;
                
                if(j-i > 0 && k-1 >= 0 && mines[k-1] == '*')
                {
                    around++;
                }
                if(mines[k] == '*')
                {
                    if(k == j) fucked = true;
                    else around++;
                }
                if(j-i < n-1 && mines[k+1] == '*')
                {
                    around++;
                }
            }

            output[j] = around + '0';
        }
    }

    for(int i = 0; i < n*n; i++)
    {
        if(fucked && mines[i] == '*')
        {
            cout << '*';
        }
        else
        {
            cout << output[i];
        }
        if(i % n == n-1) cout << '\n';
    }
    
    return 0;
}