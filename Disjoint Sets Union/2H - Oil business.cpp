#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>

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
        for (int index = 1; index <= n; ++index)
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
    int n, m;
    long long lim, currSum = 0;

    scanf("%d %d %lli", &n, &m, &lim);

    Edge grp[m];
    bool check[m] = {0};

    unordered_map<int, unordered_map<int, int>> store;

    for (int index = 0; index < m; ++index)
    {
        scanf("%d %d %d", &grp[index].u, &grp[index].v, &grp[index].w);
        store[grp[index].u][grp[index].v] = index + 1;
    }

    sort(grp, grp + m);

    union_set graph(n);

    for (int index = m - 1; index >= 0; --index)
        if (!graph.is_same_set(grp[index].u, grp[index].v))
        {
            graph.unite(grp[index].u, grp[index].v);
            check[index] = 1;
        }

    vector<int> result;

    for (int index = 0; index < m; ++index)
        if (!check[index])
            if (currSum + grp[index].w <= lim)
            {
                currSum += grp[index].w;
                result.push_back(store[grp[index].u][grp[index].v]);
            }

    printf("%d\n", result.size());
    for (int val : result)
        printf("%d ", val);
    return 0;
}