#include <cstdio>

int arr[101];

int main()
{

    int TC;
    scanf("%d", &TC);
    int n;
    while (TC--)
    {
        scanf("%d", &n);
        for (int val = 1; val <= n; ++val)
            arr[val] = val;
        if (n & 1)
        {
            for (int index = 1; index < n - 1; index += 2)
                std::swap(arr[index], arr[index + 1]);
            std::swap(arr[n], arr[n - 1]);
        }
        else
            for (int index = 1; index < n; index += 2)
                std::swap(arr[index], arr[index + 1]);
        for (int index = 1; index <= n; printf("%d ", arr[index++]))
            ;
        puts("");
    }

    return 0;
}
