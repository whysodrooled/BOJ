#include <iostream>
using namespace std;

int compare(const void* a, const void* b)
{
    int* num1 = *(int**)a;
    int* num2 = *(int**)b;

    if(num1[1] < num2[1]) return -1;
    if(num1[1] > num2[1]) return 1;
    if(num1[0] < num2[0]) return -1;
    if(num1[0] > num2[0]) return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int** arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[2];
        scanf("%d", &arr[i][0]);
        scanf("%d", &arr[i][1]);
    }

    qsort(arr, n, sizeof(arr[0]), compare);

    /*for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }*/

    int time = 0;
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i][0] >= time)
        {
            time = arr[i][1];
            result++;
            //printf("lol: %d, %d\n", arr[i][0], arr[i][1]);
        }
    }

    printf("%d", result);

    return 0;
}