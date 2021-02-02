#include <iostream>
#include <vector>
#include <cstring>

#define ll long long

ll dp[18][180];

using namespace std;

void getDigits(int number, vector<int>& digits)
{
    while (number) {
        digits.push_back(number % 10);
        number /= 10;
    }
} 

ll compute(int index, int tight, ll sum, vector<int> digits) {
    if (index == -1)
        return sum;

    if (dp[index][sum] != -1 && tight == 0)
        return dp[index][sum];

    ll retVal = 0;
    
    int end = (tight) ? digits[index] : 9;

    for (int val = 0; val <= end; ++val) {
        int newTight = (val == digits[index]) ? tight : 0;
        retVal += compute(index - 1, newTight, sum + val, digits);
    }
    
    if (!tight)
        dp[index][sum] = retVal;
    
    return retVal;
}

ll getSum(ll left, ll right) {
    memset(dp, -1, sizeof(dp));
    
    vector<int> digits;
    getDigits(left - 1, digits);
    ll sumLeft = compute(digits.size() - 1, 1, 0, digits);
    
    digits.clear();
    
    getDigits(right, digits);
    ll sumRight = compute(digits.size() - 1, 1, 0, digits);

    return sumRight - sumLeft;
}

int main()
{
    ll left, right;
    cin >> left >> right;

    cout << getSum(left, right);
    return 0;
}
