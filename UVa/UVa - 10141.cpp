#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, cnt = 1;

    string result, temp;
    double maxCom, minPrice, currCom, currPrice;

    bool isFirst = 1;

    while (cin >> n >> p, n)
    {
        maxCom = INT_MIN;
        minPrice = INT_MAX;
        result = "";
        for (int c = 0; c < n; ++c)
            cin.ignore(), getline(cin, temp);
        while (p--)
        {

            //cin.ignore();
            getline(cin, temp);
            cin >> currPrice >> currCom;
            if (currCom > maxCom || (currCom == maxCom && currPrice < minPrice))
            {
                maxCom = currCom;
                minPrice = currPrice;
                result = temp;
            }

            while (currCom--)
                cin.ignore(), getline(cin, temp);
        }
        if (isFirst)
            isFirst = 0;
        else
            cout << '\n';
        cout << "RFP #" << cnt++ << '\n'
             << result << "\n";
    }

    return 0;
}