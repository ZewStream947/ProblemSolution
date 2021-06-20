#include <cstdio>
#include <map>
#include <stack>

#define GET '?'

using namespace std;

typedef pair<int, int> ii;

class DSU
{
private:
    int *par, *size, cnt_connected;
    stack<int> stk;

    int get_par(int x)
    {
        while (x != par[x])
            x = par[x];
        return x;
    }

public:
    void reset(int n)
    {
        par = new int[n];
        size = new int[n];
        cnt_connected = n;
        for (int index = 0; index < n; ++index)
            par[index] = index, size[index] = 1;
    }

    void unite(int u, int v)
    {
        if ((u = get_par(u)) == (v = get_par(v)))
            return;
        if (size[u] > size[v])
            swap(u, v);
        par[u] = v;
        size[v] += size[u];
        --cnt_connected;
        stk.push(u);
    }

    void save()
    {
        stk.push(-1);
    }

    void rollback()
    {
        while (!stk.empty() && stk.top() != -1)
        {
            size[par[stk.top()]] -= size[stk.top()];
            par[stk.top()] = stk.top();
            ++cnt_connected;
            stk.pop();
        }

        if (!stk.empty())
            stk.pop();
    }

    int get_cnt_connected()
    {
        return cnt_connected;
    }
};

DSU graph;

struct Query
{
    int u = -1, v = -1, other_end = -1;
    char type = '\0';
};

void solve(int l, int r, Query query[])
{
    if (l == r)
    {
        if (query[l].type == GET)
            printf("%d\n", graph.get_cnt_connected());
        return;
    }

    int m = (l + r) >> 1;

    graph.save();
    for (int index = m + 1; index <= r; ++index)
        if (query[index].type != GET && query[index].other_end < l)
            graph.unite(query[index].u, query[index].v);
    solve(l, m, query);
    graph.rollback();

    graph.save();
    for (int index = l; index <= m; ++index)
        if (query[index].type != GET && query[index].other_end > r)
            graph.unite(query[index].u, query[index].v);
    solve(m + 1, r, query);
    graph.rollback();
}

int main()
{

    int n, m;

    scanf("%d %d", &n, &m);

    if (!m)
        return 0;

    graph.reset(n);

    map<ii, int> isExist;

    Query query[m << 1];

    for (int index = 0; index < m; ++index)
    {
        scanf(" %c", &query[index].type);
        if (query[index].type == GET)
            continue;
        scanf("%d %d", &query[index].u, &query[index].v), --query[index].u, --query[index].v;
        if (query[index].u > query[index].v)
            swap(query[index].u, query[index].v);
        map<ii, int>::iterator pos = isExist.find(make_pair(query[index].u, query[index].v));
        if (pos != isExist.end())
        {
            query[pos->second].other_end = index;
            query[index].other_end = pos->second;
            isExist.erase(pos);
        }
        else
            isExist[make_pair(query[index].u, query[index].v)] = index;
    }

    for (pair<ii, int> val : isExist)
    {
        query[m].u = val.first.first;
        query[m].v = val.first.second;
        query[m].other_end = val.second;
        query[val.second].other_end = m++;
    }

    solve(0, m - 1, query);

    return 0;
}