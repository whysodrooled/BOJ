#include <bits/stdc++.h>

using namespace std;


int n, m;
int crane[51];
vector<int> box;
int minute = 0;
int curcrane;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> crane[i];
    }

    sort(crane, crane+n, compare);

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> curcrane;
        box.push_back(curcrane);
    }

    sort(box.begin(), box.end(), compare);

    if(crane[0] < box[0])
    {
        minute = -1;
    }
    else
    {
        while(box.size() > 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(box.size() == 0) break;
                
                for(int j = 0; j < box.size(); j++)
                {
                    if(crane[i] >= box[j])
                    {
                        box.erase(box.begin()+j);
                        break;
                    }
                }
            }

            minute++;
        }
    }

    cout << minute;
    
    return 0;
}