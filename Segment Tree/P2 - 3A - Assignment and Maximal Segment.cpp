#include <cstdio>
#include <vector>

using namespace std;

const int INF = __INT_MAX__;

class Segment_Tree
{
private:
    struct Node
    {
        long long seg = 0, pref = 0, suf = 0, sum = 0;
        int lz = INF;
        Node operator+(const Node &other)
        {
            Node tmp;
            tmp.seg = max(max(seg, other.seg), suf + other.pref);
            tmp.sum = sum + other.sum;
            tmp.pref = max(pref, sum + other.pref);
            tmp.suf = max(other.suf, suf + other.sum);
            return tmp;
        }
    };

    int n;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    vector<Node> st;

    void apply(int p, int val, int k)
    {
        st[p].sum = (long long)val * k;
        st[p].seg = st[p].pref = st[p].suf = (long long)((long long)max(0, val)) * k;
        st[p].lz = val;
    }

    void push(int p, int l, int r)
    {
        if (st[p].lz != INF)
        {
            int mid = (l + r) >> 1;
            apply(lf(p), st[p].lz, mid - l + 1);
            apply(rg(p), st[p].lz, r - mid);
            st[p].lz = INF;
        }
    }

    void update(int p, int L, int R, int l, int r, int val)
    {
        if (r < L || l > R)
            return;
        if (L != R)
            push(p, L, R);
        if (L >= l && R <= r)
            return apply(p, val, R - L + 1);
        update(lf(p), L, (L + R) >> 1, l, r, val);
        update(rg(p), ((L + R) >> 1) + 1, R, l, r, val);
        st[p] = st[lf(p)] + st[rg(p)];
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st.resize(n << 2);
    }

    void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }
    long long query() { return max(0LL, st[1].seg); }
};

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    Segment_Tree st(n);

    int l, r, val;

    while (m--)
    {
        scanf("%d %d %d", &l, &r, &val);
        st.update(l, --r, val);
        printf("%lli\n", st.query());
    }
    return 0;
}