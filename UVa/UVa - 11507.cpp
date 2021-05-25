#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    const unordered_map<string, unordered_map<string, string>> arr = {{"+x", {{"+y", "+y"}, {"-y", "-y"}, {"+z", "+z"}, {"-z", "-z"}}},
                                                                      {"-x", {{"+y", "-y"}, {"-y", "+y"}, {"+z", "-z"}, {"-z", "+z"}}},
                                                                      {"+y", {{"+y", "-x"}, {"-y", "+x"}, {"+z", "+y"}, {"-z", "+y"}}},
                                                                      {"-y", {{"+y", "+x"}, {"-y", "-x"}, {"+z", "-y"}, {"-z", "-y"}}},
                                                                      {"+z", {{"+y", "+z"}, {"-y", "+z"}, {"+z", "-x"}, {"-z", "+x"}}},
                                                                      {"-z", {{"+y", "-z"}, {"-y", "-z"}, {"+z", "+x"}, {"-z", "-x"}}}};
    int n;
    string curr, temp;
    while (cin >> n, n)
    {
        curr = "+x";
        while (--n)
        {
            cin >> temp;
            if (temp != "No")
                curr = arr.at(curr).at(temp);
        }
        cout << curr << '\n';
    }

    return 0;
}