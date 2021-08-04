#include <cstdio>
#include <stack>

using namespace std;

const int MAXLEN = 15e4 + 5;

int arr[MAXLEN], lcp[MAXLEN], len;

//temp
int cnt[MAXLEN], tmp[MAXLEN];

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
    arr[len++] = 0;

    int cls[len], suf[len], classes;

    {
        for (int index = 0; index < len; ++index)
            cls[index] = arr[index], suf[index] = index;
        sort(suf, cls, 11);
        cls[suf[0]] = 0;
        classes = 1;
        for (int index = 1; index < len; ++index)
        {
            if (arr[suf[index]] != arr[suf[index - 1]])
                ++classes;
            cls[suf[index]] = classes - 1;
        }
    }

    pair<int, int> prev, curr;
    for (int l = 1; l < len; l <<= 1)
    {
        for (int index = 0; index < len; ++index)
        {
            suf[index] -= l;
            if (suf[index] < 0)
                suf[index] += len;
        }
        sort(suf, cls, classes);
        classes = 1;
        tmp[suf[0]] = 0;
        for (int index = 1; index < len; ++index)
        {
            prev = {cls[suf[index - 1]], cls[(suf[index - 1] + l) % len]};
            curr = {cls[suf[index]], cls[(suf[index] + l) % len]};
            classes += prev != curr;
            tmp[suf[index]] = classes - 1;
        }
        for (int index = 0; index < len; ++index)
            cls[index] = tmp[index];
    }

    for (int index = 0, j, k = 0; index < len; ++index)
    {
        if (cls[index] == len - 1)
        {
            lcp[len - 1] = k = 0;
            continue;
        }
        j = suf[cls[index] + 1];
        while (j + k < len && index + k < len && arr[index + k] == arr[j + k])
            ++k;
        lcp[cls[index]] = k;
        if (k)
            --k;
    }
    lcp[len] = 0;

    { //Solving
        stack<pair<int, int>> stk;

        long long mxpro = len - 1;
        int mxlen = len - 1, stpos = 0;

        for (int index = 0, val, pos, tmp, v; index <= len; ++index)
        {
            val = lcp[index], pos = index;
            while (!stk.empty() && stk.top().first >= val)
            {
                v = stk.top().first;
                pos = stk.top().second;
                stk.pop();
                tmp = index - pos + 1;
                if (v > val)
                    if ((long long)v * tmp > (long long)mxpro)
                    {
                        mxpro = (long long)v * tmp;
                        mxlen = v;
                        stpos = suf[pos];
                    }
            }
            stk.emplace(val, pos);
        }

        printf("%lli\n%d\n", mxpro, mxlen);
        for (int index = stpos; index < stpos + mxlen; printf("%d ", arr[index++]))
            ;
    }
}

int main()
{

    int m;
    scanf("%d %d", &len, &m);

    for (int index = 0; index < len; scanf("%d", arr + index++))
        ;

    construct();

    return 0;
}