#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int arrSize;

    cin >> arrSize;

    int number[arrSize];

    for (int index = 0; index < arrSize; ++index)
        cin >> number[index];

    sort(number, number + arrSize);

    int current = 1;

    for (int x : number)
        if (x > current)
            return current;
        else if (current == x)
            ++current;

    cout << current;

    return 0;
}