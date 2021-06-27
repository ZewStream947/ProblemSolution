#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
struct item
{
    ll seg, pref, suf, sum;
};

class Segment_Tree
{
private:
    int n;
    vector<item> st;

    int lf(int par)
    {
        return par << 1;
    }

    int rg(int par)
    {
        return par << 1 | 1;
    }

    item build(int arr[], int par, int l, int r)
    {
        if (l == r)
            return st[par] = {arr[l], arr[l], arr[l], arr[l]};

        item lft = build(arr, lf(par), l, (l + r) >> 1);
        item rgt = build(arr, rg(par), ((l + r) >> 1) + 1, r);
        return st[par] = {max(max(lft.seg, rgt.seg), lft.suf + rgt.pref), max(lft.pref, lft.sum + rgt.pref), max(rgt.suf, rgt.sum + lft.suf), lft.sum + rgt.sum};
    }

    item update(int par, int l, int r, int index, int new_val)
    {
        if (index < l || index > r)
            return st[par];
        if (l == r)
            return st[par] = {new_val, new_val, new_val, new_val};

        item lft = update(lf(par), l, (l + r) >> 1, index, new_val);
        item rgt = update(rg(par), ((l + r) >> 1) + 1, r, index, new_val);
        return st[par] = {max(max(lft.seg, rgt.seg), lft.suf + rgt.pref), max(lft.pref, lft.sum + rgt.pref), max(rgt.suf, rgt.sum + lft.suf), lft.sum + rgt.sum};
    }

public:
    Segment_Tree(int arr[], int n)
    {
        this->n = n;
        st.assign(n << 2, {0, 0, 0, 0});
        build(arr, 1, 0, n - 1);
    }

    void update(int index, int new_val)
    {
        update(1, 0, n - 1, index, new_val);
    }

    ll query()
    {
        return max(st[1].seg, 0LL);
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

    printf("%lli\n", st.query());
    int index, val;
    while (m--)
    {
        scanf("%d %d", &index, &val);
        st.update(index, val);
        printf("%lli\n", st.query());
    }

    return 0;
}