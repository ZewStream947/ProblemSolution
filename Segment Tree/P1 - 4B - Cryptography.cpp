#include <iostream>
#include <vector>

using namespace std;

int r;

struct mtx
{
    int a, b, c, d;
    mtx operator*(const mtx &other)
    {
        if (a == -1 && other.a == -1)
            return {0, 0, 0, 0};
        if (a == -1)
            return other;
        if (other.a == -1)
            return {a, b, c, d};
        mtx tmp;
        tmp.a = ((((a % r) * (other.a % r))) % r + (((b % r) * (other.c % r))) % r) % r;
        tmp.b = ((((a % r) * (other.b % r))) % r + (((b % r) * (other.d % r))) % r) % r;
        tmp.c = ((((c % r) * (other.a % r))) % r + (((d % r) * (other.c % r))) % r) % r;
        tmp.d = ((((c % r) * (other.b % r))) % r + (((d % r) * (other.d % r))) % r) % r;
        return tmp;
    }
};

class Segment_Tree
{
private:
    int n;
    vector<mtx> st;

    int lf(int p) { return p << 1; }
    int rg(int p) { return p << 1 | 1; }

    mtx build(int p, int l, int r, mtx arr[])
    {
        return st[p] = l == r ? arr[l] : build(lf(p), l, (l + r) >> 1, arr) * build(rg(p), ((l + r) >> 1) + 1, r, arr);
    }

    mtx query(int p, int L, int R, int l, int r)
    {
        if (r < L || l > R)
            return {-1, -1, -1, -1};
        if (L >= l && R <= r)
            return st[p];
        return query(lf(p), L, (L + R) >> 1, l, r) * query(rg(p), ((L + R) >> 1) + 1, R, l, r);
    }

public:
    Segment_Tree(mtx arr[], int n)
    {
        this->n = n;
        st.assign(n << 2, {0, 0, 0, 0});
        build(1, 0, n - 1, arr);
    }

    mtx query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;

    cin >> r >> n >> m;

    mtx arr[n];

    for (int index = 0; index < n; ++index)
        cin >> arr[index].a >> arr[index].b >> arr[index].c >> arr[index].d;

    Segment_Tree st(arr, n);

    mtx result;
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        result = st.query(--l, --r);
        cout << result.a << ' ' << result.b << '\n'
             << result.c << ' ' << result.d << "\n\n";
    }

    return 0;
}