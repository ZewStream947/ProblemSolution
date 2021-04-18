#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int size;

    cin >> size;

    long long arr[size], gcd = 0;

    int result = size + 1;

    for (int l = 0, r = 0; r < size; ++r)
    {
        cin >> arr[r];
        if (arr[r] == 1)
        {
            result = 1;
            break;
        }
        gcd = __gcd(gcd, arr[r]);
        if (gcd == 1)
        {
            int lo = l, hi = r;
            ll temp = arr[r];
            while (lo < hi)
            {
                temp = __gcd(temp, arr[--hi]);
                if (temp == 1)
                    break;
            }
            l = hi + 1;
            result = min(result, r - l + 2);
            gcd = temp;
        }
    }

    cout << ((result != size + 1) ? result : -1);

    return 0;
}