#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int size, target;

    cin >> size >> target;

    int distance[size];

    long long result = 0;

    for (int l = 0, r = 0; r < size; ++r)
    {
        cin >> distance[r];
        while (l < r && distance[r] - distance[l] > target)
        {
            result += size - r;
            ++l;
        }
    }

    cout << result;
    return 0;
}