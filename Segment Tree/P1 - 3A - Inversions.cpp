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

    int query(int par, int L, int R, int l, int r)
    {
        if (r < L || l > R)
            return 0;
        if (L >= l && R <= r)
            return st[par];
        return query(lf(par), L, (L + R) >> 1, l, r) + query(rg(par), ((L + R) >> 1) + 1, R, l, r);
    }

    int update(int par, int l, int r, int idx)
    {
        if (idx < l || idx > r)
            return st[par];
        return st[par] = l == r ? 1 : update(lf(par), l, (l + r) >> 1, idx) + update(rg(par), ((l + r) >> 1) + 1, r, idx);
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
    }
    int query(int l, int r)
    {

        int val = query(1, 0, n - 1, l, r);
        update(1, 0, n - 1, l - 1);
        return val;
    }
};
int main()
{
    int n;

    scanf("%d", &n);

    Segment_Tree st(n);

    for (int val, cnt = n; cnt; --cnt)
    {
        scanf("%d", &val);
        printf("%d ", st.query(val, n - 1));
    }

    return 0;
}