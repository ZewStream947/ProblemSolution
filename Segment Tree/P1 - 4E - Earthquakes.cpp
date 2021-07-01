#include <cstdio>
#include <vector>

using namespace std;

class Segment_Tree
{
private:
    int n;
    vector<int> mn;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    void update(int p, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;
        if (l == r)
        {
            mn[p] = val;
            return;
        }
        int lft = lf(p);
        update(lft, l, (l + r) >> 1, idx, val);
        update(lft | 1, ((l + r) >> 1) + 1, r, idx, val);
        mn[p] = min(mn[lft], mn[lft | 1]);
    }

    void query(int p, int L, int R, int l, int r, int power, int &cnt)
    {
        if (r < L || l > R || mn[p] > power)
            return;
        if (L == R)
        {
            mn[p] = 1e9 + 1;
            ++cnt;
            return;
        }
        int lft = lf(p);
        query(lft, L, (L + R) >> 1, l, r, power, cnt);
        query(lft | 1, ((L + R) >> 1) + 1, R, l, r, power, cnt);
        mn[p] = min(mn[lft], mn[lft | 1]);
    }

public:
    Segment_Tree(int n)
    {
        this->n = n;
        mn.assign(n << 2, 1e9 + 1);
    }

    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    int query(int l, int r, int power)
    {
        int cnt = 0;
        query(1, 0, n - 1, l, r, power, cnt);
        return cnt;
    }
};

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    Segment_Tree st(n);

    int type, a, b, power;
    while (m--)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d", &a, &power);
            st.update(a, power);
        }
        else
        {
            scanf("%d %d %d", &a, &b, &power);
            printf("%d\n", st.query(a, --b, power));
        }
    }

    return 0;
}