#include <cstdio>

class Segment_Tree
{
private:
    int n, *st;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    int build(int p, int l, int r)
    {
        return st[p] = l == r ? 1 : build(lf(p), l, (l + r) >> 1) + build(rg(p), ((l + r) >> 1) + 1, r);
    }

    int query(int p, int l, int r, int idx)
    {
        if (l == r)
            return l;
        int rgt = rg(p);
        return idx < st[rgt] ? query(rgt, ((l + r) >> 1) + 1, r, idx) : query(lf(p), l, (l + r) >> 1, idx - st[rgt]);
    }

    int update(int p, int l, int r, int idx)
    {
        if (idx < l || idx > r)
            return st[p];
        return st[p] = l == r ? 0 : update(lf(p), l, (l + r) >> 1, idx) + update(rg(p), ((l + r) >> 1) + 1, r, idx);
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st = new int[n << 2];
        build(1, 0, n - 1);
    }

    int query(int idx) { return query(1, 0, n - 1, idx); }
    void update(int idx) { update(1, 0, n - 1, idx); }
};
int main()
{
    int n;
    scanf("%d", &n);

    Segment_Tree st(n);

    int arr[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    for (int index = n - 1; index >= 0; --index)
        arr[index] = st.query(arr[index]),
        st.update(arr[index]);
    for (int index = 0; index < n; printf("%d ", arr[index++] + 1))
        ;
    return 0;
}