#include <cstdio>
#include <vector>

using namespace std;

class union_set
{
private:
    vector<int> superios, p;

    int update(int x)
    {
        if (x == p[x])
            return x;
        int root = update(p[x]);
        superios[x] += superios[p[x]];
        return p[x] = root;
    }

public:
    union_set(int n)
    {
        p.resize(n);
        superios.assign(n, 0);
        for (int index = 0; index < n; ++index)
            p[index] = index;
    }

    void unite(int a, int b)
    {
        p[a] = b;
        ++superios[a];
    }

    int get_sups(int n)
    {
        update(n);
        return superios[n];
    }
};

int main()
{

    int n, queries;

    scanf("%d %d", &n, &queries);

    union_set un(n);

    int query, l, r;

    while (queries--)
    {
        scanf("%d", &query);
        if (query == 1)
        {
            scanf("%d %d", &l, &r);
            un.unite(--l, --r);
        }
        else
        {
            scanf("%d", &l);
            printf("%d\n", un.get_sups(--l));
        }
    }

    return 0;
}
