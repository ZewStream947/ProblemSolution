#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool check(ll num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        if (sum > 10)
            return false;
        num /= 10;
    }
    return (sum == 10);
}

ll solve(int k)
{
    int num = 19, count = 1;
    while (count < k)
    {
        num += 9;
        if (check(num))
            ++count;
    }

    return num;
}

int main()
{
    int k;
    cin >> k;
    cout << solve(k);
    return 0;
}