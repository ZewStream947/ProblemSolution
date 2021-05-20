#include <iostream>

using namespace std;

int main()
{
    int n;
    int total = 0, val;

    cin >> n;

    string str;

    while (n--)
    {
        cin >> str;
        if (str[0] == 'd')
            cin >> val, total += val;
        else
            cout << total << '\n';
    }

    return 0;
}