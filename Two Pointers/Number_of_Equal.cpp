#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m, x;

    cin >> n >> m;

    unordered_map<int, int> store;

    for (; n; cin >> x, ++store[x], --n)
        ;

    long long result = 0;
    while (m--)
    {
        cin >> x;
        result += (long long)store[x];
    }

    cout << result;
    return 0;
}