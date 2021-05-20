#include <cstdio>

int main()
{
    int TC;
    scanf("%d", &TC);

    while (TC--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a < b)
            printf("<");
        else if (a > b)
            printf(">");
        else
            printf("=");
        printf("\n");
    }

    return 0;
}
