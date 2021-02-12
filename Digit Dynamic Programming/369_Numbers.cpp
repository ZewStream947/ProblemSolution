#include <bits/stdc++.h>

#define MOD int(1e9 + 7)
#define MAX_SIZE 51
#define MAX_COUNT int(MAX_SIZE / 3 + 1)
#define ll long long

using namespace std;

ll f[MAX_SIZE][MAX_COUNT][MAX_COUNT][MAX_COUNT];
char le[MAX_SIZE], ri[MAX_SIZE];
string target;
int len;

void dec(char *number)
{
    int index = strlen(number) - 1;

    while (number[index] == '0')
        number[index--] = '9';

    --number[index];
}
int solve(int index, bool tight, int cn3, int cn6, int cn9)
{
    if (cn3 >= 17 or cn6 >= 17 or cn9 >= 17)
        return 0;
    if (index == -1)
        return (cn3 == cn6) && (cn3 == cn9) && (cn3 > 0);

    if (!tight && f[index][cn3][cn6][cn9] != -1)
        return f[index][cn3][cn6][cn9] % MOD;

    int lim = tight ? target[index] - '0' : 9;

    int ret = 0;

    for (int val = 0; val <= lim; ++val)
        ret = (ret + solve(index - 1, tight && (val == lim), (val == 3) + cn3, (val == 6) + cn6, (val == 9) + cn9)) % MOD;

    return tight ? ret : f[index][cn3][cn6][cn9] = ret;
}

int solve(char *number)
{
    target = number;
    len = target.size();
    reverse(target.begin(), target.end());
    return solve(len - 1, 1, 0, 0, 0) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    memset(f, -1, sizeof(f));

    while (t--)
    {
        cin >> le >> ri;
        dec(le);
        cout << (solve(ri) - solve(le) + MOD) % MOD << endl;
    }

    return 0;
}