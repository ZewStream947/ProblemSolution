#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool check(string str)
{
    int cnt[3] = {0};
    for (char c : str)
        ++cnt[c - 'A'];
    int maxE = max(cnt[0], max(cnt[1], cnt[2]));
    if (maxE != str.length() / 2)
        return false;

    char opening = '\0', closing = '\0';
    if (cnt[str[0] - 'A'] == maxE)
        opening = str[0];
    else
    {
        closing = str[str.length() - 1];
        if (cnt[closing - 'A'] != maxE)
            return false;
    }

    stack<char> stk;
    if (opening != '\0')
    {
        for (int index = 0; index < str.length(); ++index)
            if (str[index] == opening)
                stk.push(opening);
            else if (stk.empty())
                return false;
            else
                stk.pop();
    }
    else
        for (int index = str.length() - 1; index >= 0; --index)
            if (str[index] == closing)
                stk.push(closing);
            else if (stk.empty())
                return false;
            else
                stk.pop();

    return stk.empty();
}

int main()
{
    int tcases;
    cin >> tcases;
    while (tcases--)
    {
        string str;
        cin >> str;

        cout << (check(str) ? "YES" : "NO") << endl;
    }

    return 0;
}