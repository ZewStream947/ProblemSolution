#include <iostream>

using namespace std;

int main()
{
    int cnt = 1;
    string name;
    while (cin >> name, name[0] != '*')
    {
        cout << "Case " << cnt++ << ": ";
        if (name[0] == 'H')
            cout << "Hajj-e-Akbar\n";
        else
            cout << "Hajj-e-Asghar\n";
    }
    return 0;
}