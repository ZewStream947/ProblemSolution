#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Segment_Tree
{
private:
    int n;
    vector<int> st;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    int update(int p, int l, int r, int idx)
    {
        if (idx < l || idx > r)
            return st[p];
        return st[p] = l == r ? 1 : update(lf(p), l, (l + r) >> 1, idx) + update(rg(p), ((l + r) >> 1) + 1, r, idx);
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
    Segment_Tree(int n)
    {
        this->n = n;
        st.assign(n << 2, 0);
    }

    void update(int idx)
    {
        update(1, 0, n - 1, idx);
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

    unordered_map<int, int> visited;

    Segment_Tree st(n << 1);

    int res[n + 1] = {0};

    for (int index = 0, seg; index < n << 1; ++index)
    {
        scanf("%d", &seg);
        if (visited.count(seg))
        {
            res[seg] = (index - visited[seg] - 1) - (st.query(visited[seg], index) << 1);
            st.update(visited[seg]);
        }
        else
            visited[seg] = index;
    }

    for (int index = 1; index <= n; printf("%d ", res[index++]))
        ;
    return 0;
}