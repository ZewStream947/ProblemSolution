#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXSIZE = 4e5 + 1;

int **cls, *log, strLen;

void compute_log(int size)
{
    log = new int[size + 1];
    log[1] = 0;
    for (int index = 2; index <= size; ++index)
        log[index] = log[index / 2] + 1;
}

void sort(int output[], int cmp[], int indexing[], int size, int lim)
{
    int index, cnt[lim] = {0};
    for (index = 0; index < size; ++index)
        ++cnt[cmp[indexing[index]]];
    for (index = 1; index < lim; ++index)
        cnt[index] += cnt[index - 1];
    for (index = size - 1; index >= 0; --index)
        output[--cnt[cmp[indexing[index]]]] = indexing[index];
}

void process(char str[], int len)
{
    int index, classes, indexing[len], suffix[len];
    { //Init
        compute_log(len);
        classes = log[len] + 1;
        cls = new int *[classes];
        for (index = 0; index <= classes; ++index)
            cls[index] = new int[len];
    }
    {
        for (index = 0; index < len; ++index)
            indexing[index] = index,
            cls[0][index] = str[index] - 33;
        sort(suffix, cls[0], indexing, len, 95);
        cls[0][suffix[0]] = classes = 0;
        for (index = 1; index < len; ++index)
            cls[0][suffix[index]] = (str[suffix[index - 1]] != str[suffix[index]]) ? ++classes : classes;
    }

    for (int k = 0; k <= log[len]; ++k)
    {
        for (index = 0; index < len; ++index)
        {
            indexing[index] = suffix[index] - (1 << k);
            if (indexing[index] < 0)
                indexing[index] += len;
        }
        sort(suffix, cls[k], indexing, len, classes + 1);
        if (k < log[len])
        {
            cls[k + 1][suffix[0]] = classes = 0;
            for (index = 1; index < len; ++index)
            {
                pair<int, int> prev = {cls[k][suffix[index - 1]], cls[k][(suffix[index - 1] + (1 << k)) % len]};
                pair<int, int> curr = {cls[k][suffix[index]], cls[k][(suffix[index] + (1 << k)) % len]};
                cls[k + 1][suffix[index]] = (prev != curr) ? ++classes : classes;
            }
        }
    }
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    int minLen = min(a.second, b.second);
    int lg = log[minLen];
    pair<int, int> x = {cls[lg][a.first - 1], cls[lg][a.first - 1 + minLen - (1 << lg)]};
    pair<int, int> y = {cls[lg][b.first - 1], cls[lg][b.first - 1 + minLen - (1 << lg)]};
    return (x != y) ? x < y : ((a.second != b.second) ? a.second < b.second : a.first < b.first);
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    char str[MAXSIZE];

    cin >> str;

    strLen = strlen(str);

    process(str, strLen);

    {
        int subSize;

        cin >> subSize;

        pair<int, int> sub[subSize];
        int index;

        for (index = 0; index < subSize; ++index)
        {
            cin >> sub[index].first >> sub[index].second;
            sub[index].second = sub[index].second - sub[index].first + 1;
        }

        sort(sub, sub + subSize, compare);
        for (index = 0; index < subSize; ++index)
            cout << sub[index].first << ' ' << sub[index].first + sub[index].second - 1 << '\n';
    }
    return 0;
}