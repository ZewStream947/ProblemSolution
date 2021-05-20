#include <cstdio>

int main()
{
    int w, h, l, cnt = 1, TC;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d %d", &w, &h, &l);
        printf("Case %d: ", cnt++);
        if (w <= 20 && h <= 20 && l <= 20)
            printf("good\n");
        else
            printf("bad\n");
    }

    return 0;
}