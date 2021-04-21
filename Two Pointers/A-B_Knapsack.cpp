#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m, target, wA, wB;

    cin >> n >> m >> target >> wA >> wB;

    int size = n + m, arr[size];

    for (int index = 0; index < n; cin >> arr[index++])
        ;
    for (int index = n; index < size; cin >> arr[index++])
        ;

    sort(arr, arr + n);
    sort(arr + n, arr + size, greater<int>());

    long long result = 0, currSum = 0, cnt = 0;

    for (int l = 0, r = 0; r < size; ++r)
    {
        currSum += arr[r];
        cnt += (r < n) ? wA : wB;
        if (cnt > target && currSum <= result)
            break;
        while (currSum > result && cnt > target)
        {
            cnt -= (l < n) ? wA : wB;
            currSum -= arr[l++];
        }
        result = max(result, currSum);
    }

    cout << result;
    return 0;
}