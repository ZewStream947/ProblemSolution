#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char str[51];
    while (scanf("%s", &str) && strcmp(str, "#"))
    {
        if (next_permutation(str, str + strlen(str)))
            printf("%s\n", str);
        else
            printf("No Successor\n");
    }

    return 0;
}