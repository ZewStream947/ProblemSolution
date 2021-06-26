#include <cstdio>
#include <vector>

#define INF int(1e9 + 1)

using namespace std;

typedef vector<int> vi;

class Segment_Tree
{
private:
    vi arr, st;

    int left(int par)
    {
        return par << 1;
    }

    int right(int par)
    {
        return (par << 1) | 1;
    }

    int construct(int par, int l, int r)
    {
        return st[par] = ((l == r) ? arr[l] : min(construct(left(par), l, (l + r) >> 1), construct(right(par), ((l + r) >> 1) + 1, r)));
    }

    int update(int par, int l, int r, int index, int new_val)
    {
        if (index < l || index > r)
            return st[par];

        return st[par] = (l == r ? new_val : min(update(left(par), l, (l + r) >> 1, index, new_val), update(right(par), ((l + r) >> 1) + 1, r, index, new_val)));
    }

    int minQuery(int par, int L, int R, int l, int r)
    {
        if (r < L || l > R)
            return INF;
        if (L >= l && R <= r)
            return st[par];
        return min(minQuery(left(par), L, (L + R) >> 1, l, r), minQuery(right(par), ((L + R) >> 1) + 1, R, l, r));
    }

public:
    Segment_Tree(const vi &arr)
    {
        this->arr = arr;
        st.assign(arr.size() << 2, 0);
        construct(1, 0, arr.size() - 1);
    }

    void update(int index, int new_val)
    {
        update(1, 0, arr.size() - 1, index, new_val);
    }

    int minQuery(int l, int r)
    {
        return minQuery(1, 0, arr.size() - 1, l, r);
    }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];

    for (int index = 0; index < n; scanf("%d", &arr[index++]))
        ;

    Segment_Tree st(vi(arr, arr + n));

    int type, a, b;

    while (m--)
    {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1)
            st.update(a, b);
        else
            printf("%d\n", st.minQuery(a, --b));
    }

    return 0;
}