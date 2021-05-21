#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{

    int TC, cnt = 1, rlv;
    cin >> TC;
    string addr;
    map<int, vector<string>, greater<int>> order;
    while (TC--)
    {
        order.clear();
        for (int index = 0; index < 10; ++index)
            cin >> addr >> rlv,
                order[rlv].push_back(addr);
        cout << "Case #" << cnt++ << ":\n";
        for (string s : order[order.begin()->first])
            cout << s << '\n';
    }

    return 0;
}