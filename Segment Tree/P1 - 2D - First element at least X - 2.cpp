#include <cstdio>
#include <vector>

using namespace std;

class Segment_Tree
{
private:
    int n;
    vector<int> st;

    int lf(int par)
    {
        return par << 1;
    }

    int rg(int par)
    {
        return par << 1 | 1;
    }

    int build(int par, int l, int r, int arr[])
    {
        return st[par] = (l == r ? arr[l] : max(build(lf(par), l, (l + r) >> 1, arr), build(rg(par), ((l + r) >> 1) + 1, r, arr)));
    }

    int update(int par, int l, int r, int idx, int new_val)
    {
        if (idx < l || idx > r)
            return st[par];
        return st[par] = (l == r ? new_val : max(update(lf(par), l, (l + r) >> 1, idx, new_val), update(rg(par), ((l + r) >> 1) + 1, r, idx, new_val)));
    }

    int query(int par, int l, int r, int target, int minIdx)
    {
        if (l == r)
            return st[par] >= target ? l : -1;
        int lft = lf(par), rgt = rg(par);
        int idx = -1;
        if (st[lft] >= target && minIdx <= (l + r) >> 1)
            idx = query(lft, l, (l + r) >> 1, target, minIdx);
        if (idx == -1 && st[rgt] >= target)
            idx = query(rgt, ((l + r) >> 1) + 1, r, target, minIdx);
        return idx;
    }

public:
    Segment_Tree(int arr[], int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
        build(1, 0, n - 1, arr);
    }

    void update(int idx, int new_val)
    {
        update(1, 0, n - 1, idx, new_val);
    }

    int query(int target, int minIdx)
    {
        return query(1, 0, n - 1, target, minIdx);
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

    for (int type, idx, val; m; --m)
    {
        scanf("%d", &type);
        scanf("%d %d", &idx, &val);
        if (type == 1)
            st.update(idx, val);
        else
            printf("%d\n", st.query(idx, val));
    }

    return 0;
}