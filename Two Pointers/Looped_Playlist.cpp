#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    short int size;
    long long target;
    cin >> size >> target;

    int arr[size];

    long long sum = 0;

    for (int index = 0; index < size; ++index)
        cin >> arr[index], sum += arr[index];

    long long circle = target / sum;
    target %= sum;

    pair<short int, short int> result = {1001, -1};

    sum = 0;
    for (short int l = 0, r = 0, len = 0; l < size; sum -= arr[l++], --len)
    {
        while (len < result.first && sum < target)
        {
            if (r == size)
                r = 0;
            sum += arr[r++];
            ++len;
        }
        result = min(result, {len, l + 1});
    }

    cout << result.second << ' ' << (long long)result.first + circle * size;
    return 0;
}