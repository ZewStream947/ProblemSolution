#include <bits/stdc++.h>

#define MOD int(1e9 + 7)
#define MAX_SIZE 2001

using namespace std;

long long f[MAX_SIZE][MAX_SIZE];
char l[MAX_SIZE], r[MAX_SIZE];
int m, d, size;

void dec()
{
    int index = size - 1;

    while (l[index] == '0')
        l[index--] = '9';

    --l[index];
}

int solve(char *num, int index, int tight, int mod)
{
    if (index == size)
        return (mod == 0);

    if (!tight && f[index][mod] != -1)
        return f[index][mod];

    int lim = tight ? num[index] - '0' : 9;
    int ret = 0;

    for (int val = 0; val <= lim; ++val)
    {
        if (((index & 1) && val != d) || (!(index & 1) && val == d))
            continue;
        ret = (ret + solve(num, index + 1, tight && (val == lim), (mod * 10 + val) % m)) % MOD;
    }

    if (!tight)
        return f[index][mod] = ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> d >> l >> r;

    size = strlen(l);
    dec();
    memset(f, -1, sizeof(f));
    cout << (solve(r, 0, 1, 0) - solve(l, 0, 1, 0) + MOD) % MOD;

    return 0;
}