#include <iostream>

using namespace std;

int t;
int n;
int price[1000000];
long long int money;
long long int maxx;
int stock;
int temp;
bool dir;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> t;

    for(int a = 0; a < t; a++)
    {
        cin >> n;
        
        for(int i = 0; i < n; i++)
        {
            cin >> price[i];
        }

        money = 0;
        maxx = 0;
        stock = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(price[i] > maxx)
            {
                money += stock * maxx;
                stock = 0;
                
                maxx = price[i];
            }
            else
            {
                money -= price[i];
                stock++;
            }
        }

        if(stock > 0)
        {
            money += stock * maxx;
        }

        cout << money << '\n';
    }
    
    return 0;
}