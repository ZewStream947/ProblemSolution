#include <cstdio>

using namespace std;

int main()
{
    int number;
    while (scanf("%d", &number) == 1)
    {
        int result = 0;
        for (int cnt = 0; cnt < 4; ++cnt)
            result = (result << 8) | ((number >> (8 * cnt)) & 255);
        printf("%d converts to %d\n", number, result);
    }

    return 0;
}