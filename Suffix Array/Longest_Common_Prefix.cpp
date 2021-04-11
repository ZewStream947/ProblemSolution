#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 4 * (1e5) + 1;

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

void construct_suffix_array(int output[], char str[], int strLen)
{
    int indexing[strLen], cls[strLen], classes, index;

    { //Init
        for (index = 0; index < strLen; ++index)
            indexing[index] = index,
            cls[index] = str[index] - 96;
        sort(output, indexing, cls, 27, strLen);
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
}

void construct_lcp(int output[], char str[], int suffix[], int strLen)
{
    int index, rank[strLen];
    for (index = 0; index < strLen; ++index)
        rank[suffix[index]] = index;

    int k = 0, p;

    for (index = 0; index < strLen; ++index)
        if (rank[index] != strLen - 1)
        {
            for (p = suffix[rank[index] + 1]; str[index + k] == str[p + k];)
                ++k;
            output[rank[index]] = k;
            if (k)
                --k;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[MAXSIZE];

    cin >> str;

    int strLen = strlen(str);

    str[strLen++] = 96;
    str[strLen] = '\0';

    int suffix[strLen];

    construct_suffix_array(suffix, str, strLen);

    int lcp[strLen - 1];

    construct_lcp(lcp, str, suffix, strLen);
    return 0;
}