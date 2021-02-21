#include <bits/stdc++.h>

#define LL long long
#define MAX_LEN 20
#define BOOL_VALS 2

using namespace std;

vector<short int> target;
short int len = 0;

LL f[MAX_LEN][MAX_LEN][BOOL_VALS][BOOL_VALS];

void convert(LL converter, vector<short int> &target, short int &len)
{
    target.clear();

    while (converter)
    {
        target.push_back(converter % 10);
        converter /= 10;
    }

    len = target.size();
}

LL solve(int l, int r, bool tightL, bool tightR, bool isLeadingbyZero)
{
    if (l < r)
        return !tightL || !tightR;

    if (!tightL && f[l][r][tightR][isLeadingbyZero] != -1)
        return f[l][r][tightR][isLeadingbyZero];

    LL ret = 0;

    int lim = tightL ? target[l] : 9;

    for (int val = 0; val <= lim; ++val)
        ret += solve(l - 1, r + ((!isLeadingbyZero | val != 0) & (l != r)), tightL & (val == lim), (val == target[r]) ? tightR : (val > target[r]), isLeadingbyZero & (val == 0));

    if (!tightL)
        return f[l][r][tightR][isLeadingbyZero] = ret;

    return ret;
}

LL solve(LL number)
{
    if (number < 10)
        return number + 1;

    convert(number, target, len);

    return solve(len - 1, 0, 1, 0, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    short int cases;

    cin >> cases;

    memset(f, -1, sizeof(f));

    for (int t = 1; t <= cases; ++t)
    {
        LL l, r;

        cin >> l >> r;

        if (l > r)
            swap(l, r);

        cout << "Case " << t << ": " << solve(r) - solve(l - 1) << endl;
    }

    return 0;
}
