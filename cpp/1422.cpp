// https://www.acmicpc.net/board/view/66583

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct comp
{
    bool operator()(int a, int b)
    {
        // 9 99 998 8 89 898 ...
        // 큰 수를 앞 혹은 뒤에 스팸
        int temp1 = a;
        int temp2 = b;
        ll a1 = 0;
        ll b1 = 0;

        while (temp1 > 0)
        {
            a1 += temp1 % 10;
            temp1 /= 10;
            a1 *= 10;
        }
        a1 /= 10;
        while (temp2 > 0)
        {
            b1 += temp2 % 10;
            temp2 /= 10;
            b1 *= 10;
        }
        b1 /= 10;

        while (a1 > 0 && b1 > 0)
        {
            if((a1 % 10) == (b1 % 10))
            {
                a1 /= 10;
                b1 /= 10;
            }
            else
            {
                return (a1 % 10) < (b1 % 10);
            }
        }

        return a1 > b1;
    }
};

int K, N;
int nums[50];
int tempp = 0;
priority_queue<int, vector<int>, comp> pq;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> K >> N;

    int temp;
    for (size_t i = 0; i < K; i++)
    {
        cin >> temp;
        tempp = max(temp, tempp);
        pq.push(temp);
    }
    for (size_t i = 0; i < (N-K); i++)
    {
        pq.push(tempp);
    }
    while (!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }

    return 0;
}