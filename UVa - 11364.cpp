#include <bits/stdc++.h>

using namespace std;

int main()
{

    int TC;

    scanf("%d", &TC);
    int minE, maxE, n, x;
    while (TC--)
    {
        maxE = -1;
        minE = 100;
        scanf("%d", &n);

        while (n--)
            scanf("%d", &x),
                minE = min(x, minE),
                maxE = max(x, maxE);

        printf("%d\n", 2 * (maxE - minE));
    }
    return 0;
}