#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int *suffix;
int len = 0;

void count_sort(int source[], int arr[], int len)
{
    int index, output[len], cnt[len] = {0};
    for (index = 0; index < len; ++index)
        ++cnt[arr[index]];
    for (index = 1; index < len; ++index)
        cnt[index] += cnt[index - 1];
    for (index = len - 1; index >= 0; --index)
        output[--cnt[arr[source[index]]]] = source[index];
    copy(output, output + len, source);
}

void buildSA(char str[])
{
    suffix = (int *)malloc(len * sizeof(int));
    int cls[len], cls_temp[len], index;
    { //Init
        pair<char, int> arr[len];
        for (index = 0; index < len; ++index)
            arr[index] = {str[index], index};
        sort(arr, arr + len);
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
}

int upper_bound(char source[], char target[])
{
    int l = 1, r = len, mid;
    int sub_len = strlen(target);
    while (l < r)
    {
        mid = (l + r) >> 1;
        char tmp[sub_len];
        memcpy(tmp, &source[suffix[mid]], sub_len);
        tmp[sub_len] = '\0';
        if (strcmp(target, tmp) >= 0)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int lower_bound(char source[], char target[])
{
    int l = 1, r = len, mid;
    int sub_len = strlen(target);
    while (l < r)
    {
        mid = (l + r) >> 1;
        char tmp[sub_len];
        memcpy(tmp, &source[suffix[mid]], sub_len);
        tmp[sub_len] = '\0';
        if (strcmp(target, tmp) <= 0)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);

    char str[300001];
    scanf("%s", str);

    len = strlen(str);
    str[len++] = '$';
    str[len] = '\0';

    buildSA(str);
    {
        int t;
        scanf("%d", &t);
        char s[300001];
        while (t--)
        {
            scanf("%s", s);
            cout << upper_bound(str, s) - lower_bound(str, s) << endl;
        }
    }

    return 0;
}