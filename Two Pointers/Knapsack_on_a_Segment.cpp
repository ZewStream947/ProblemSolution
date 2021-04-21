#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int size, target;

    cin >> size >> target;

    pair<int, int> arr[size];

    for (pair<int, int> &index : arr)
        cin >> index.first;
    long long currCost = 0, maxCost = 0, total = 0;
    for (int l = 0, r = 0; r < size; ++r)
    {
        cin >> arr[r].second;
        total += arr[r].first;
        currCost += arr[r].second;
        while (total > target)
        {
            total -= arr[l].first;
            currCost -= arr[l++].second;
        }
        maxCost = max(maxCost, currCost);
    }

    cout << maxCost;
    return 0;
}