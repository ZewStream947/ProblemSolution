#include <iostream>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

class union_set
{
private:
    int *p, *rank, *len;

    ii get(int x)
    {
        if (x == p[x])
            return make_pair(x, 0);
        ii val = get(p[x]);
        p[x] = val.fi;
        len[x] = (val.se + len[x]) % 2;
        return make_pair(p[x], len[x]);
    }

public:
    union_set(int n)
    {
        p = new int[n];
        rank = new int[n];
        len = new int[n];
        for (int index = 0; index < n; ++index)
            p[index] = index, rank[index] = len[index] = 0;
    }

    void unite(int a, int b)
    {
        ii val_a = get(a), val_b = get(b);
        if (val_a.fi == val_b.fi)
            return;
        if (rank[val_a.fi] > rank[val_b.fi])
            swap(val_a, val_b);
        p[val_a.fi] = val_b.fi;
        len[val_a.fi] = (val_a.se + 1 + val_b.se) % 2;
        if (rank[val_a.fi] == rank[val_b.fi])
            ++rank[val_b.fi];
    }

    bool is_same_part(int a, int b)
    {
        return get(a) == get(b);
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    union_set graph(n);

    int cnt = 1, a, b;
    for (; cnt <= m; ++cnt)
    {
        scanf("%d %d", &a, &b);
        if (!graph.is_same_part(--a, --b))
            graph.unite(a, b);
        else
        {
            printf("%d", cnt);
            break;
        }
    }

    if (cnt > m)
        puts("-1");
    return 0;
}