#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    int TC = 1, cnt, l, r;
    while (cin >> str)
    {
        vector<vector<int>> arr(str.length(), vector<int>(2, 0));
        arr[0][0] = (str[0] == '0');
        arr[0][1] = (str[0] == '1');
        for (int index = 1; index < str.length(); ++index)
        {
            arr[index][0] += arr[index - 1][0] + (str[index] == '0');
            arr[index][1] += arr[index - 1][1] + (str[index] == '1');
        }
        cout << "Case " << TC++ << ":\n";
        cin >> cnt;
        while (cnt--)
        {
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            int num0 = arr[r][0] - (l > 0 ? arr[l - 1][0] : 0);
            int num1 = arr[r][1] - (l > 0 ? arr[l - 1][1] : 0);
            if (num0 == (r - l + 1) || num1 == (r - l + 1))
                cout
                    << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}