#include <bits/stdc++.h>

using namespace std;

int f[10][100][100];
int number[20];

bool isPrime(int num)
{
    if (num < 2)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int x = 5; x * x <= num; x += 6)
        if (num % x == 0 || num % (x + 2) == 0)
            return false;
    return true;
}

int countOn(int index, bool tight, int sum_even, int sum_odd)
{
    if (index == 0)
        return isPrime(sum_odd - sum_even);

    if (!tight && f[index][sum_even][sum_odd] >= 0)
        return f[index][sum_even][sum_odd];

    int lim = tight ? number[index] : 9;

    int count = 0;

    for (int val = 0; val <= lim; ++val)
        if (index & 1)
            count += countOn(index - 1, tight && (val == lim), sum_even + val, sum_odd);
        else
            count += countOn(index - 1, tight && (val == lim), sum_even, sum_odd + val);

    if (!tight)
        f[index][sum_even][sum_odd] = count;

    return count;
}

int solve(int num)
{
    int len = 0;

    while (num)
    {
        number[++len] = num % 10;
        num /= 10;
    }

    return countOn(len, true, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cases, left, right;
    cin >> cases;

    memset(f, -1, sizeof(f));

    while (cases--)
    {
        cin >> left >> right;
        cout << solve(right) - solve(left - 1) << endl;
    }

    return 0;
}