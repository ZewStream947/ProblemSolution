#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b, h, w, minCost, eachCost, bedAvail;

    while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        minCost = INT_MAX;

        while (h--)
        {
            scanf("%d", &eachCost);
            for (long i = 0; i < w; ++i)
            {
                scanf("%d", &bedAvail);
                if (bedAvail >= n)
                    minCost = min(minCost, eachCost * n);
            }
        }

        if (minCost <= b)
            printf("%d\n", minCost);
        else
            printf("stay home\n");
    }
    return 0;
}