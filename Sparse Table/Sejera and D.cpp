#include <iostream>
#include <algorithm>

#define MAX_SIZE 100005
#define MAX_LOG 18

using namespace std;

int table[MAX_SIZE][MAX_LOG], log[MAX_SIZE], dtc[MAX_SIZE], arr[MAX_SIZE], size;

void compute_log()
{
    log[1] = 0;
    for (int index = 2; index <= size; ++index)
        log[index] = log[index / 2] + 1;
}

void construct_table()
{
    for (int pow = 1; pow <= log[size]; ++pow)
        for (int index = 0, len = (1 << pow); index + len <= size; ++index)
            table[index][pow] = max(table[index][pow - 1], table[index + (len / 2)][pow - 1]);
}

bool check(int l, int r, int d)
{
    int lg = log[r - l + 1];
    int maxVal = max(table[l][lg], table[r - (1 << lg) + 1][lg]);
    return (maxVal <= d);
}

int query(int t, int d)
{
    if (size == 1)
        return 1;
    int lim = (upper_bound(arr, arr + size + 1, t) - arr) - 1;
    int minPos = lim;

    int l = 0, r = minPos - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, lim - 1, d))
        {
            minPos = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return minPos + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size;

    compute_log();

    --size;
    {
        cin >> arr[0];
        dtc[0] = arr[0];
        table[0][0] = arr[0];
        for (int index = 0; index < size; ++index)
        {
            cin >> arr[index + 1];
            dtc[index] = arr[index + 1] - arr[index];
            table[index][0] = dtc[index];
        }
    }

    construct_table();

    int queries, t, d;
    cin >> queries;
    while (queries--)
    {
        cin >> t >> d;
        cout << query(t, d) << '\n';
    }

    return 0;
}