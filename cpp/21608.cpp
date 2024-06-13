#include <bits/stdc++.h>

using namespace std;

int n;
int pown;
int student;
vector<pair<int, array<int, 4>>> s;
int seat[21][21];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    pown = pow(2, n);

    for(int i = 0; i < pown; i++)
    {
        array<int, 4> fav;
        
        cin >> student >> fav[0] >> fav[1] >> fav[2] >> fav[3];
        s.push_back(make_pair(student, fav));
    }

    seat[1][1] = student;
    
    return 0;
}