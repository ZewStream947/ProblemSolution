#include <cstdio>
#include <algorithm>

using namespace std;

class union_set
{
private:
    int *p, *rank;

    int get_par(int x)
    {
        return (x == p[x] ? x : p[x] = get_par(p[x]));
    }

public:
    union_set(int n)
    {
        p = new int[n + 1];
        rank = new int[n + 1];
        for (int index = 0; index <= n; ++index)
            p[index] = index, rank[index] = 0;
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

    bool is_same_set(int a, int b)
    {
        return get_par(a) == get_par(b);
    }
};

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &other)
    {
        return w < other.w;
    }
};

int main()
{
    int n, roads;

    scanf("%d %d", &n, &roads);

    union_set graph(n);

    Edge grp[roads];
    for (int index = 0; index < roads; ++index)
        scanf("%d %d %d", &grp[index].u, &grp[index].v, &grp[index].w);

    sort(grp, grp + roads);

    int result = -1;
    for (Edge e : grp)
        if (!graph.is_same_set(e.u, e.v))
        {
            graph.unite(e.u, e.v);
            result = max(result, e.w);
        }

    printf("%d", result);

    return 0;
}