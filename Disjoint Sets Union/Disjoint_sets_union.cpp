#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

class union_set
{
private:
    vi parent, p, rank, extra;

    int get_root(int n)
    {
        return (n == p[n] ? n : p[n] = get_root(p[n]));
    }

public:
    union_set(int n)
    {
        p.assign(n, 0);
        parent.assign(n, 0);
        rank.assign(n, 0);
        extra.assign(n, 0);
        for (int index = 0; index < n; ++index)
            p[index] = parent[index] = index;
    }

    void unite(int a, int b)
    {
        int root_a = get_root(a), root_b = get_root(b);
        if (root_a != root_b)
            if (rank[root_a] > rank[root_b])
            {
                extra[root_b] -= extra[root_a];
                p[root_b] = parent[root_b] = root_a;
            }
            else
            {
                extra[root_a] -= extra[root_b];
                p[root_a] = parent[root_a] = root_b;
                if (rank[root_a] == rank[root_b])
                    ++rank[root_b];
            }
    }

    void add(int n, int val)
    {
        extra[get_root(n)] += val;
    }

    int get(int n)
    {
        int player = n, point = 0;
        while (n != parent[n])
        {
            point += extra[n];
            n = parent[n];
        }
        return point + extra[n];
    }
};

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    union_set uns(n);

    char query[5];
    int l, r;
    while (m--)
    {
        scanf("%s", &query);
        if (strcmp(query, "join") == 0)
        {
            scanf("%d %d", &l, &r);
            uns.unite(--l, --r);
        }
        else if (strcmp(query, "add") == 0)
        {
            scanf("%d %d", &l, &r);
            uns.add(--l, r);
        }
        else
        {
            scanf("%d", &l);
            printf("%d\n", max(uns.get(--l), 0));
        }
    }

    return 0;
}