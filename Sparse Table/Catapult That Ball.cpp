#include <iostream>

using namespace std;

int **table, *log, size;

void construct_log()
{
    log = (int *)malloc((size + 1) * sizeof(int));
    log[1] = 0;
    for (int index = 2; index <= size; ++index)
        log[index] = log[index / 2] + 1;
}

void construct_table()
{
    for (int pow = 1; pow <= log[size]; ++pow)
        for (int index = 0, len = (1 << pow); index + len <= size; ++index)
            table[index][pow] = max(table[index][pow - 1], table[index + (len >> 1)][pow - 1]);
}

int query(int l, int r)
{
    int lg = log[r - l + 1];
    return max(table[l][lg], table[r - (1 << lg) + 1][lg]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries;

    cin >> size >> queries;

    construct_log();

    table = new int *[size];

    for (int index = 0; index < size; ++index)
    {
        table[index] = new int[log[size] + 1];
        cin >> table[index][0];
    }

    construct_table();

    int l, r, cnt = 0;

    while (queries--)
    {
        cin >> l >> r;
        int cmp = l - 1;
        if (l > r)
            swap(l, r);
        if (query(l - 1, r - 2) <= table[cmp][0])
            ++cnt;
    }

    cout << cnt;

    return 0;
}