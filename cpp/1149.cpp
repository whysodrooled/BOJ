#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int res = 0;
int N;
int rgb[1001][3] = {0};
int modez[1001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> rgb[0][0] >> rgb[0][1] >> rgb[0][2];

    for (size_t i = 1; i < N; i++)
    {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
        for (size_t j = 0; j < 3; j++)
        {
            switch(j)
            {
                case 0:
                {
                    rgb[i][0] = min(
                        rgb[i][0] + rgb[i - 1][1],
                        rgb[i][0] + rgb[i - 1][2]);

                    break;
                }
                case 1:
                {
                    rgb[i][1] = min(
                        rgb[i][1] + rgb[i - 1][0],
                        rgb[i][1] + rgb[i - 1][2]);
                    
                    break;
                }
                case 2:
                {
                    rgb[i][2] = min(
                        rgb[i][2] + rgb[i - 1][0],
                        rgb[i][2] + rgb[i - 1][1]);
                    
                    break;
                }
            }
        }
    }
    
    cout << min({rgb[N-1][0], rgb[N-1][1], rgb[N-1][2]});

    return 0;
}