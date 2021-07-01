#include <cstdio>

struct Node
{
    int freq[40] = {0};
    long long count = 0;
    Node operator+(Node other)
    {
        Node tmp;
        int sum = 0;
        for (int index = 0; index < 40; ++index)
        {
            tmp.freq[index] = freq[index] + other.freq[index];
            tmp.count += (long long)freq[index] * sum;
            sum += other.freq[index];
        }
        tmp.count += count + other.count;
        return tmp;
    }
};

class Segment_Tree
{
private:
    int n;
    Node *st;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    const Node empty;

    void build(int p, int l, int r, int arr[])
    {
        if (l == r)
        {
            st[p].freq[--arr[l]] = 1;
            return;
        }

        int lft = lf(p);
        build(lft, l, (l + r) >> 1, arr);
        build(lft | 1, ((l + r) >> 1) + 1, r, arr);
        st[p] = st[lft] + st[lft | 1];
    }

    void update(int p, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;
        if (l == r)
        {
            for (int index = 0; index < 40; ++index)
                st[p].freq[index] = 0;
            st[p].freq[val] = 1;
            return;
        }
        int lft = lf(p);
        update(lft, l, (l + r) >> 1, idx, val);
        update(lft | 1, ((l + r) >> 1) + 1, r, idx, val);
        st[p] = st[lft] + st[lft | 1];
    }

    Node query(int p, int L, int R, int l, int r)
    {
        if (r < L || l > R)
            return empty;
        if (L >= l && R <= r)
            return st[p];
        return query(lf(p), L, (L + R) >> 1, l, r) + query(rg(p), ((L + R) >> 1) + 1, R, l, r);
    }

public:
    Segment_Tree(int n, int arr[])
    {
        this->n = n;
        st = new Node[n << 2];
        build(1, 0, n - 1, arr);
    }

    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    long long query(int l, int r) { return query(1, 0, n - 1, l, r).count; }
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int index = 0, val; index < n; scanf("%d", arr + index++))
        ;

    Segment_Tree st(n, arr);

    int type, a, b;

    while (m--)
    {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1)
            printf("%lli\n", st.query(--a, --b));
        else
            st.update(--a, --b);
    }

    return 0;
}