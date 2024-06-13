#include <bits/stdc++.h>
using namespace std;

int n;
int temp;
vector<int> tree;
int result;
int topindex = 0;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        tree.push_back(temp);
    }

    sort(tree.begin(), tree.end(), compare);
    
    for(int i = 0; i < n; i++)
    {
        tree[i] += (i + 1);
    }

    sort(tree.begin(), tree.end(), compare);

    cout << tree[0] + 1;

    return 0;
}