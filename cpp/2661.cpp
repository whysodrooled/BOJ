#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
bool stop = false;

void recur(int num, int depth)
{
    if(stop)
        return;

    arr.push_back(num);

    for (size_t i = 1; i < depth; i++)
    {
        int same = 0;

        for (size_t j = 0; j < i; j++)
        {
            if(arr[depth - 1 - j] == arr[depth - 1 - j - i])
            {
                same++;
            }
        }
        
        if(same == i)
        {
            arr.pop_back();
            return;
        }
    }
    
    if(depth == N)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
        }
        stop = true;
    }
    else
    {
        recur(1, depth+1);
        recur(2, depth+1);
        recur(3, depth+1);
    }

    arr.pop_back();
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    recur(1, 1);
    
    return 0;
}