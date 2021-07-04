#include <cstdio>
#include <vector>

#define mp(a, b) make_pair((long long)a, (int)b)
#define val first
#define len second

using namespace std;

int n, h;
vector<pair<long long, int>> st;
vector<long long> lazy;

void apply(int p, long long value)
{
    st[p].val += (long long)st[p].len * value;
    if (p < n)
        lazy[p] += value;
}

void update(int p)
{
    while (p > 1)
        p >>= 1, st[p].val = st[p << 1].val + st[p << 1 | 1].val + lazy[p] * (long long)st[p].len;
}

void modify(int l, int r, long long value)
{
    int l0 = l += n, r0 = r += n;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            apply(l++, value);
        if (r & 1)
            apply(--r, value);
    }
    update(l0), update(--r0);
}

void push(int p)
{
    for (int idx, lv = h; lv; --lv)
    {
        idx = p >> lv;
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
    long long sum = 0;
    l += n, r += n;
    push(l), push(r - 1);

    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            sum += st[l++].val;
        if (r & 1)
            sum += st[--r].val;
    }

    return sum;
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    h = (sizeof(int) << 3) - __builtin_clz(n);

    st.assign(n << 1, mp(0, 1));
    lazy.assign(n, 0);

    for (int index = n - 1; index; --index)
        st[index].len = st[index << 1].len + st[index << 1 | 1].len;

    int type, l, r, value;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            scanf("%d", &value), modify(l, r, (long long)value);
        else
            printf("%lli\n", query(l, r));
    }

    return 0;
}