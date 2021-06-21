#include <cstdio>

int main()
{
    int n, queries;
    scanf("%d %d", &n, &queries);

    int arr[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    for (int x, l, r, mid; queries; --queries)
    {
        scanf("%d", &x);
        l = -1, r = n;
        while (l + 1 < r)
        {
            mid = (l + r) >> 1;
            if (arr[mid] < x)
                l = mid;
            else
                r = mid;
        }
        printf("%d\n", r + 1);
    }
}
