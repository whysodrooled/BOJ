#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int N, K;
int change = 0;
int A[10001];

int partition(int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r-1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            change++;
        }

        if(change >= K)
            return -1;
    }
    
    if((i+1) != r)
    {
        int temp = A[i+1];
        A[i+1] = A[r];
        A[r] = temp;
        change++;
    }

    return i + 1;
}

void quick_sort(int p, int r)
{
    if(p<r)
    {
        int q = partition(p, r);
        if(q == -1)
            return;
        quick_sort(p, q - 1);
        quick_sort(q + 1, r);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    quick_sort(0, N-1);
    if(change < K)
    {
        cout << -1;
    }
    else
    {
        for (size_t i = 0; i < N; i++)
        {
            cout << A[i] << ' ';
        }
    }

    return 0;
}