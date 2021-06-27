#include <cstdio>
#include <vector>

using namespace std;

class Segment_Tree
{
private:
    vector<int> st;
    int n;

    int lf(int par)
    {
        return par << 1;
    }

    int rg(int par)
    {
        return par << 1 | 1;
    }

    int build(int arr[], int par, int l, int r)
    {
        return st[par] = (l == r ? arr[l] : build(arr, lf(par), l, (l + r) >> 1) + build(arr, rg(par), ((l + r) >> 1) + 1, r));
    }

    int update(int par, int l, int r, int idx)
    {
        if (idx < l || idx > r)
            return st[par];
        return st[par] = (l == r ? st[par] == 0 : update(lf(par), l, (l + r) >> 1, idx) + update(rg(par), ((l + r) >> 1) + 1, r, idx));
    }

    int query(int par, int l, int r, int k)
    {
        if (l == r)
            return l;
        int lft = lf(par), rgt = rg(par);
        return (k < st[lft] ? query(lft, l, (l + r) >> 1, k) : query(rgt, ((l + r) >> 1) + 1, r, k - st[lft]));
    }

public:
    Segment_Tree(int arr[], int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int index)
    {
        update(1, 0, n - 1, index);
    }

    int query(int k)
    {
        return query(1, 0, n - 1, k);
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    Segment_Tree st(arr, n);

    for (int type, val; m; --m)
    {
        scanf("%d %d", &type, &val);
        if (type == 1)
            st.update(val);
        else
            printf("%d\n", st.query(val));
    }

    return 0;
}