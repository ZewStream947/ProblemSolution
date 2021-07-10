#include <cstdio>
#include <vector>

class Segment_Tree
{
private:
    int n;
    std::vector<int> st;
    std::vector<bool> lz;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    void apply(int p, int k)
    {
        st[p] = k - st[p];
        lz[p] = !lz[p];
    }

    void push(int p, int l, int r)
    {
        if (lz[p])
        {
            int mid = (l + r) >> 1;
            apply(lf(p), mid - l + 1);
            apply(rg(p), r - mid);
            lz[p] = 0;
        }
    }

    void reverse(int p, int L, int R, int l, int r)
    {
        if (L != R)
            push(p, L, R);
        if (r < L || l > R)
            return;
        if (L >= l && R <= r)
            return apply(p, R - L + 1);

        reverse(lf(p), L, (L + R) >> 1, l, r);
        reverse(rg(p), ((L + R) >> 1) + 1, R, l, r);
        st[p] = st[lf(p)] + st[rg(p)];
    }

    int query(int p, int l, int r, int k)
    {
        if (l != r)
            push(p, l, r);
        if (l == r)
            return l;
        int lft = lf(p);
        if (k < st[lft])
            return query(lft, l, (l + r) >> 1, k);
        return query(lft | 1, ((l + r) >> 1) + 1, r, k - st[lft]);
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
        lz.assign(n << 2, 0);
    }

    void reverse(int l, int r) { reverse(1, 0, n - 1, l, r); }
    int query(int k) { return query(1, 0, n - 1, k); }
};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Segment_Tree st(n);

    int type, l, r;

    while (m--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d", &l, &r);
            st.reverse(l, --r);
        }
        else
        {
            scanf("%d", &l);
            printf("%d\n", st.query(l));
        }
    }

    return 0;
}