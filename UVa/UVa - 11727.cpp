#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    short int TC;
    scanf("%d", &TC);
    int arr[3], cnt = 1;
    while (TC--)
    {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr + 3);
        printf("Case %d: %d\n", cnt++, arr[1]);
    }

    return 0;
}