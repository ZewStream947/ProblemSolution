#include <cstdio>
#include <bitset>

#define LIM 1000000

using namespace std;

int main()
{
    bitset<LIM + 1> bit;

    int n, m, l, r, range, rpt;

    while (scanf("%d %d", &n, &m), n || m)
    {
        bit.reset();
        bool IS_CONFLICT = 0;

        while (n--)
        {
            scanf("%d %d", &l, &r);
            if (!IS_CONFLICT)
            {
                for (++l; l <= r; ++l)
                {
                    if (bit.test(l))
                        IS_CONFLICT = 1;
                    bit.set(l);
                }
            }
        }

        while (m--)
        {
            scanf("%d %d %d", &l, &r, &rpt);
            while (!IS_CONFLICT && l <= LIM)
            {
                for (int index = l + 1; index <= r; ++index)
                {
                    if (bit.test(index))
                        IS_CONFLICT = 1;
                    bit.set(index);
                }
                l += rpt;
                r += rpt;
                if (r > LIM)
                    r = LIM;
            }
        }

        IS_CONFLICT ? puts("CONFLICT") : puts("NO CONFLICT");
    }

    return 0;
}