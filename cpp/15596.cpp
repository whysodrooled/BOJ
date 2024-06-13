#include <bits/stdc++.h>

using namespace std;

long long sum(vector<int> &a)
{
    long long result = 0;
    int sizz = a.size();
    for(int i = 0; i < sizz; i++)
    {
        result += a[i];
    }

    return result;
}