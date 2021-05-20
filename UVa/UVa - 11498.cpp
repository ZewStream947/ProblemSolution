#include <cstdio>

using namespace std;

int main()
{

    int n, x, y, rootX, rootY;

    while (scanf("%d", &n), n)
    {
        scanf("%d %d", &rootX, &rootY);
        while (n--)
        {
            scanf("%d %d", &x, &y);
            x -= rootX;
            y -= rootY;
            if (x == 0 || y == 0)
                printf("divisa\n");
            else if (x > 0)
            {
                if (y > 0)
                    printf("NE\n");
                else
                    printf("SE\n");
            }
            else
            {
                if (y > 0)
                    printf("NO\n");
                else
                    printf("SO\n");
            }
        }
    }

    return 0;
}