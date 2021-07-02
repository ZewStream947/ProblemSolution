#include <cstdio>
#include <vector>

using namespace std;

class Segment_Tree
{
private:
    int n, h;
    vector<long long> st, lazy;

    void apply(int p, long long val)
    {
        st[p] += val;
        if (p < n)
            lazy[p] += val;
    }

    void update(int p)
    {
        while (p > 1)
            p >>= 1, st[p] = min(st[p << 1], st[p << 1 | 1]) + lazy[p];
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

public:
    Segment_Tree(int n)
    {
        this->n = n;
        h = (sizeof(int) << 3) - __builtin_clz(n);
        st.assign(n << 1, 0);
        lazy.assign(n, 0);
    }

    void add(int l, int r, int val)
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

    long long query(int l, int r)
    {
        l += n, r += n;
        push(l), push(r - 1);
        long long result = 1e18 + 1;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                result = min(result, st[l++]);
            if (r & 1)
                result = min(result, st[--r]);
        }
        return result;
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Segment_Tree st(n);

    int type, l, r, val;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
        {

            scanf("%d", &val);
            st.add(l, r, val);
        }
        else
            printf("%lli\n", st.query(l, r));
    }

    return 0;
}