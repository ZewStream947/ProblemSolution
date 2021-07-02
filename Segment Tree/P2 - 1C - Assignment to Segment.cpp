#include <cstdio>
#include <vector>

class Segment_Tree
{
private:
    int n;
    std::vector<int> st;
    const int EMPTY = 1e9 + 1;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    void push(int p)
    {
        if (st[p] != EMPTY)
        {
            st[lf(p)] = st[rg(p)] = st[p];
            st[p] = EMPTY;
        }
    }

    void modify(int p, int L, int R, int l, int r, int val)
    {
        if (r < L || l > R)
            return;
        if (L != R)
            push(p);
        if (L >= l && R <= r)
        {
            st[p] = val;
            return;
        }
        modify(lf(p), L, (L + R) >> 1, l, r, val);
        modify(rg(p), ((L + R) >> 1) + 1, R, l, r, val);
    }

    int query(int p, int l, int r, int idx)
    {
        if (l == r)
            return st[p];
        push(p);
        int mid = (l + r) >> 1;
        if (idx <= mid)
            return query(lf(p), l, mid, idx);
        return query(rg(p), mid + 1, r, idx);
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
    }

    void modify(int l, int r, int val) { modify(1, 0, n - 1, l, r, val); }
    int query(int idx) { return query(1, 0, n - 1, idx); }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Segment_Tree st(n);

    int type, l, r, val;

    while (m--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d %d", &l, &r, &val);
            st.modify(l, --r, val);
        }
        else
            scanf("%d", &l),
                printf("%d\n", st.query(l));
    }

    return 0;
}