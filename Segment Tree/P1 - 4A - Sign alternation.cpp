#include <cstdio>

int *st, n, s;

void build()
{
    for (int index = n - 1; index; --index)
        st[index] = st[index << 1] + st[index << 1 | 1];
}

void modify(int idx, int new_val)
{
    for (st[idx += n] = new_val; idx > 1; idx >>= 1)
        st[idx >> 1] = st[idx] + st[idx ^ 1];
}

int sum(int l, int r) //sum query on [l, r]
{
    for (s = 0, l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            s += st[l++];
        if (!(r & 1))
            s += st[r--];
    }
    return s;
}

int main()
{
    scanf("%d", &n);

    st = new int[n << 1];

    for (int index = 0; index < n; ++index)
    {
        scanf("%d", st + n + index);
        if (index & 1)
            st[index + n] *= -1;
    }

    build();
    int m;
    scanf("%d", &m);
    int type, a, b;
    while (m--)
    {
        scanf("%d %d %d", &type, &a, &b);
        if (type)
            printf("%d\n", sum(--a, --b) * (a & 1 ? -1 : 1));
        else
            modify(a - 1, b * ((a - 1) & 1 ? -1 : 1));
    }

    return 0;
}
