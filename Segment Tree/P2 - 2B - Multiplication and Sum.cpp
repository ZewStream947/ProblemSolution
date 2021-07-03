#include <cstdio>

const long long MOD = 1e9 + 7;

int n, h;
long long *st, *lazy;

long long multiply(long long a, long long b) { return ((a % MOD) * (b % MOD)) % MOD; }

long long plus(long long a, long long b) { return ((a % MOD) + (b % MOD)) % MOD; }

void apply(int p, long long val)
{
    st[p] = multiply(st[p], val);
    if (p < n)
        lazy[p] = multiply(lazy[p], val);
}

void build()
{
    h = (sizeof(int) << 3) - __builtin_clz(n);
    for (int index = 0; index < n; ++index)
        lazy[index] = st[index + n] = 1;

    for (int index = n - 1; index; --index)
        st[index] = st[index << 1] + st[index << 1 | 1];
}

void update(int p)
{
    while (p > 1)
        p >>= 1, st[p] = multiply(plus(st[p << 1], st[p << 1 | 1]), lazy[p]);
}

void modify(int l, int r, int val)
{
    int l0 = l += n, r0 = r += n;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            apply(l++, (long long)val);
        if (r & 1)
            apply(--r, (long long)val);
    }
    update(l0), update(r0 - 1);
}

void push(int p)
{
    for (int idx, level = h; level; --level)
    {
        idx = p >> level;
        if (lazy[idx] > 1)
        {
            apply(idx << 1, lazy[idx]);
            apply(idx << 1 | 1, lazy[idx]);
            lazy[idx] = 1;
        }
    }
}

long long query(int l, int r)
{
    long long sum = 0;
    l += n, r += n;
    push(l), push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            sum = plus(sum, st[l++]);
        if (r & 1)
            sum = plus(sum, st[--r]);
    }

    return sum;
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    st = new long long[n << 1];
    lazy = new long long[n];

    build();
    int type, l, r, val;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            scanf("%d", &val), modify(l, r, val);
        else
            printf("%lli\n", query(l, r));
    }

    return 0;
}