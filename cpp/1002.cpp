// https://www.acmicpc.net/board/view/142108
// https://mathbang.net/101#gsc.tab=0

#include <bits/stdc++.h>

using namespace std;

int T;
long long Jx, Jy, Bx, By;
int Jl, Bl;

int main()
{
    int T;
    cin >> T;

    for (size_t _ = 0; _ < T; _++)
    {
        cin >> Jx >> Jy >> Jl >> Bx >> By >> Bl;

        double d = pow(pow(Jx-Bx, 2) + pow(Jy-By, 2), 0.5);

        if((Jl + Bl) == d || abs(Jl - Bl) == d)
            cout << 1;
        else if(abs(Jl - Bl) < d && d < (Jl + Bl))
            cout << 2;
        else if(d == 0 && Jl == Bl)
            cout << -1;
        else
            cout << 0;

        cout << '\n';
    }
    
    
    return 0;
}