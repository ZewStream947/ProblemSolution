#include <cstdio>
#include <bitset>

const int MAXSIZE = 2e5;

int n;
std::bitset<41> st[MAXSIZE];

std::bitset<41> result;

void build()
{
    for (int index = n - 1; index; --index)
        st[index] = st[index << 1] | st[index << 1 | 1];
}

void modify(int idx, int val)
{
    st[idx += n].reset();
    st[idx].set(val);
    for (; idx > 1; idx >>= 1)
        st[idx >> 1] = st[idx] | st[idx ^ 1];
}

int query(int l, int r)
{
    result.reset();
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            result |= st[l++];
        if (!(r & 1))
            result |= st[r--];
    }
    return result.count();
}

int main()
{

    int m;
    scanf("%d %d", &n, &m);

    for (int index = 0, val; index < n; ++index)
        scanf("%d", &val),
            st[index + n].set(val);

    build();

    int type, a, b;

    while (m--)
    {
        scanf("%d %d %d", &type, &a, &b);
        if (type == 1)
            printf("%d\n", query(--a, --b));
        else
            modify(--a, b);
    }

    return 0;
}