#include <iostream>

using namespace std;

int main()
{
    string str, next;
    int cnt, len;
    while (cin >> str, str != "END")
    {
        cnt = 1;
        next = to_string(str.length());
        while (str != next)
        {
            str = next;
            next = to_string(str.length());
            ++cnt;
        }
        cout << cnt << "\n";
    }

    return 0;
}