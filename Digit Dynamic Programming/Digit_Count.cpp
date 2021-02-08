#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<int> digit;

int len;

ll solve(int index, int prev)
{
    if (index == len)
        return 1;

    ll ret = 0;
    for (auto val : digit)
        if (abs(prev - val) <= 2 || prev == -1)
            ret += solve(index + 1, val);

    return ret;
}

void solve()
{
    int size;
    cin >> size >> len;
    digit.clear();

    for (int i = 0, x; i < size; ++i)
    {
        cin >> x;
        digit.push_back(x);
    }

    cout << solve(0, -1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases;
    cin >> cases;
    for (int x = 1; x <= cases; ++x)
    {
        cout << "Case " << x << ": ";
        solve();
    }
    return 0;
}
