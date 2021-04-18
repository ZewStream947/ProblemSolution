#include <iostream>

using namespace std;

int cnt[int(1e5) + 1];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int size, target;

    cin >> size >> target;

    int arr[size];
    for (int index = 0; index < size; cin >> arr[index++])
        ;
    int currCnt = 0;
    long long result = 0;
    for (int l = 0, r = 0; r < size; ++r)
    {
        if (++cnt[arr[r]] == 1)
            ++currCnt;
        while (currCnt > target)
            if (--cnt[arr[l++]] == 0)
                --currCnt;
        result += r - l + 1;
    }
    cout << result;
    return 0;
}