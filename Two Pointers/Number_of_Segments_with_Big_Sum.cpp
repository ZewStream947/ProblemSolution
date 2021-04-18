#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int size;
    long long target;

    cin >> size >> target;

    int arr[size];

    for (int index = 0; index < size; cin >> arr[index++])
        ;

    long long currSum = 0, result = 0;
    for (int r = 0, l = 0; r < size; ++r)
    {
        currSum += arr[r];
        while (currSum - arr[l] >= target)
            currSum -= arr[l++];
        if (currSum >= target)
            result += l + 1;
    }
    cout << result;
    return 0;
}