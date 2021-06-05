#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string str;
vector<char> chr;

bool isPalin()
{
    int l = 0, r = chr.size() - 1;
    while (l < r && chr[l] == chr[r])
        ++l, --r;

    return l >= r;
}

int main()
{

    while (getline(cin, str) && str != "DONE")
    {
        chr.clear();
        for (int index = 0; str[index] != '\0'; ++index)
            if (str[index] != ' ' && str[index] != '!' && str[index] != ',' && str[index] != '.' && str[index] != '?')
                chr.push_back((char)tolower(str[index]));
        if (isPalin())
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }

    return 0;
}