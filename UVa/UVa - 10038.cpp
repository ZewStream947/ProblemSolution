#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int index, n, prev, curr;
    int arr[3000];

    while (scanf("%d", &n) == 1)
    {
        bool check[n] = {0};
        bool isJolly = 0;
        scanf("%d", &prev);
        for (index = 1; index < n; ++index)
        {
            scanf("%d", &curr);
            if (abs(curr - prev) < n)
                check[abs(curr - prev)] = 1;
            prev = curr;
        }
        for (index = 1; index < n; ++index)
            if (!check[index])
                break;
        if (index == n)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}