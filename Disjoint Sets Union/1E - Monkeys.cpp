#include <cstdio>
#include <vector>
#include <set>

#define fi first
#define se second
#define v(type) vector<type>
#define p(type1, type2) pair<type1, type2>

using namespace std;

class union_set
{
private:
    v(int) p, result;
    v(v(int)) children;

    int get_par(int n)
    {
        return (n == p[n] ? n : p[n] = get_par(p[n]));
    }

public:
    union_set(int n, int secs)
    {
        p.assign(n, 0);
        result.assign(n, secs);
        children.assign(n, v(int)(0));
        for (int index = 0; index < n; ++index)
        {
            p[index] = index;
            children[index].push_back(index);
        }
    }

    void unite(int a, int b, int sec)
    {
        if ((a = get_par(a)) == (b = get_par(b)))
            return;
        if (a > b)
            swap(a, b);
        if (a == 0)
            for (int child : children[b])
                result[child] = sec;
        children[a].insert(children[a].end(), children[b].begin(), children[b].end());
        p[b] = a;
    }

    void print_result(int n, int secs)
    {
        for (int index = 0; index < n; ++index)
            printf("%d\n", result[index] != secs ? result[index] : -1);
    }
};

int main()
{
    int monks, rls;
    scanf("%d %d", &monks, &rls);

    v(p(int, int)) config(monks);
    v(p(bool, bool)) check(monks, p(bool, bool)(0, 0));

    for (int index = 0; index < monks; ++index)
    {
        scanf("%d %d", &config[index].fi, &config[index].se);
        config[index].fi > 0 ? --config[index].fi : check[index].fi = 1;
        config[index].se > 0 ? --config[index].se : check[index].se = 1;
    }

    v(p(int, int)) rls_order(rls);

    for (int index = 0; index < rls; ++index)
    {
        scanf("%d %d", &rls_order[index].fi, &rls_order[index].se);
        if (rls_order[index].se == 1)
        {
            check[--rls_order[index].fi].fi = 1;
            rls_order[index].se = config[rls_order[index].fi].fi;
        }
        else
        {
            check[--rls_order[index].fi].se = 1;
            rls_order[index].se = config[rls_order[index].fi].se;
        }
    }

    union_set graph(monks, rls);
    for (int index = 0; index < monks; ++index)
    {
        if (!check[index].fi)
            graph.unite(index, config[index].fi, rls);
        if (!check[index].se)
            graph.unite(index, config[index].se, rls);
    }

    for (int sec = rls - 1; sec >= 0; --sec)
        graph.unite(rls_order[sec].fi, rls_order[sec].se, sec);

    graph.print_result(monks, rls);
    return 0;
}