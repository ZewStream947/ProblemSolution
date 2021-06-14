#include <cstdio>
#include <vector>
#include <set>

using namespace std;

class union_set
{
private:
    vector<int> rank, p;
    set<int> joined;

    int get_par(int x)
    {
        return (x == p[x] ? x : p[x] = get_par(p[x]));
    }

public:
    union_set(int n)
    {
        p.resize(n);
        rank.assign(n, 0);
        for (int index = 0; index < n; ++index)
            p[index] = index, joined.insert(index);
    }

    void unite(int a, int b)
    {
        if ((a = get_par(a)) == (b = get_par(b)))
            return;
        if (rank[a] > rank[b])
            swap(a, b);
        p[a] = b;
        if (rank[a] == rank[b])
            ++rank[b];
    }

    void unite_range(int l, int r)
    {
        set<int>::iterator pos = joined.lower_bound(l);
        while (pos != joined.end() && *pos < r)
        {
            int val = *pos;
            unite(val, val + 1);
            joined.erase(pos);
            pos = joined.lower_bound(val);
        }
    }

    bool is_same(int a, int b)
    {
        return get_par(a) == get_par(b);
    }
};

int main()
{
    int n, queries;
    scanf("%d %d", &n, &queries);

    union_set un(n);

    int query, l, r;

    while (queries--)
    {
        scanf("%d %d %d", &query, &l, &r);
        if (query == 1)
            un.unite(--l, --r);
        else if (query == 2)
            un.unite_range(--l, --r);
        else if (un.is_same(--l, --r))
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}