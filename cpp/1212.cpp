#include <bits/stdc++.h>

using namespace std;

unsigned long long int temp;
unsigned long long int numm = 0;
bool displayy = false;
string input;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> input;
    if(input[0] == '0')
    {
        cout << 0;
        return 0;
    }

    int sizz = input.size();

    for(int i = 0; i < sizz; i++)
    {
        temp = input[i] - '0';
        for(int i = 4; i > 0; i/=2)
        {
            if(displayy || temp & i)
            {
                displayy = true;
                cout << ((temp & i) != 0);
            }
        }
    }
    
    return 0;
}