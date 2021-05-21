#include <cstdio>

using namespace std;

int main()
{
    int B, N;

    while (scanf("%d %d", &B, &N), B || N)
    {
        int moneyRes[B + 1], bankA, bankB, val;
        for (int index = 1; index <= B; ++index)
            scanf("%d", moneyRes + index);
        for (int index = 1; index <= N; ++index)
        {
            scanf("%d %d %d", &bankA, &bankB, &val);
            moneyRes[bankA] -= val;
            moneyRes[bankB] += val;
        }
        bool isOk = true;
        for (int index = 1; index <= B; ++index)
            if (moneyRes[index] < 0)
            {
                isOk = false;
                break;
            }

        if (isOk)
            printf("S\n");
        else
            printf("N\n");
    }

    return 0;
}