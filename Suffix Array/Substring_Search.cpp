
#include <algorithm>
#include <cstring>

using namespace std;

int *suffix;
int len = -1;

void count_sort(int suffix[], int cls[])
{
    int cnt[len] = {0}, output[len], index;
    for (index = 0; index < len; ++index)
        ++cnt[cls[index]];
    for (index = 1; index < len; ++index)
        cnt[index] += cnt[index - 1];
    for (index = len - 1; index >= 0; --index)
        output[--cnt[cls[suffix[index]]]] = suffix[index];
    copy(output, output + len, suffix);
}

void buildSA(char str[])
{
    int index;
    suffix = (int *)malloc(len * sizeof(int));

    int cls[len], cls_temp[len];
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
        count_sort(suffix, cls);
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

bool bin_search(char source[], char str[], int l, int r, int sub_len)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        char sub[sub_len];
        memcpy(sub, &source[suffix[mid]], sub_len);
        sub[sub_len] = '\0';

        int cmp = strcmp(sub, str);
        if (cmp == 0)
            return true;
        else if (cmp < 0)
            l = mid + 1;
        else
            r = mid;
    }
    return false;
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

    { //Solve
        int t;
        scanf("%d", &t);
        char s[300001];
        while (t--)
        {
            scanf("%s", s);
            cout << (bin_search(str, s, 1, len, strlen(s)) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}