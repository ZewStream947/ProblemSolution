#include <bits/stdc++.h>

using namespace std;

int getDeg(int a, int b, bool f)
{
    a = (f) ? a - b : b - a;
    if (a <= 0)
        a += 40;
    return a * 9;
}

int main()
{
    int a, b, c, d;
    while (scanf("%d %d %d %d", &a, &b, &c, &d), (a || b || c || d))
        printf("%d\n", 1080 + getDeg(a, b, 1) + getDeg(b, c, 0) + getDeg(c, d, 1));

    return 0;
}