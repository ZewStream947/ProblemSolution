#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPalin(vector<int> arr)
{
    int l = 0, r = arr.size() - 1;
    while (l < r && arr[l] == arr[r])
        ++l, --r;
    return l >= r;
}

bool isPerfectSquare(int number)
{
    return (int)pow((int)sqrt(number), 2) == number;
}

int main()
{
    int TC, cnt = 1;

    scanf("%d", &TC);
    char str[100000];
    cin.ignore();
    vector<int> ch;

    while (TC--)
    {
        ch.clear();
        cin.getline(str, 100000);
        for (int index = 0; str[index] != '\0'; ++index)
            if (str[index] >= 'a' && str[index] <= 'z')
                ch.push_back(str[index]);
        printf("Case #%d:\n", cnt++);
        if (isPalin(ch) && isPerfectSquare(ch.size()))
            printf("%d\n", (int)sqrt(ch.size()));
        else
            printf("No magic :(\n");
    }

    return 0;
}