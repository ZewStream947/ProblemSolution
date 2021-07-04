#include <cstdio>
#include <vector>

#define vl first
#define len second

using namespace std;

const int EMPTY = (int)1e9 + 1;
int n, h;
vector<pair<long long, int>> st;
vector<int> lazy;

void apply(int p, long long val)
{
    st[p].vl = (long long)st[p].len * val;
    if (p < n)
        lazy[p] = val;
}

void update(int p)
{
    while (p > 1)
    {
        p >>= 1;
        st[p].vl = lazy[p] != EMPTY ? (long long)st[p].len * lazy[p] : st[p << 1].vl + st[p << 1 | 1].vl;
    }
}

void push(int p)
{
    for (int lv = h, idx; lv; --lv)
    {
        idx = p >> lv;
        if (lazy[idx] != EMPTY)
        {
            apply(idx << 1, lazy[idx]);
            apply(idx << 1 | 1, lazy[idx]);
            lazy[idx] = EMPTY;
        }
    }
}

void modify(int l, int r, long long val)
{
    int l0 = l += n, r0 = r += n;
    push(l0), push(r0 - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            apply(l++, val);
        if (r & 1)
            apply(--r, val);
    }

    update(l0), update(--r0);
}

long long query(int l, int r)
{
    long long result = 0;
    l += n, r += n;
    push(l), push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            result += st[l++].vl;
        if (r & 1)
            result += st[--r].vl;
    }
    return result;
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    st.assign(n << 1, make_pair(0, 1));
    lazy.assign(n, EMPTY);

    for (int index = n - 1; index; --index)
        st[index].len = st[index << 1].len + st[index << 1 | 1].len;
    h = 32 - __builtin_clz(n);

    int type, l, r, val;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            scanf("%d", &val), modify(l, r, (long long)val);
        else
            printf("%lli\n", query(l, r));
    }

    return 0;
}