#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

class disjoint_set_union
{
private:
    vi p, rank;

    int get_root(int val)
    {
        return (p[val] == val ? val : p[val] = get_root(p[val]));
    }

public:
    disjoint_set_union(int n)
    {
        rank.assign(n, 0);
        p.assign(n, 0);
        for (int val = 0; val < n; ++val)
            p[val] = val;
    }

    bool is_same_set(int a, int b)
    {
        return get_root(a - 1) == get_root(b - 1);
    }

    void unite(int a, int b)
    {
        int root_a = get_root(a - 1), root_b = get_root(b - 1);
        if (root_a != root_b)
            if (rank[root_a] > rank[root_b])
                p[root_b] = root_a;
            else
            {
                p[root_a] = root_b;
                if (rank[root_a] == rank[root_b])
                    ++rank[root_b];
            }
    }
};

int main()
{
    int size, queries;

    scanf("%d %d", &size, &queries);
    disjoint_set_union union_set(size);

    char query[6];
    int l, r;

    while (queries--)
    {
        scanf("%s %d %d", &query, &l, &r);
        if (strcmp(query, "union") == 0)
            union_set.unite(l, r);
        else
            union_set.is_same_set(l, r) ? puts("YES") : puts("NO");
    }

    return 0;
}