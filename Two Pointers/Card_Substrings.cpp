#include <iostream>

using namespace std;

bool check(int source[], int cmp[])
{
    for (int x = 0; x < 26; ++x)
        if (source[x] > cmp[x])
            return false;
    return true;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int len, cards;
    char str[int(1e5) + 5];

    cin >> len >> cards >> str;

    int card[26] = {0}, cnt[26] = {0};

    for (char x; cards; --cards)
        cin >> x, ++card[x - 97];

    long long result = 0;

    for (int l = 0, r = 0; r < len; ++r)
    {
        ++cnt[str[r] - 97];
        while (!check(cnt, card))
            --cnt[str[l++] - 97];
        result += r - l + 1;
    }

    cout << result;

    return 0;
}