#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    bool arr[50][50];
    char temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            arr[i][j] = (temp == '1') ? true : false;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> temp;
            arr[i][j] = ((temp == '1') != arr[i][j]);
        }
    }

    if(n < 3 || m < 3)
    {
        bool end = false;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j])
                {
                    end = true;
                    break;
                }
            }
        }

        if(end)
        {
            cout << -1;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(m - j < 3)
            {
                if(arr[i][j])
                {
                    cout << -1;
                    return 0;
                }
            }
            else
            {
                if(arr[i][j])
                {
                    for(int k = 0; k < 3; k++)
                    {
                        for(int l = 0; l < 3; l++)
                        {
                            arr[i+k][j+l] = !arr[i+k][j+l];
                        }
                    }

                    result++;
                }
            }
        }
    }

    cout << result;
    
    return 0;
}