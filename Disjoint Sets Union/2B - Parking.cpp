#include <cstdio>
#include <vector>

using namespace std;

class cirle_union_set
{
private:
    vector<int> p;

    int get_par(int x)
    {
        return (x == p[x] ? x : p[x] = get_par(p[x]));
    }

public:
    cirle_union_set(int n)
    {
        p.resize(n + 1);
        for (int index = 0; index < n; ++index)
            p[index] = index;
        p[n] = 0;
    }

    void unite(int x)
    {
        p[x] = get_par(x + 1);
    }

    int get_pos(int x)
    {
        int pos = get_par(x);
        unite(pos);
        return pos;
    }
};

int main()
{
    int queries, demand;

    scanf("%d", &queries);

    cirle_union_set park(queries);

    while (queries--)
    {
        scanf("%d", &demand);
        printf("%d ", park.get_pos(demand - 1) + 1);
    }

    return 0;
}