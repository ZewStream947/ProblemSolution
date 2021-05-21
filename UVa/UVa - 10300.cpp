#include <iostream>

using namespace std;

int main()
{

    int TC;

    scanf("%d", &TC);

    int n, a, b, c;

    long long result = 0;

    while (TC--)
    {
        scanf("%d", &n);
        result = 0;
        while (n--)
        {
            scanf("%d %d %d", &a, &b, &c);
            result += (long long)a * c;
        }
        printf("%lli\n", result);
    }

    return 0;
}