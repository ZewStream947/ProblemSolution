#include <iostream>

using namespace std;

int main()
{
    int TC, n;
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d", &n);
        printf("%d\n", abs(((((n * 63) + 7492) * 5 - 498) % 100) / 10));
    }

    return 0;
}