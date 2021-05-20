#include <cstdio>

using namespace std;

int main()
{

    short int n, x, cnta, cntb, cnt = 1;
    while (scanf("%d", &n), n)
    {
        cnta = cntb = 0;
        while (n--)
        {
            scanf("%d", &x);
            if (x == 0)
                ++cntb;
            else
                ++cnta;
        }
        printf("Case %d: %d\n", cnt++, cnta - cntb);
    }

    return 0;
}