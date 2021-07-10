#include <cstdio>
#include <vector>

using namespace std;

class Segment_Tree
{
private:
    int n;
    vector<int> st, lz;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    void apply(int p, int val)
    {
        st[p] += val;
        lz[p] += val;
    }

    void push(int p)
    {
        if (lz[p])
        {
            apply(lf(p), lz[p]);
            apply(rg(p), lz[p]);
            lz[p] = 0;
        }
    }

    void add(int p, int L, int R, int l, int r, int val)
    {
        if (r < L || l > R)
            return;
        if (L != R)
            push(p);
        if (L >= l && R <= r)
            return apply(p, val);
        add(lf(p), L, (L + R) >> 1, l, r, val);
        add(rg(p), ((L + R) >> 1) + 1, R, l, r, val);
        st[p] = max(st[lf(p)], st[rg(p)]);
    }

    int query(int p, int l, int r, int x, int L)
    {
        if (l == r)
            return l;
        push(p);
        int mid = (l + r) >> 1;
        int res = -1;
        int lft = lf(p);
        if (L <= mid && st[lft] >= x)
            res = query(lft, l, mid, x, L);
        if (res == -1 && st[lft | 1] >= x)
            res = query(lft | 1, mid + 1, r, x, L);
        return res;
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
        lz.assign(n << 2, 0);
    }

    void add(int l, int r, int val) { add(1, 0, n - 1, l, r, val); }
    int query(int x, int l)
    {
        int res = query(1, 0, n - 1, x, l);
        return res;
    }
};

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    Segment_Tree st(n);

    int type, a, b, val;

    while (m--)
    {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1)
        {
            scanf("%d", &val);
            st.add(a, --b, val);
        }
        else
            printf("%d\n", st.query(a, b));
    }

    return 0;
}