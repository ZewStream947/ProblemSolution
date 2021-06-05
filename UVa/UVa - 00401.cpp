#include <cstdio>
#include <unordered_map>
#include <cstring>

using namespace std;

unordered_map<char, char> reverse = {
    {'A', 'A'},
    {'E', '3'},
    {'H', 'H'},
    {'I', 'I'},
    {'J', 'L'},
    {'L', 'J'},
    {'M', 'M'},
    {'O', 'O'},
    {'S', '2'},
    {'T', 'T'},
    {'U', 'U'},
    {'V', 'V'},
    {'W', 'W'},
    {'X', 'X'},
    {'Y', 'Y'},
    {'Z', '5'},
    {'1', '1'},
    {'2', 'S'},
    {'3', 'E'},
    {'5', 'Z'},
    {'8', '8'}};

char str[100];
int len;

bool isPalin()
{
    int l = 0, r = len - 1;
    while (l < r && str[l] == str[r])
        ++l, --r;

    return l >= r;
}

bool isMirrored()
{
    int l = 0, r = len - 1;

    while (l <= r && reverse.count(str[r]) >= 1 && str[l] == reverse[str[r]])
        ++l, --r;

    return l > r;
}

int main()
{
    while (scanf("%s", &str) != EOF)
    {
        len = strlen(str);
        bool isMirr = isMirrored(), isPal = isPalin();
        if (!isMirr && !isPal)
            printf("%s -- is not a palindrome.\n\n", str);
        else if (!isMirr && isPal)
            printf("%s -- is a regular palindrome.\n\n", str);
        else if (isMirr && !isPal)
            printf("%s -- is a mirrored string.\n\n", str);
        else
            printf("%s -- is a mirrored palindrome.\n\n", str);
    }

    return 0;
}