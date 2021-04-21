#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int size, target;

    cin >> size >> target;

    int arr[size];

    bitset<1001> bit;
    bit.reset();
    bit[0] = 1;

    int result = size + 1;

    for (int l = 0, r = 0; r < size; ++r)
    {
        cin >> arr[r];
        bit |= (bit << arr[r]);
        bool isOk = false;
        if (bit[target])
        {
            bit.reset();
            bit[0] = 1;
            l = r;
            for (; !bit[target] && r - l + 1 <= result; --l)
                bit |= (bit << arr[l]);
            result = min(result, r - l);
        }
    }

    cout << ((result != size + 1) ? result : -1);
    return 0;
}