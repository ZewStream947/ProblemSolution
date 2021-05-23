#include <cstdio>

using namespace std;

int main()
{
    int index, n, m, maxApm, currApm, maximal, cnt = 1;

    bool isFirstLine = 1;

    int device[21];
    bool isTurnedOn[21];

    while (scanf("%d %d %d", &n, &m, &maxApm), n)
    {
        maximal = currApm = 0;

        for (index = 1; index <= n; ++index)
        {
            scanf("%d", device + index);
            isTurnedOn[index] = 0;
        }

        while (m--)
        {
            scanf("%d", &index);
            currApm += ((isTurnedOn[index]) ? -1 : 1) * device[index];
            if (currApm > maximal)
                maximal = currApm;
            isTurnedOn[index] = !isTurnedOn[index];
        }

        printf("Sequence %d\n", cnt++);

        if (maximal <= maxApm)
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maximal);
        else
            printf("Fuse was blown.\n\n");
    }

    return 0;
}