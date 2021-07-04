#include <cstdio>
#include <vector>

using namespace std;

const int EMPTY = (int)1e9 + 5;
int n, h;
vector<int> st, lazy;

void apply(int p, int val)
{
    st[p] = val;
    if (p < n)
        lazy[p] = val;
}

void update(int p)
{
    while (p > 1)
    {
        p >>= 1;
        st[p] = lazy[p] != EMPTY ? lazy[p] : min(st[p << 1], st[p << 1 | 1]);
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

void modify(int l, int r, int val)
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

int query(int l, int r)
{
    int result = EMPTY;
    l += n, r += n;
    push(l), push(r - 1);
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            result = min(result, st[l++]);
        if (r & 1)
            result = min(result, st[--r]);
    }
    return result;
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);

    st.assign(n << 1, 0);
    lazy.assign(n, EMPTY);

    h = 32 - __builtin_clz(n);

    int type, l, r, val;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            scanf("%d", &val), modify(l, r, val);
        else
            printf("%d\n", query(l, r));
    }

    return 0;
}