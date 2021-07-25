#include <iostream>
#include <vector>

using namespace std;

const int BASE = 31;
const int MOD = 1e9 + 9;

vector<long long> POW;

void precompute(int n)
{
    POW.resize(n);
    POW[0] = 1;

    for (int index = 1; index < n; ++index)
        POW[index] = (POW[index - 1] * BASE) % MOD;
}

long long hashstr(string str)
{
    long long result = 0;
    for (int index = 0; index < str.length(); ++index)
        result = (result + (str[index] - 'a' + 1) * POW[index]) % MOD;
    return result;
}

void generate(vector<long long> &hs, string str)
{
    for (int index = 1; index <= str.length(); ++index)
        hs[index] = (hs[index - 1] + (str[index - 1] - 'a' + 1) * POW[index - 1]) % MOD;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int len;

    string needle, haystack;

    while (cin >> len)
    {
        cin >> needle >> haystack;
        precompute(max(len, (int)haystack.length()));
        long long nHash = hashstr(needle);
        vector<long long> hs(haystack.length() + 1, 0);
        generate(hs, haystack);
        for (int index = 0; index + len - 1 < haystack.length(); ++index)
            if ((hs[index + needle.length()] - hs[index] + MOD) % MOD == nHash * POW[index] % MOD)
                cout << index << "\n";
    }

    return 0;
}
