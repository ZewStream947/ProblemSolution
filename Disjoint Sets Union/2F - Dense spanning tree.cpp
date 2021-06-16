#include <iostream>
#include <algorithm>
#include <cstring>

#define INF (int(2e9) + 5)

using namespace std;

class union_set
{
private:
    int *par, *rank;

    int get_par(int x)
    {
        return (x == par[x] ? x : par[x] = get_par(par[x]));
    }

public:
    union_set(int n)
    {
        par = new int[n + 1];
        rank = new int[n + 1];
        reset(n);
    }

    void reset(int n)
    {
        for (int index = 0; index <= n; ++index)
            par[index] = index, rank[index] = 0;
    }

    void unite(int a, int b)
    {
        if ((a = get_par(a)) == (b = get_par(b)))
            return;
        if (rank[a] > rank[b])
            swap(a, b);
        par[a] = b;
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

    int vers, edgs;
    scanf("%d %d", &vers, &edgs);

    Edge edge[edgs];

    for (int index = 0; index < edgs; ++index)
        scanf("%d %d %d", &edge[index].u, &edge[index].v, &edge[index].w);

    sort(edge, edge + edgs);

    union_set graph(vers);
    int result = INF;

    for (int index = 0, idx, temp, k; index < edgs; ++index)
    {
        graph.reset(vers);
        temp = -INF;
        for (k = 0; index + k < edgs; ++k)
        {
            idx = index + k;
            if (!graph.is_same_set(edge[idx].u, edge[idx].v))
            {
                graph.unite(edge[idx].u, edge[idx].v);
                temp = max(temp, edge[idx].w - edge[index].w);
            }
        }
        bool isASpanningTree = 1;

        for (k = 2; k <= vers && isASpanningTree; ++k)
            isASpanningTree = graph.is_same_set(k - 1, k);
        if (isASpanningTree)
            result = min(result, temp);
    }

    result < INF ? printf("YES\n%d", result) : puts("NO");

    return 0;
}