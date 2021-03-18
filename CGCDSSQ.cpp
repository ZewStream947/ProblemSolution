#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return (!b) ? a : gcd(b, a % b);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin >> size;

    unordered_map<int, long long> result;
    unordered_map<int, int> current, next;
    unordered_map<int, int>::iterator it;

    int x;

    while (size--)
    {
        next.clear();
        cin >> x;
        for (it = current.begin(); it != current.end(); ++it)
            next[gcd(it->first, x)] += it->second;
        ++next[x];

        current = next;

        for (it = current.begin(); it != current.end(); ++it)
            result[it->first] += it->second;
    }

    int queries;
    cin >> queries;
    while (queries--)
        cin >> x,
            cout << result[x] << '\n';

    return 0;
}