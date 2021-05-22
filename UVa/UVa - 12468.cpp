#include <iostream>
using namespace std;
int main()
{
    int a, b;

    while (scanf("%d %d", &a, &b), (a >= 0 && b >= 0))
    {
        if (a > b)
            swap(a, b);
        printf("%d\n", min(b - a, a + 100 - b));
    }

    return 0;
}