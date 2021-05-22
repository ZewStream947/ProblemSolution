#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const vector<string> lyrics = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int n;

    cin >> n;
    vector<string> list(n);
    for (int index = 0; index < n; cin >> list[index++])
        ;
    int lim = max(16, (n / 16 + (n % 16 > 0)) * 16);
    for (int index = 0; index < lim; ++index)
        cout << list[index % n] << ": " << lyrics[index % 16] << '\n';
    return 0;
}