#include <cstdio>

int main()
{
    int TC, cnt = 1;
    char cmd[100001];
    scanf("%d", &TC);

    while (TC--)
    {
        int arr[100] = {0};
        int pointer = 0;

        scanf("%s", &cmd);

        for (int index = 0; cmd[index]; ++index)
            if (cmd[index] == '<')
            {
                if (--pointer == -1)
                    pointer = 99;
            }
            else if (cmd[index] == '>')
            {
                if (++pointer == 100)
                    pointer = 0;
            }
            else if (cmd[index] == '+')
            {
                if (++arr[pointer] == 256)
                    arr[pointer] = 0;
            }
            else if (cmd[index] == '-')
                if (--arr[pointer] == -1)
                    arr[pointer] = 255;

        printf("Case %d:", cnt++);
        for (int index = 0; index <= 99; ++index)
            printf(" %02X", arr[index]);
        printf("\n");
    }

    return 0;
}