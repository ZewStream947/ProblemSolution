#include <iostream>
#include <cstring>

using namespace std;

class union_set
{
private:
    int *rank, *par;

    int get_par(int x)
    {
        return (x == par[x] ? x : par[x] = get_par(par[x]));
    }

public:
    void reset(int n)
    {
        rank = new int[n];
        par = new int[n];
        for (int index = 0; index < n; ++index)
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
        return (get_par(a) == get_par(b));
    }
};
int main()
{

    int TC;
    scanf("%d\n", &TC);

    union_set network;

    int a, b, n, succ, unsucc;
    char c, query[100];

    bool first = 1;
    while (TC--)
    {
        if (!first)
            printf("\n");
        else
            first = 0;
        succ = unsucc = 0;
        scanf("%d\n", &n);
        network.reset(n);
        while (gets(query) != NULL)
        {
            if (strcmp(query, "") == 0)
                break;
            sscanf(query, "%c %d %d", &c, &a, &b);
            if (c == 'c')
                network.unite(--a, --b);
            else if (network.is_same_set(--a, --b))
                ++succ;
            else
                ++unsucc;
        }
        printf("%d,%d\n", succ, unsucc);
    }

    return 0;
}