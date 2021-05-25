#include <iostream>

using namespace std;

int getCode(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 1;
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 1;
    return 0;
}

int getSum(int number)
{
    if (number < 10)
        return number;
    int sum = 0;
    while (number)
        sum += number % 10,
            number /= 10;

    return getSum(sum);
}

int main()
{
    string name1, name2;

    cout.precision(2);
    while (getline(cin, name1) && getline(cin, name2))
    {
        int sum1 = 0, sum2 = 0;
        for (char ch : name1)
            sum1 += getCode(ch);
        for (char ch : name2)
            sum2 += getCode(ch);
        sum1 = getSum(sum1);
        sum2 = getSum(sum2);
        cout << fixed << ((double)min(sum1, sum2) / (double)max(sum1, sum2)) * 100.00 << " %\n";
    }

    return 0;
}