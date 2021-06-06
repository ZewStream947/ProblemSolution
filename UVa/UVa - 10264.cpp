#include <cstdio>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{

    int n;
    while (scanf("%d", &n) == 1)
    {
        int size = 1 << n;
        int weight[size];

        for (int index = 0; index < size; scanf("%d", weight + index++))
            ;

        int potencies[size] = {0};

        for (int corner = 0; corner < size; ++corner)
            for (int pos = 0; pos < n; ++pos)
                potencies[corner] += weight[corner ^ (1 << pos)];

        int result = 0;
        for (int corner = 0; corner < size; ++corner)
            for (int pos = 0; pos < n; ++pos)
                result = max(result, potencies[corner] + potencies[corner ^ (1 << pos)]);
        printf("%d\n", result);
    }

    return 0;
}