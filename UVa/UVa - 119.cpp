#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n;

    string giver, receiver;
    int money, receivers;

    unordered_map<string, int> list;
    vector<string> order;

    bool isFirst = 1;

    while (cin >> n)
    {
        list.clear();
        order.clear();
        for (int index = 0; index < n; ++index)
            cin >> giver, order.push_back(giver);

        while (n--)
        {
            cin >> giver >> money >> receivers;
            if (receivers > 0)
            {
                money /= receivers;
                list[giver] -= money * receivers;
                while (receivers--)
                    cin >> receiver,
                        list[receiver] += money;
            }
        }
        if (isFirst)
            isFirst = false;
        else
            cout << '\n';
        for (string s : order)
            cout << s << ' ' << list[s] << '\n';
    }

    return 0;
}