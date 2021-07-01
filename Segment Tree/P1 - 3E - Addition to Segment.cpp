#include <cstdio>
#include <vector>

class Segment_Tree
{
private:
    int n;
    std::vector<long long> st;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    long long update(int p, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return st[p];
        if (l == r)
            return st[p] += (long long)val;
        return st[p] = update(lf(p), l, (l + r) >> 1, idx, val) + update(rg(p), ((l + r) >> 1) + 1, r, idx, val);
    }

    long long sum(int p, int L, int R, int l, int r)
    {
        if (r < L || l > R)
            return 0;
        if (L >= l && R <= r)
            return st[p];
        return sum(lf(p), L, (L + R) >> 1, l, r) + sum(rg(p), ((L + R) >> 1) + 1, R, l, r);
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
    }

    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    long long query(int idx) { return sum(1, 0, n - 1, 0, idx); }
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
            st.update(l, val);
            st.update(r, -val);
        }
        else
        {
            scanf("%d", &val);
            printf("%lli\n", st.query(val));
        }
    }

    return 0;
}
