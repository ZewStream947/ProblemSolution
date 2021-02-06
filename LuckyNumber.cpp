#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

ll f[20][2][83];
vector<int> digit;
vector<int> trace(20, 0);
int numLen, k;

void init(int number)
{
    memset(f, -1, sizeof(f));

    digit.clear();

    while (number)
    {
        digit.push_back(number % 10);
        number /= 10;
    }

    reverse(digit.begin(), digit.end());

    numLen = digit.size();
}

bool check()
{
    int index = 0;
    while (trace[index] == 0 && index < numLen)
        ++index;
    if (index < numLen)
    {
        ll number = trace[index];
        for (++index; index < numLen; ++index)
            number = number * 10 + trace[index];
        return (number % k == 0);
    }
    return false;
}

ll count(int index, bool smaller, int mod)
{
    if (index == numLen)
        return ((mod == 0 && check()) ? 1 : 0);

    if (f[index][smaller][mod] != -1)
        return f[index][smaller][mod];

    int lim = (smaller) ? digit[index] : 9;

    ll ret_count = 0;

    for (int val = 0; val <= lim; ++val)
    {
        bool next_smaller = ((val < digit[index]) ? 0 : smaller);
        trace[index] = val;
        ret_count += count(index + 1, next_smaller, (mod + val) % k);
    }

    f[index][smaller][mod] = ret_count;

    return ret_count;
}

int main()
{
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        ll left, right;
        cin >> left >> right >> k;

        init(left - 1);
        ll count_left = count(0, 1, 0);

        init(right);
        ll count_right = count(0, 1, 0);

        cout << count_right - count_left << endl;
    }
    return 0;
}
