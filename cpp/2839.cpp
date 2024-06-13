/*
5a + 3b = input 을 만족하는 경우만 구한다.
*/

#include <iostream>
using namespace std;

int main()
{
    int a;
    scanf("%d", &a);

    int temp = a;
    int count = 0;

    if(a % 5 == 0)
    {
        count = a / 5;
    }
    else
    {
        while(true)
        {
            temp -= 3;
            count++;
            if(temp % 5 == 0)
            {
                count += temp / 5;
                break;
            }
            else if(temp < 0)
            {
                count = -1;
                break;
            }
        }
    }

    printf("%d", count);
}