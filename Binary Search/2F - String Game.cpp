#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char t[200001], p[200001];
int *idx, len;
vector<bool> check;

bool good(int pos)
{
    check.assign(len, 1);
    for (int index = 0; index <= pos; ++index)
        check[idx[index]] = 0;
    int pIndex = 0;
    for (int index = 0; index < len && p[pIndex] != '\0'; ++index)
        if (check[index] && t[index] == p[pIndex])
            ++pIndex;
    return p[pIndex] == '\0';
}

int main()
{
    gets(t), gets(p);

    idx = new int[len = strlen(t)];

    for (int index = 0; index < len; ++index)
        scanf("%d", &idx[index]), --idx[index];

    int mid, l = -1, r = len - 1;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        good(mid) ? l = mid : r = mid;
    }

    printf("%d", l + 1);

    return 0;
}