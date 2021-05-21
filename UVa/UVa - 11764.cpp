#include <cstdio>

using namespace std;

int main()
{
    int TC, cnt = 1;

    scanf("%d", &TC);

    int n, prevH, h, hTotal, lTotal;

    while (TC--)
    {
        hTotal = lTotal = 0;
        scanf("%d %d", &n, &prevH);
        --n;
        while (n--)
        {
            scanf("%d", &h);
            if (h > prevH)
                ++hTotal;
            else if (h < prevH)
                ++lTotal;
            prevH = h;
        }

        printf("Case %d: %d %d\n", cnt++, hTotal, lTotal);
    }

    return 0;
}