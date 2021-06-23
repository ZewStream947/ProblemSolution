#include <cstdio>

int *arr, n, k;

bool good(long long sum)
{
    int currSeg = 1, index = 0;
    long long currSum = 0;

    for (; index < n; ++index)
        if (currSum + arr[index] <= sum)
            currSum += arr[index];
        else
        {
            --index;
            if (++currSeg > k)
                break;
            else
                currSum = 0;
        }
    return currSeg <= k && index == n;
}

int main()
{
    scanf("%d %d", &n, &k);

    arr = new int[n];
    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    long long mid, l = 0, r = 1e15;

    while (l + 1 < r)
    {
        mid = l + ((r - l) >> 1);
        good(mid) ? r = mid : l = mid;
    }

    printf("%lld", r);
    return 0;
}