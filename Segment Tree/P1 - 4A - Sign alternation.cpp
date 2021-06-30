#include <cstdio>
#include <vector>

class Segment_Tree
{
private:
    int n;
    std::vector<int> st;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    int build(int p, int l, int r, int arr[])
    {
        return st[p] = l == r ? arr[l] : build(lf(p), l, (l + r) >> 1, arr) + build(rg(p), ((l + r) >> 1) + 1, r, arr);
    }

    int update(int p, int l, int r, int idx, int new_val)
    {
        if (idx < l || idx > r)
            return st[p];
        return st[p] = l == r ? new_val : update(lf(p), l, (l + r) >> 1, idx, new_val) + update(rg(p), ((l + r) >> 1) + 1, r, idx, new_val);
    }

    int query(int p, int L, int R, int l, int r)
    {
        if (r < L || l > R)
            return 0;
        if (L >= l && R <= r)
            return st[p];
        return query(lf(p), L, (L + R) >> 1, l, r) + query(rg(p), ((L + R) >> 1) + 1, R, l, r);
    }

public:
    Segment_Tree(int arr[], int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
        //st = new int[n << 2];
        build(1, 0, n - 1, arr);
    }
    void update(int idx, int new_val)
    {
        update(1, 0, n - 1, idx, new_val);
    }

    int query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int index = 0; index < n; ++index)
    {
        scanf("%d", &arr[index]);
        if (index & 1)
            arr[index] *= -1;
    }

    Segment_Tree st(arr, n);

    int type, m, l, r;

    scanf("%d", &m);

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type)
            printf("%d\n", st.query(--l, --r) * (l & 1 ? -1 : 1));
        else
            st.update(l - 1, r * ((l - 1) & 1 ? -1 : 1));
    }

    return 0;
}