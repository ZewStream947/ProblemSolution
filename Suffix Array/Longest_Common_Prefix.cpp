#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_LEN 400001

using namespace std;

int *suffix, *lcp;
int len = 0;

void count_sort(int source[], int cmp[], int len)
{
    int output[len], cnt[len] = {0}, index;
    for (index = 0; index < len; ++index)
        ++cnt[cmp[index]];
    for (index = 1; index < len; ++index)
        cnt[index] += cnt[index - 1];
    for (index = len - 1; index >= 0; --index)
        output[--cnt[cmp[source[index]]]] = source[index];
    copy(output, output + len, source);
}

void build(char str[])
{
    {
        len = strlen(str);
        lcp = (int *)malloc(len * sizeof(int));
        str[len++] = '$';
        str[len] = '\0';
        suffix = (int *)malloc(len * sizeof(int));
    }
    int cls[len], cls_temp[len], index;

    {
        pair<char, int> arr[len];
        for (index = 0; index < len; ++index)
            arr[index] = {str[index], index};
        sort(arr, arr + len, [](pair<char, int> l, pair<char, int> r) {
            return l.first < r.first;
        });
        for (index = 0; index < len; ++index)
            suffix[index] = arr[index].second;
        cls[suffix[0]] = 0;
        for (index = 1; index < len; ++index)
            cls[suffix[index]] = cls[suffix[index - 1]] + (arr[index - 1].first != arr[index].first);
    }

    for (int gap = 1; gap < len; gap *= 2)
    {
        for (index = 0; index < len; ++index)
            suffix[index] = (suffix[index] - gap + len) % len;
        count_sort(suffix, cls, len);
        cls_temp[suffix[0]] = 0;
        for (index = 1; index < len; ++index)
        {
            pair<int, int> prev = {cls[suffix[index - 1]], cls[(suffix[index - 1] + gap) % len]};
            pair<int, int> curr = {cls[suffix[index]], cls[(suffix[index] + gap) % len]};
            cls_temp[suffix[index]] = cls_temp[suffix[index - 1]] + (prev != curr);
        }
        copy(cls_temp, cls_temp + len, cls);
    }

    { //build lcp
        int k = 0;
        for (index = 0; index < len; ++index)
            if (cls[index] != len - 1)
            {
                for (int p = suffix[cls[index] + 1]; str[index + k] == str[p + k];)
                    ++k;
                lcp[cls[index]] = k;
                if (k)
                    --k;
            }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char str[MAX_LEN];
    cin >> str;

    build(str);
    for (int index = 0; index < len; ++index)
        cout << suffix[index] << ' ';
    cout << endl;
    for (int index = 0; index < len - 1; ++index)
        cout << lcp[index] << ' ';
    return 0;
}