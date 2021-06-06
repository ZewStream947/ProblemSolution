#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int TC;

    scanf("%d", &TC);

    char ch;
    int n, val;

    unordered_map<char, int> value;

    char str[10001];
    cout.precision(2);

    while (TC--)
    {
        value.clear();
        scanf("%d", &n);
        while (n--)
            cin.ignore(), scanf("%c %d", &ch, &val), value[ch] = val;
        scanf("%d", &n);
        cin.ignore();

        double result = 0;
        while (n--)
        {
            cin.getline(str, 10001);
            for (int index = 0; str[index] != '\0'; ++index)
                if (value.count(str[index]))
                    result += value[str[index]];
        }
        cout << fixed << result / 100 << "$\n";
    }

    return 0;
}