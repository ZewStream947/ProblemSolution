#include <cstdio>

using namespace std;

int main()
{
    int TC, cnt = 1, n, speed, minSpeed;
    scanf("%d", &TC);
    while (TC--)
    {
        minSpeed = -1;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &speed);
            if (speed > minSpeed)
                minSpeed = speed;
        }
        printf("Case %d: %d\n", cnt++, minSpeed);
    }

    return 0;
}