#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int size;
    ll target;
    cin >> size >> target;

    int arr[size];
    ll result = 0, currSum = 0;
    for (int l = 0, r = 0; r < size; ++r)
    {
        cin >> arr[r];
        currSum += arr[r];
        while (currSum > target)
            currSum -= arr[l++];
        result += (long long)(r - l + 1) * (r - l + 2) / 2;
    }

    cout << result;
    return 0;
}