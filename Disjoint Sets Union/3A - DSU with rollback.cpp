#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

class DSU
{
private:
    int *par, sets;

    stack<int> stk;

    int get_par(int x)
    {
        while (x != par[x])
            x = par[x];
        return par[x];
    }

public:
    DSU(int n)
    {
        sets = n;
        par = new int[n];
        for (int index = 0; index < n; ++index)
            par[index] = index;
    }

    void unite(int a, int b)
    {
        if ((a = get_par(a)) == (b = get_par(b)))
            return;
        stk.push(a);
        --sets;
        par[a] = b;
    }

    void save()
    {
        stk.push(-1);
    }

    void rollback()
    {
        while (!stk.empty() && stk.top() != -1)
        {
            par[stk.top()] = stk.top();
            stk.pop();
            ++sets;
        }

        if (!stk.empty())
            stk.pop();
    }

    int number_of_sets()
    {
        return sets;
    }
};

int main()
{
    int n, queries;
    scanf("%d %d", &n, &queries);

    DSU graph(n);

    char query[9];
    int l, r;

    while (queries--)
    {
        scanf(" %s", &query);
        if (strcmp(query, "persist") == 0)
            graph.save();
        else
        {
            if (strcmp(query, "union") == 0)
            {
                scanf("%d %d", &l, &r);
                graph.unite(--l, --r);
            }
            else
                graph.rollback();
            printf("%d\n", graph.number_of_sets());
        }
    }

    return 0;
}