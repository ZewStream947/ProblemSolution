#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long

using namespace std;

vector<int> digit;
int size;
int f[20][2][180];

void init(ll number)
{
    memset(f, -1, sizeof(f));
    digit.clear();
    while (number) {
        digit.push_back(number % 10);
        number /= 10;
    }
    size = digit.size();
    reverse(digit.begin(), digit.end());
}

ll getSum(int index, bool smaller, ll sum)
{
    if (index == size)
        return sum;
    
    if (f[index][smaller][sum] != -1)
        return f[index][smaller][sum];
    
    int lim = (smaller) ? digit[index] : 9;
    ll ret_sum = 0;

    for (int val = 0; val <= lim; ++val) {
        bool next_smaller = (val < digit[index]) ? 0 : smaller;
        ret_sum += getSum(index + 1, next_smaller, sum + val);
    }

    f[index][smaller][sum] = ret_sum;
    
    return ret_sum;
}

int main()
{
    ll left, right;
     
    cin >> left >> right;
    while (left != -1 and right != -1) {
        init(left - 1);
        ll sumLeft = getSum(0, 1, 0);

        init(right);
        ll sumRight = getSum(0, 1, 0);

        cout << sumRight - sumLeft << endl;
        cin >> left >> right;
    }
    
    return 0;
}
