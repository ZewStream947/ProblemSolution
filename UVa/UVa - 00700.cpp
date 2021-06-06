#include <cstdio>

using namespace std;

int main()
{

    int n, a, b, maxYear, mYIndex, index, cnt = 1;
    int diff[20], y[20];

    while (scanf("%d", &n), n)
    {
        for (maxYear = -1, index = 0, mYIndex = -1; index < n; ++index)
        {
            scanf("%d %d %d", y + index, &a, &b);
            diff[index] = b - a;
            if (y[index] > maxYear)
            {
                maxYear = y[index];
                mYIndex = index;
            }
        }
        for (; maxYear < 10000; maxYear += diff[mYIndex])
        {
            for (index = 0; index < n; ++index)
                if (index != mYIndex && (maxYear - y[index]) % diff[index])
                    break;
            if (index == n)
                break;
        }
        printf("Case #%d:\n", cnt++);
        if (maxYear < 10000)
            printf("The actual year is %d.\n\n", maxYear);
        else
            printf("Unknown bugs detected.\n\n");
    }

    return 0;
}