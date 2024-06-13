#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using std::cin;
using std::cout;

std::string dna;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int s, p;
    cin >> s >> p >> dna;
    int def_stats[4], stats[4] = {0};
    cin >> def_stats[0] >> def_stats[1] >> def_stats[2] >> def_stats[3];

    int result = 0;
    for (size_t i = 0; i < dna.size(); i++)
    {
        int idx;
        switch(dna[i])
        {
            case 'A':
            {
                idx = 0;
                break;
            }
            case 'C':
            {
                idx = 1;
                break;
            }
            case 'G':
            {
                idx = 2;
                break;
            }
            case 'T':
            {
                idx = 3;
                break;
            }
        }

        stats[idx]++;

        if(i >= (p-1))
        {
            bool pass = true;
            for (size_t j = 0; j < 4; j++)
            {
                if (stats[j] < def_stats[j])
                {
                    pass = false;
                    break;
                }
            }
            
            if(pass)
                result++;

            switch(dna[i-p+1])
            {
                case 'A':
                {
                    idx = 0;
                    break;
                }
                case 'C':
                {
                    idx = 1;
                    break;
                }
                case 'G':
                {
                    idx = 2;
                    break;
                }
                case 'T':
                {
                    idx = 3;
                    break;
                }
            }
            stats[idx]--;
        }
    }

    cout << result;

    return 0;
}