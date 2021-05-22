#include <iostream>
#include <vector>

using namespace std;

int main()
{
    short int TC, n, idx, result;

    cin >> TC;

    string str;

    vector<string> prev;

    while (TC--)
    {
        prev.clear();
        cin >> n;
        result = 0;

        while (n--)
        {
            cin >> str;
            if (str == "SAME")
                cin >> str >> idx,
                    str = prev[idx - 1];
            if (str == "LEFT")
                --result, prev.push_back(str);
            else if (str == "RIGHT")
                ++result, prev.push_back(str);
        }
        cout << result << '\n';
    }

    return 0;
}