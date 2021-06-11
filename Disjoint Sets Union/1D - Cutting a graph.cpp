#include <cstdio>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class union_set
{
private:
    vector<int> p, rank;
    int get_root(int x)
    {
        return (x == p[x] ? x : p[x] = get_root(p[x]));
    }

public:
    union_set(int n)
    {
        p.assign(n + 1, 0);
        rank.assign(n + 1, 0);
        for (int index = 1; index <= n; ++index)
            p[index] = index;
    }

    void unite(int l, int r)
    {
        int root_l = get_root(l), root_r = get_root(r);
        if (root_l != root_r)
            if (rank[root_l] > rank[root_r])
                p[root_r] = root_l;
            else
            {
                p[root_l] = root_r;
                if (rank[root_l] == rank[root_r])
                    ++rank[root_r];
            }
    }

    bool is_same_component(int l, int r)
    {
        return get_root(l) == get_root(r);
    }
};

int main()
{
    int vertices, edges, queries;

    scanf("%d %d %d", &vertices, &edges, &queries);

    vector<set<int>> grp(vertices + 1);

    int l, r;

    for (int index = 0; index < edges; ++index)
        scanf("%d %d", &l, &r),
            grp[l].insert(r),
            grp[r].insert(l);

    vector<pair<bool, pair<int, int>>> query(queries);

    char format[4];

    for (int index = queries - 1; index >= 0; --index)
    {
        scanf("%s %d %d", &format, &query[index].second.first, &query[index].second.second);
        if (strcmp(format, "cut") == 0)
        {
            query[index].first = 1;
            grp[query[index].second.first].erase(query[index].second.second);
            grp[query[index].second.second].erase(query[index].second.first);
        }
        else
            query[index].first = 0;
    }

    union_set graph(vertices);
    for (int index = 1; index <= vertices; ++index)
        for (int x : grp[index])
            graph.unite(index, x);

    vector<bool> result;

    for (int index = 0; index < queries; ++index)
        if (query[index].first)
            graph.unite(query[index].second.first, query[index].second.second);
        else
            result.push_back(graph.is_same_component(query[index].second.first, query[index].second.second));

    for (int index = result.size() - 1; index >= 0; --index)
        result[index] ? puts("YES") : puts("NO");

    return 0;
}