#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int len, result = 0, cntA = 0, cntB = 0;
    long long target, current = 0;

    string str;

    cin >> len >> target >> str;

    for (int l = 0, r = 0; r < len; ++r)
    {
        if (str[r] == 'a')
            ++cntA;
        else if (str[r] == 'b')
            current += cntA, ++cntB;
        while (current > target)
        {
            if (str[l] == 'a')
                --cntA, current -= cntB;
            else if (str[l] == 'b')
                --cntB;
            ++l;
        }
        result = max(result, r - l + 1);
    }

    cout << result;

    return 0;
}