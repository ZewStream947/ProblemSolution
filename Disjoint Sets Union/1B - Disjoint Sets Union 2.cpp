#include <cstdio>
#include <vector>
#include <cstring>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

using namespace std;

typedef vector<int> vi;

class disjoint_set_union
{
private:
    vi p, rank, minS, maxS, sizeS;

    int get_root(int val)
    {
        return (p[val] == val ? val : p[val] = get_root(p[val]));
    }

public:
    disjoint_set_union(int n)
    {
        rank.assign(n, 0);
        maxS.assign(n, 0);
        minS.assign(n, 0);
        sizeS.assign(n, 1);
        p.assign(n, 0);
        for (int val = 0; val < n; ++val)
            p[val] = maxS[val] = minS[val] = val;
    }

    int get_min(int val)
    {
        return minS[get_root(val - 1)];
    }

    int get_max(int val)
    {
        return maxS[get_root(val - 1)];
    }

    int get_size(int val)
    {
        return sizeS[get_root(val - 1)];
    }

    void unite(int a, int b)
    {
        int root_a = get_root(a - 1), root_b = get_root(b - 1);
        if (root_a != root_b)
            if (rank[root_a] > rank[root_b])
            {
                p[root_b] = root_a;
                sizeS[root_a] += sizeS[root_b];
                maxS[root_a] = max(maxS[root_a], maxS[root_b]);
                minS[root_a] = min(minS[root_a], minS[root_b]);
            }
            else
            {
                p[root_a] = root_b;
                sizeS[root_b] += sizeS[root_a];
                maxS[root_b] = max(maxS[root_a], maxS[root_b]);
                minS[root_b] = min(minS[root_a], minS[root_b]);
                if (rank[root_a] == rank[root_b])
                    ++rank[root_b];
            }
    }
};

int main()
{
    int size, queries;

    scanf("%d %d", &size, &queries);
    disjoint_set_union union_set(size);

    char query[6];
    int l, r;

    while (queries--)
    {
        scanf("%s", &query);
        if (strcmp(query, "union") == 0)
        {
            scanf("%d %d", &l, &r);
            union_set.unite(l, r);
        }
        else
        {
            scanf("%d", &l);
            printf("%d %d %d\n", union_set.get_min(l) + 1, union_set.get_max(l) + 1, union_set.get_size(l));
        }
    }

    return 0;
}