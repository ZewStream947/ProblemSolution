#include <cstdio>
#include <cstring>
#include <stack>

const int MAXLEN = 4e5 + 5;

char str[MAXLEN];
int lcp[MAXLEN], len;

int tmp[MAXLEN], cnt[MAXLEN];

void sort(int suf[], int cmp[], int lim)
{
    for (int index = 0; index < lim; cnt[index++] = 0)
        ;
    for (int index = 0; index < len; ++cnt[cmp[index++]])
        ;
    for (int index = 1; index < lim; ++index)
        cnt[index] += cnt[index - 1];
    for (int index = len - 1; index >= 0; --index)
        tmp[--cnt[cmp[suf[index]]]] = suf[index];
    for (int index = 0; index < len; ++index)
        suf[index] = tmp[index];
}

void construct()
{
    len = strlen(str);
    str[len++] = 0;

    int suf[len], cls[len], classes;

    {
        for (int index = 0; index < len; ++index)
            suf[index] = index, cls[index] = str[index];
        sort(suf, cls, 256);
        classes = 1;
        cls[suf[0]] = 0;
        for (int index = 1; index < len; ++index)
        {
            if (str[suf[index]] != str[suf[index - 1]])
                ++classes;
            cls[suf[index]] = classes - 1;
        }
    }

    struct item
    {
        int a, b;
    } prev, curr;

    for (int l = 1; l < len; l <<= 1)
    {
        for (int index = 0; index < len; ++index)
        {
            suf[index] -= l;
            if (suf[index] < 0)
                suf[index] += len;
        }
        sort(suf, cls, classes);
        tmp[suf[0]] = 0;
        classes = 1;
        for (int index = 1; index < len; ++index)
        {
            prev = {cls[suf[index - 1]], cls[(suf[index - 1] + l) % len]};
            curr = {cls[suf[index]], cls[(suf[index] + l) % len]};
            if (prev.a != curr.a || prev.b != curr.b)
                ++classes;
            tmp[suf[index]] = classes - 1;
        }

        for (int index = 0; index < len; ++index)
            cls[index] = tmp[index];
    }

    int j, k = 0;
    for (int index = 0; index < len; ++index)
    {
        if (cls[index] == len - 1)
        {
            lcp[cls[index]] = k = 0;
            continue;
        }
        j = suf[cls[index] + 1];
        while (index + k < len && j + k < len && str[index + k] == str[j + k])
            ++k;
        lcp[cls[index]] = k;
        if (k)
            --k;
    }

    lcp[len] = 0;
}

signed main()
{

    scanf("%s", str);
    construct();

    long long result = ((long long)len * (len - 1)) >> 1;

    std::stack<std::pair<int, int>> stk;

    for (int index = 0, val, pos, tmp, l; index <= len; ++index)
    {
        val = lcp[index], pos = index;
        while (!stk.empty() && stk.top().first >= val)
        {
            tmp = stk.top().first;
            pos = stk.top().second;
            stk.pop();
            l = index - pos;
            if (tmp > val)
                result += (long long)l * (l + 1) / 2 * (tmp - std::max(val, stk.empty() ? 0 : stk.top().first));
        }
        stk.emplace(val, pos);
    }
    printf("%lli", result);
    return 0;
}