#include <iostream>

using namespace std;

const string one = "one";
const string two = "two";
const string three = "three";

int compare(string src, string compare)
{
    if (src.length() != compare.length())
        return 5;
    int mst = 0;
    for (int index = 0; index < src.length(); ++index)
        if (src[index] != compare[index])
            ++mst;
    return mst;
}

int main()
{

    int TC;
    cin >> TC;

    string str;

    while (TC--)
    {

        cin >> str;
        if (compare(str, one) <= 1)
            cout << 1;
        else if (compare(str, two) <= 1)
            cout << 2;
        else if (compare(str, three) <= 1)
            cout << 3;
        cout << '\n';
    }

    return 0;
}