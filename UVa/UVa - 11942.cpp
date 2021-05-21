#include <cstdio>

using namespace std;

int main()
{
    int TC, prev, curr;
    scanf("%d", &TC);
    printf("Lumberjacks:\n");
    while (TC--)
    {
        scanf("%d", &prev);
        bool dec = true, inc = true;
        for (int index = 1; index <= 9; ++index)
        {
            scanf("%d", &curr);
            if (curr > prev)
                dec = false;
            else if (curr < prev)
                inc = false;
            prev = curr;
        }

        if (inc || dec)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }

    return 0;
}