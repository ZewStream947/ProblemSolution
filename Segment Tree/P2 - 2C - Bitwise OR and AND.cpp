#include <cstdio>
#include <vector>

int n, h;
std::vector<long long> st, lazy;

void apply(int p, long long val)
{
    st[p] |= val;
    if (p < n)
        lazy[p] |= val;
}

void update(int p)
{
    while (p > 1)
        p >>= 1, st[p] = (st[p << 1] & st[p << 1 | 1]) | lazy[p];
}

void modify(int l, int r, long long val)
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
        if (lazy[idx])
        {
            apply(idx << 1, lazy[idx]);
            apply(idx << 1 | 1, lazy[idx]);
            lazy[idx] = 0;
        }
    }
}

long long query(int l, int r)
{
    long long sum = __LONG_LONG_MAX__;
    l += n, r += n;
    push(l), push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            sum &= st[l++];
        if (r & 1)
            sum &= st[--r];
    }

    return sum;
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    st.assign(n << 1, 0);
    lazy.assign(n, 0);

    h = (sizeof(int) << 3) - __builtin_clz(n);

    int type, l, r;
    long long val;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            scanf("%lli", &val), modify(l, r, val);
        else
            printf("%lli\n", query(l, r));
    }

    return 0;
}