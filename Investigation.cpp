#include <bits/stdc++.h>

using namespace std;

int k;
int f[10][2][100][100];

string target;

string to_str(int number)
{
    stringstream str;
    str << number;
    return str.str();
}

int solve(int index, bool tight, int mod, int mod_prod)
{
    if (index == target.length())
        return (mod == 0 && mod_prod == 0);

    if (f[index][tight][mod][mod_prod] != -1)
        return f[index][tight][mod][mod_prod];

    int lim = (tight) ? target[index] - '0' : 9;

    int count = 0;

    for (int val = 0; val <= lim; ++val)
        count += solve(index + 1, tight && val == lim, (mod + val) % k, (((mod_prod * 10) % k) + val) % k);

    return f[index][tight][mod][mod_prod] = count;
}

void solve()
{
    int left, right;
    cin >> left >> right >> k;

    if (k > 99)
    {
        cout << 0 << endl;
        return;
    }

    memset(f, -1, sizeof(f));
    target = to_str(right);
    int result = solve(0, 1, 0, 0);

    memset(f, -1, sizeof(f));
    target = to_str(left - 1);
    cout << result - solve(0, 1, 0, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tcase;
    cin >> tcase;
    for (int x = 1; x <= tcase; ++x)
    {
        cout << "Case " << x << ": ";
        solve();
    }
    return 0;
}