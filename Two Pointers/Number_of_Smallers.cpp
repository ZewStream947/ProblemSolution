#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    int arr[n], index;

    for (index = 0; index < n; ++index)
        cin >> arr[index];

    index = 0;
    for (int x; m; --m)
    {
        cin >> x;
        while (index < n && arr[index] < x)
            ++index;
        cout << index << ' ';
    }

    return 0;
}