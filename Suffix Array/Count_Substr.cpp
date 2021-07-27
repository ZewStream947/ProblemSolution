#include <cstdio>
#include <cstring>

struct pr
{
    int a, b;
};

const int MAXLEN = 3e5 + 2;

//SA vars
int len, suf[MAXLEN];
char str[MAXLEN];

//Substr vars
char sub[MAXLEN];
int sublen;

//Temp vars
int cnt[MAXLEN], tmp[MAXLEN], index;

void sort_suf(int cmp[], int lim)
{
    for (index = 0; index < lim; cnt[index++] = 0)
        ;
    for (index = 0; index < len; ++cnt[cmp[index++]])
        ;
    for (index = 1; index < lim; ++index)
        cnt[index] += cnt[index - 1];
    for (index = len - 1; index >= 0; --index)
        tmp[--cnt[cmp[suf[index]]]] = suf[index];
    for (index = 0; index < len; ++index)
        suf[index] = tmp[index];
}

void construct()
{
    len = strlen(str);
    str[len++] = '$';

    int cls[len], classes;
    { //Len 1
        for (index = 0; index < len; ++index)
        {
            suf[index] = index;
            cls[index] = str[index];
        }
        sort_suf(cls, 256);
        cls[suf[0]] = 0;
        classes = 1;
        for (index = 1; index < len; ++index)
        {
            if (str[suf[index]] != str[suf[index - 1]])
                ++classes;
            cls[suf[index]] = classes - 1;
        }
    }

    pr prev, curr;

    for (int l = 1; l < len; l <<= 1)
    {
        for (index = 0; index < len; ++index)
        {
            suf[index] -= l;
            if (suf[index] < 0)
                suf[index] += len;
        }
        sort_suf(cls, classes);
        tmp[suf[0]] = 0;
        classes = 1;
        for (index = 1; index < len; ++index)
        {
            prev = {cls[suf[index - 1]], cls[(suf[index - 1] + l) % len]};
            curr = {cls[suf[index]], cls[(suf[index] + l) % len]};
            if (prev.a != curr.a || prev.b != curr.b)
                ++classes;
            tmp[suf[index]] = classes - 1;
        }
        for (index = 0; index < len; ++index)
            cls[index] = tmp[index];
    }
}

bool good2(int idx1)
{
    int idx2 = 0;
    while (idx1 < len && idx2 < sublen && str[idx1] == sub[idx2])
        ++idx1, ++idx2;
    return (idx2 == sublen || str[idx1] > sub[idx2]);
}

bool good1(int idx1)
{
    int idx2 = 0;
    while (idx1 < len && idx2 < sublen && str[idx1] == sub[idx2])
        ++idx1, ++idx2;
    return (idx2 < sublen && str[idx1] > sub[idx2]);
}

int find(bool isUpper)
{
    int l = 0, r = len, mid;
    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        if (isUpper)
            good1(suf[mid]) ? r = mid : l = mid;
        else
            good2(suf[mid]) ? r = mid : l = mid;
    }
    return r;
}

int main()
{

    scanf("%s", &str);

    construct();

    int n;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%s", &sub);
        sublen = strlen(sub);
        printf("%d\n", find(1) - find(0));
    }

    return 0;
}
