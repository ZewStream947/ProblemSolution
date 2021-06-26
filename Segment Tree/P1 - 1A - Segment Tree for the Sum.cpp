#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
class Segment_Tree
{
private:
    int n;
    vi arr;
    vll st;

    int left(int p)
    {
        return p << 1;
    }

    int right(int p)
    {
        return (p << 1) | 1;
    }

    void build(int par, int l, int r)
    {
        if (l == r)
            st[par] = arr[l];
        else
        {
            build(left(par), l, (l + r) >> 1);
            build(right(par), ((l + r) >> 1) + 1, r);
            st[par] = (long long)st[left(par)] + (long long)st[right(par)];
        }
    }

    long long update(int par, int l, int r, int idx, int new_val)
    {
        if (idx < l || idx > r)
            return st[par];
        if (l == r)
            return st[par] = new_val;

        long long val1 = update(left(par), l, (l + r) >> 1, idx, new_val);
        long long val2 = update(right(par), ((l + r) >> 1) + 1, r, idx, new_val);
        return st[par] = (long long)val1 + (long long)val2;
    }

    long long get_sum(int par, int L, int R, int l, int r)
    {
        if (l > R || r < L)
            return 0;
        if (L >= l && R <= r)
            return st[par];
        return get_sum(left(par), L, (L + R) >> 1, l, r) + get_sum(right(par), ((L + R) >> 1) + 1, R, l, r);
    }

public:
    Segment_Tree(const vi &arr)
    {
        this->arr = arr;
        st.assign(arr.size() << 2, 0);
        build(1, 0, arr.size() - 1);
    }

    void update(int index, int new_val)
    {
        update(1, 0, arr.size() - 1, index, new_val);
    }

    long long get_sum(int l, int r)
    {
        return get_sum(1, 0, arr.size() - 1, l, r);
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

    int type, l, r;

    while (m--)
    {
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
            st.update(l, r);
        else
            printf("%lli\n", st.get_sum(l, --r));
    }

    return 0;
}
