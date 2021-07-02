#include <cstdio>

#define max(a, b) (a > b ? a : b)

int n;
long long st[(int)2e5 + 1];

void modify(int l, int r, long long val)
{
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            st[l] = max(st[l], val);
            ++l;
        }
        if (!(r & 1))
        {
            st[r] = max(st[r], val);
            --r;
        }
    }
}

int query(int idx)
{
    int res = 0;
    for (idx += n; idx; idx >>= 1)
        res = max(res, st[idx]);
    return res;
}

int main()
{
    int m;

    scanf("%d %d", &n, &m);

    int type, l, r, val;
    while (m--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d %d", &l, &r, &val);
            modify(l, --r, val);
        }
        else
            scanf("%d", &l), printf("%d\n", query(l));
    }

    return 0;
}