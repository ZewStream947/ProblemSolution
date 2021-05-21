#include <iostream>

using namespace std;

int main()
{

    int TC;
    cin >> TC;
    string str;

    while (TC--)
    {
        cin >> str;
        if (str == "1" || str == "4" || str == "78")
            cout << "+\n";
        else if (str.length() >= 2 && str[str.length() - 1] == '5' && str[str.length() - 2] == '3')
            cout << "-\n";
        else if (str.length() >= 2 && str[0] == '9' && str[str.length() - 1] == '4')
            cout << "*\n";
        else
            cout << "?\n";
    }

    return 0;
}