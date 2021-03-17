#include <iostream>

#define MAX_SIZE 100010
#define MAX_LOG 18

using namespace std;

int Min[MAX_SIZE][MAX_LOG], Max[MAX_SIZE][MAX_LOG], *log, size;

void compute_log()
{
    log = (int *)malloc((size + 1) * sizeof(int));
    log[1] = 0;
    for (int index = 2; index <= size; ++index)
        log[index] = log[index / 2] + 1;
}

void construct_Mintable()
{
    for (int pow = 1; pow <= log[size]; ++pow)
        for (int index = 0, len = 1 << pow; index + len <= size; ++index)
            Min[index][pow] = min(Min[index][pow - 1], Min[index + (len >> 1)][pow - 1]);
}

void construct_Maxtable()
{
    for (int pow = 1; pow <= log[size]; ++pow)
        for (int index = 0, len = 1 << pow; index + len <= size; ++index)
            Max[index][pow] = max(Max[index][pow - 1], Max[index + (len >> 1)][pow - 1]);
}

int Max_query(int l, int r)
{
    if (l > r)
        return -100000001;
    int lg = log[r - l + 1];
    return max(Max[l][lg], Max[r - (1 << lg) + 1][lg]);
}
int Min_query(int l, int r)
{
    int lg = log[r - l + 1];
    return min(Min[l][lg], Min[r - (1 << lg) + 1][lg]);
}

double solve(int l, int r)
{

    double m = Min_query(l, r);
    return m + max((Max_query(l, r) - m) / 2.0, max(Max_query(0, l - 1) * 1.0, Max_query(r + 1, size - 1) * 1.0));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size;

    compute_log();

    for (int index = 0; index < size; ++index)
        cin >> Min[index][0],
            Max[index][0] = Min[index][0];

    construct_Mintable();
    construct_Maxtable();

    int queries, l, r;
    cin >> queries;

    cout.precision(1);
    while (queries--)
    {
        cin >> l >> r;
        cout << fixed << solve(l, r) << '\n';
    }

    return 0;
}