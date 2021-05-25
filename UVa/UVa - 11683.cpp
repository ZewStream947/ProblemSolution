#include <cstdio>

int main()
{
    int h, w, x, prev, result;

    while (scanf("%d", &h), h)
    {
        scanf("%d %d", &w, &x);
        result = prev = h - x;
        while (--w)
        {
            scanf("%d", &x);
            if (h - x > prev)
                result += h - x - prev;
            prev = h - x;
        }

        printf("%d\n", result);
    }

    return 0;
}