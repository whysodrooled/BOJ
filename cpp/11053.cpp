/*
5
30 10 20 30 40

8
1 10 11 12 2 3 4 5
*/

// https://velog.io/@min-ji99/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4LIS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int A[1001];
int result[1001];
int lol = 1;
int N;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        result[i] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        int temp = result[i];
        
        for (int j = i-1; j >= 0; j--)
        {
            if(A[j] < A[i])
            {
                result[i] = max(result[i], temp + result[j]);
                lol = max(result[i], lol);
            }
        }
    }

    cout << lol;

    return 0;
}