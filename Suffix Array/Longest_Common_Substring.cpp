#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 2 * (1e5) + 2;

void sort(int output[], int indexing[], int cmp[], int lim, int size)
{
    int index, cnt[lim] = {0};
    for (index = 0; index < size; ++index)
        ++cnt[cmp[indexing[index]]];
    for (index = 1; index < lim; ++index)
        cnt[index] += cnt[index - 1];
    for (index = size - 1; index >= 0; --index)
        output[--cnt[cmp[indexing[index]]]] = indexing[index];
}

void construct(int output[], char str[], int strLen, int LCP[])
{
    int indexing[strLen], cls[strLen], classes, index;

    { //Init
        for (index = 0; index < strLen; ++index)
            indexing[index] = index,
            cls[index] = str[index] - 95;
        sort(output, indexing, cls, 28, strLen);
        cls[output[0]] = classes = 0;
        for (index = 1; index < strLen; ++index)
            cls[output[index]] = (str[output[index - 1]] != str[output[index]]) ? ++classes : classes;
    }

    for (int l = 1; l < strLen; l *= 2)
    {
        for (index = 0; index < strLen; ++index)
        {
            indexing[index] = output[index] - l;
            if (indexing[index] < 0)
                indexing[index] += strLen;
        }
        sort(output, indexing, cls, classes + 1, strLen);
        indexing[output[0]] = classes = 0;
        for (index = 1; index < strLen; ++index)
        {
            pair<int, int> prev = {cls[output[index - 1]], cls[(output[index - 1] + l) % strLen]};
            pair<int, int> curr = {cls[output[index]], cls[(output[index] + l) % strLen]};
            indexing[output[index]] = (prev != curr) ? ++classes : classes;
        }
        copy(indexing, indexing + strLen, cls);
    }
    {
        int k = 0, p;

        for (index = 0; index < strLen; ++index)
            if (cls[index] != strLen - 1)
            {
                for (p = output[cls[index] + 1]; str[index + k] == str[p + k];)
                    ++k;
                LCP[cls[index]] = k;
                if (k)
                    --k;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[MAXSIZE];

    cin >> str;

    int str1Len = strlen(str);

    str[str1Len++] = 96;

    cin >> str + str1Len;

    int strLen = strlen(str);

    str[strLen++] = 95;
    str[strLen] = '\0';

    int suffix[strLen], lcp[strLen - 1];

    construct(suffix, str, strLen, lcp);

    int maxLen = -1, start;

    --str1Len;
    for (int index = 1; index < strLen; ++index)
        if ((suffix[index] > str1Len && suffix[index - 1] < str1Len) || (suffix[index] < str1Len && suffix[index - 1] > str1Len))
            if (lcp[index - 1] > maxLen)
            {
                maxLen = lcp[index - 1];
                start = suffix[index - 1];
            }

    for (; maxLen > 0; --maxLen)
        cout << str[start++];
    return 0;
}