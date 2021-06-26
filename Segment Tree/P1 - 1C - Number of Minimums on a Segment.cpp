#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class Segment_Tree
{
private:
    ii INF = make_pair(int(1e9 + 1), 1);
    int n;
    vii st;

    int lf(int par)
    {
        return par << 1;
    }

    int rg(int par)
    {
        return (par << 1) | 1;
    }

    ii build(int par, int l, int r, int arr[])
    {
        if (l == r)
            return st[par] = make_pair(arr[l], 1);
        ii val1 = build(lf(par), l, (l + r) >> 1, arr);
        ii val2 = build(rg(par), ((l + r) >> 1) + 1, r, arr);
        if (val1.first < val2.first)
            return st[par] = val1;
        if (val2.first < val1.first)
            return st[par] = val2;
        return st[par] = make_pair(val1.first, val1.second + val2.second);
    }

    ii update(int par, int l, int r, int idx, int new_val)
    {
        if (idx < l || idx > r)
            return st[par];
        if (l == r)
            return st[par] = make_pair(new_val, 1);
        ii val1 = update(lf(par), l, (l + r) >> 1, idx, new_val);
        ii val2 = update(rg(par), ((l + r) >> 1) + 1, r, idx, new_val);
        if (val1.first < val2.first)
            return st[par] = val1;
        if (val2.first < val1.first)
            return st[par] = val2;
        return st[par] = make_pair(val1.first, val1.second + val2.second);
    }

    ii query(int par, int L, int R, int l, int r)
    {
        if (L > r || R < l)
            return INF;
        if (L >= l && R <= r)
            return st[par];
        ii val1 = query(lf(par), L, (L + R) >> 1, l, r);
        ii val2 = query(rg(par), ((L + R) >> 1) + 1, R, l, r);
        if (val1.first < val2.first)
            return val1;
        if (val2.first < val1.first)
            return val2;
        return make_pair(val1.first, val1.second + val2.second);
    }

public:
    Segment_Tree(int arr[], int n)
    {
        this->n = n;
        st.assign(n << 2, make_pair(0, 0));
        build(1, 0, n - 1, arr);
    }

    void update(int index, int new_val)
    {
        update(1, 0, n - 1, index, new_val);
    }

    ii query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
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

    int type, a, b;
    ii val;
    while (m--)
    {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1)
            st.update(a, b);
        else
        {
            val = st.query(a, --b);
            printf("%d %d\n", val.first, val.second);
        }
    }

    return 0;
}