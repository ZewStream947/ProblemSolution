#include <cstdio>
#include <algorithm>

using namespace std;

int upper_bound(int l, int r, int x, int arr[])
{
    int mid;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        arr[mid] >= x ? r = mid : l = mid;
    }

    return r;
}

int lower_bound(int l, int r, int x, int arr[])
{
    int mid;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        arr[mid] > x ? r = mid : l = mid;
    }
    return l;
}

int main()
{
    int n, queries;

    scanf("%d", &n);

    int arr[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    sort(arr, arr + n);

    scanf("%d", &queries);

    for (int l, r; queries; --queries)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", lower_bound(-1, n, r, arr) - upper_bound(-1, n, l, arr) + 1);
    }

    return 0;
}