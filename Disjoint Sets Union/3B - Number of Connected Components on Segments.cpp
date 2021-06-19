#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

class DSU
{
private:
    stack<int> stk;
    int *par, *rank, curr_connected;

    int path_cp(int x)
    {
        return (x == par[x] ? x : par[x] = path_cp(par[x]));
    }

    int get_par(int x)
    {
        while (x != par[x])
            x = par[x];
        return par[x];
    }

public:
    DSU(int n)
    {
        rank = new int[n];
        par = new int[n];
        curr_connected = n;
        for (int index = 0; index < n; ++index)
            par[index] = index, rank[index] = 0;
    }

    void unite(int a, int b, bool c)
    {
        if (c)
        {
            if ((a = path_cp(a)) == (b = path_cp(b)))
                return;
        }
        else if ((a = get_par(a)) == (b = get_par(b)))
            return;
        if (rank[a] > rank[b])
            swap(a, b);
        if (rank[a] == rank[b])
            ++rank[b];
        --curr_connected;
        par[a] = b;
        stk.push(a);
    }

    void save()
    {
        stk.push(-1);
    }

    void rollback()
    {
        while (!stk.empty() && stk.top() != -1)
        {
            --rank[par[stk.top()]];
            par[stk.top()] = stk.top();
            stk.pop();
            ++curr_connected;
        }
        if (!stk.empty())
            stk.pop();
    }

    int get_connected()
    {
        return curr_connected;
    }
};

struct Edge
{
    int u, v;
};

struct Query
{
    int l, r, index, blk;
    //Mo's comparator
    bool operator<(const Query &other)
    {
        if (blk != other.blk)
            return blk < other.blk;
        return r < other.r;
    }
};

int main()
{
    //Initializing
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edge[m];

    for (int index = 0; index < m; ++index)
    {
        scanf("%d %d", &edge[index].u, &edge[index].v);
        --edge[index].u, --edge[index].v;
    }

    int queries;
    scanf("%d", &queries);

    const int block = ceil(sqrt(m)); //block size

    Query query[queries];

    for (int index = 0, l, r; index < queries; ++index)
    {
        scanf("%d %d", &l, &r);
        --l, --r;
        query[index].l = l;
        query[index].r = r;
        query[index].index = index;
        query[index].blk = l / block;
    }

    sort(query, query + queries);

    //Solving

    int result[queries];

    int currBlock = 0, index = 0;

    DSU graph(n);

    for (int currBlock = 0, index = 0; currBlock < block && index < queries; ++currBlock)
    {
        graph.rollback();
        int nextBlkIdx = (currBlock + 1) * block;
        int prevR = nextBlkIdx - 1;
        while (index < queries && query[index].blk == currBlock)
        {
            if (query[index].r < nextBlkIdx)
            {
                for (int idx = query[index].l; idx <= query[index].r; ++idx)
                    graph.unite(edge[idx].u, edge[idx].v, 1);
            }
            else
            {
                for (int idx = prevR + 1; idx <= query[index].r; ++idx)
                    graph.unite(edge[idx].u, edge[idx].v, 1);
                prevR = query[index].r;
                graph.save();
                for (int idx = query[index].l; idx < nextBlkIdx; ++idx)
                    graph.unite(edge[idx].u, edge[idx].v, 0);
            }
            result[query[index].index] = graph.get_connected();
            graph.rollback();
            ++index;
        }
    }

    for (int val : result)
        printf("%d\n", val);

    return 0;
}