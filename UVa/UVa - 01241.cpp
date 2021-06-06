#include <cstdio>
#include <bitset>

using namespace std;

int main()
{
    int TC, n, m, lim, pos;
    scanf("%d", &TC);
    bitset<2 << 10> ctt;
    while (TC--)
    {
        ctt.set();

        int result = 0;

        scanf("%d %d", &n, &m);

        for (int index = 0; index < m; ++index)
            scanf("%d", &pos), ctt[pos - 1] = 0;

        while (n)
        {
            int setIndex = 0, index = 0, lim = 2 << n;
            while (index < lim)
            {
                result += ctt[index] ^ ctt[index + 1];
                ctt[setIndex++] = ctt[index] | ctt[index + 1];
                index += 2;
            }
            --n;
        }

        printf("%d\n", result);
    }

    return 0;
}