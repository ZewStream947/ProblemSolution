#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, dPos, rPos, minDis;
    char c;

    while (cin >> n, n)
    {
        dPos = rPos = -1;
        minDis = 2000001;

        for (int index = 0; index < n; ++index)
        {
            cin >> c;
            if (c == 'R')
                rPos = index;
            else if (c == 'D')
                dPos = index;
            else if (c == 'Z')
                rPos = dPos = index;
            if (rPos >= 0 && dPos >= 0)
                minDis = min(minDis, abs(rPos - dPos));
        }
        cout << minDis << '\n';
    }

    return 0;
}