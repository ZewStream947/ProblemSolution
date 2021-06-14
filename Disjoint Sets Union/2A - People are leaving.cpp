#include <cstdio>
#include <vector>

using namespace std;

class union_set
{
private:
    vector<int> p;

public:
    union_set(int n)
    {
        p.resize(n + 1);
        for (int index = 0; index <= n; ++index)
            p[index] = index;
    }

    void unite(int x)
    {
        p[get(x)] = get(x + 1);
    }

    int get(int x)
    {
        return (x == p[x] ? x : p[x] = get(p[x]));
    }
};

int main()
{
    int n, queries, pos;

    scanf("%d %d", &n, &queries);

    char c;

    union_set query(n);

    while (queries--)
    {
        scanf(" %c %d", &c, &pos);
        if (c == '?')
        {
            pos = query.get(pos - 1);
            printf("%d\n", pos != n ? pos + 1 : -1);
        }
        else
            query.unite(pos - 1);
    }

    return 0;
}