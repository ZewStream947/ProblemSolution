#include <cstdio>

int main()
{
    int n, queries;

    scanf("%d %d", &n, &queries);

    int arr[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    bool isOk;
    for (int x, l, r, mid; queries; --queries)
    {
        scanf("%d", &x);
        isOk = 0;
        l = 0, r = n - 1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (arr[mid] == x)
            {
                isOk = 1;
                break;
            }
            if (arr[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        printf(isOk ? "YES\n" : "NO\n");
    }

    return 0;
}
