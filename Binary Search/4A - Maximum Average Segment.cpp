#include <cstdio>

#define MAXN int(1e5) + 1

int arr[MAXN], min[MAXN], n, d, resL, resR;
double sum[MAXN];

int main()
{
    scanf("%d %d", &n, &d);

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;
    double mid, l = 0, r = 100;

    while (r - l > 0.00000001)
    {
        mid = (l + r) / 2;
        bool isOk = 0;
        for (int index = 1; index <= n; ++index)
        {
            sum[index] = (double)arr[index - 1] + sum[index - 1] - mid;
            min[index] = (sum[min[index - 1]] > sum[index] ? index : min[index - 1]);
            if (index - d >= 0)
                if (sum[min[index - d]] <= sum[index])
                {
                    isOk = 1;
                    resL = min[index - d] + 1;
                    resR = index;
                    break;
                }
        }
        isOk ? l = mid : r = mid;
    }

    printf("%d %d", resL, resR);
    return 0;
}