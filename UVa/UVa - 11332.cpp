#include <cstdio>

using namespace std;

int solve(int number)
{
    if (number <= 9)
        return number;
    int sum = 0;
    while (number)
    {
        sum += number % 10;
        number /= 10;
    }
    return solve(sum);
}

int main()
{
    int n;
    while (scanf("%d", &n), n)
        printf("%d\n", solve(n));

    return 0;
}