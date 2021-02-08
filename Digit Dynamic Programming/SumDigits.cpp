#include <bits/stdc++.h>

#define ll long long

using namespace std;

string target;

ll f[16][2][136];

string to_str(ll number)
{
    stringstream convert;
    convert << number;
    return convert.str();
}

ll solve(int index, bool tight, ll sum)
{
    if (index == target.size())
        return sum;

    if (f[index][tight][sum] != -1)
        return f[index][tight][sum];

    int lim = (tight) ? target[index] - '0' : 9;

    ll ret = 0;

    for (int val = 0; val <= lim; ++val)
        ret += solve(index + 1, tight && (val == lim), sum + val);

    return f[index][tight][sum] = ret;
}

void solve()
{
    ll left, right;
    cin >> left >> right;

    memset(f, -1, sizeof(f));
    target = to_str(right);
    ll result = solve(0, 1, 0);

    memset(f, -1, sizeof(f));
    target = to_str(left - 1);

    cout << result - solve(0, 1, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;

    while (cases--)
        solve();

    return 0;
}