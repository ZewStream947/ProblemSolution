#include <cstdio>

using namespace std;

int main()
{

    int TC;
    scanf("%d", &TC);

    while (TC--)
    {
        int n, m;

        scanf("%d %d", &n, &m);

        int result = (n / 3) * (m / 3);
        printf("%d\n", result);
    }

    return 0;
}