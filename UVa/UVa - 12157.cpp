#include <cstdio>

using namespace std;

int main()
{
    int TC, cnt = 1, n, val, mile, juice;

    scanf("%d", &TC);

    while (TC--)
    {
        scanf("%d", &n);

        mile = juice = 0;

        while (n--)
        {
            scanf("%d", &val);
            ++val;
            mile += (val / 30 + (val % 30 > 0)) * 10;
            juice += (val / 60 + (val % 60 > 0)) * 15;
        }
        printf("Case %d: ", cnt++);
        if (mile == juice)
            printf("Mile Juice %d\n", mile);
        else if (mile < juice)
            printf("Mile %d\n", mile);
        else
            printf("Juice %d\n", juice);
    }

    return 0;
}