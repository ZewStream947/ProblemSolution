#include <iostream>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

class union_set
{
private:
    int *p, *rank, *len, shift, n;

    ii get(int x)
    {
        if (x == p[x])
            return {x, 0};
        ii val = get(p[x]);
        p[x] = val.fi;
        len[x] = (val.se + len[x]) % 2;
        return {p[x], len[x]};
    }

public:
    union_set(int n)
    {
        this->n = n;
        shift = 0;
        p = new int[n];
        rank = new int[n];
        len = new int[n];
        for (int index = 0; index < n; ++index)
            p[index] = index, rank[index] = len[index] = 0;
    }

    void unite(int a, int b)
    {
        ii val_a = get((a + shift) % n), val_b = get((b + shift) % n);
        if (val_a.fi == val_b.fi)
            return;
        if (rank[val_a.fi] > rank[val_b.fi])
            swap(val_a, val_b);
        p[val_a.fi] = val_b.fi;
        len[val_a.fi] = (val_a.se + 1 + val_b.se) % 2;
        if (rank[val_a.fi] == rank[val_b.fi])
            rank[val_b.fi];
    }

    bool is_same_color(int a, int b)
    {
        return get((a + shift) % n) == get((b + shift) % n);
    }

    void inc_shift()
    {
        shift = (shift + 1) % n;
    }
};

int main()
{

    int n, queries;

    scanf("%d %d", &n, &queries);

    union_set graph(n);

    int query, a, b;

    while (queries--)
    {
        scanf("%d %d %d", &query, &a, &b);
        if (query)
        {
            if (graph.is_same_color(--a, --b))
                puts("YES"), graph.inc_shift();
            else
                puts("NO");
        }
        else
            graph.unite(--a, --b);
    }

    return 0;
}