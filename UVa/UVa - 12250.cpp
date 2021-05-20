#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> store = {{"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"}, {"BONJOUR", "FRENCH"}, {"ZDRAVSTVUJTE", "RUSSIAN"}, {"CIAO", "ITALIAN"}};
int main()
{
    string str;
    int cnt = 1;
    while (getline(cin, str), str[0] != '#')
    {
        string ans;
        if (!store.count(str))
            ans = "UNKNOWN";
        else
            ans = store[str];
        cout << "Case " << cnt++ << ": " << ans << '\n';
    }
    return 0;
}