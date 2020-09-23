#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    //Part a
    int n;
    cin >> n;

    int arr[n + 2];
    for (int index = 0; index < n; ++index)
        cin >> arr[index];

    //Part b
    for (int index = 0; index < n; ++index)
        cout << arr[index] << ' ';
    cout << endl;

    //Part c
    int x, k;
    cin >> x >> k;

    for (int index = n; index >= k; --index)
        arr[index] = arr[index - 1];

    arr[k - 1] = x;
    ++n;

    for (int index = 0; index < n; ++index)
        cout << arr[index] << ' ';
    cout << endl;

    //Part d
    sort(arr, arr + n, greater<int>());

    for (int index = 0; index < n; ++index)
        cout << arr[index] << ' ';
    cout << endl;

    //Part e
    int y;
    cin >> y;
    int index = n - 1;

    while (arr[index] < y)
        --index;

    k = index + 1;

    for (index = n; index > k; --index)
        arr[index] = arr[index - 1];
    arr[k] = y;
    ++n;

    for (int index = 0; index < n; ++index)
        cout << arr[index] << ' ';

    cout << endl;

    return 0;
}