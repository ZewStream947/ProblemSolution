#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int u, v, w;
};

class union_set
{
private:
    vector<int> p, rank;

    int get_par(int x)
    {
        return (x == p[x] ? x : p[x] = get_par(p[x]));
    }

public:
    union_set(int n)
    {
        p.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int index = 1; index <= n; ++index)
            p[index] = index;
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

int main()
{
    int vers, eg;
    scanf("%d %d", &vers, &eg);

    edge edges[eg];

    for (int index = 0; index < eg; ++index)
        scanf("%d %d %d", &edges[index].u, &edges[index].v, &edges[index].w);

    sort(edges, edges + eg, [](edge a, edge b)
         { return a.w < b.w; });

    union_set graph(vers);
    long long result = 0;
    for (int index = 0; index < eg; ++index)
        if (!graph.is_same_set(edges[index].u, edges[index].v))
        {
            graph.unite(edges[index].u, edges[index].v);
            result += edges[index].w;
        }

    printf("%lli", result);

    return 0;
}