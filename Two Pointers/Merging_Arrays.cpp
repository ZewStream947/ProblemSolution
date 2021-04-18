#include <bits/stdc++.h>

using namespace std;

int main()
{

    cin.tie(NULL)->sync_with_stdio(false);

    int aSize, bSize;
    cin >> aSize >> bSize;
    int a[aSize], b[bSize], c[aSize + bSize];
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    merge(a, a + aSize, b, b + bSize, c);
    for (int &x : c)
        cout << x << ' ';
    return 0;
}