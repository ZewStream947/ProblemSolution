#include <iostream>

#define MAX_LOG 25
#define MAX_SIZE 100001

using namespace std;

int size;
int table[MAX_LOG][MAX_SIZE];
int *log;

void compute_logs(int len)
{
    log = (int *)malloc((len + 1) * sizeof(int));
    log[1] = 0;
    for (int index = 2; index <= len; ++index)
        log[index] = log[index / 2] + 1;
}

void buildSpT()
{
    compute_logs(size);
    for (int pow = 1; pow <= log[size]; ++pow)
        for (int index = 0, len = (1 << pow); index + len <= size; ++index)
            table[pow][index] = min(table[pow - 1][index], table[pow - 1][index + (len >> 1)]);
}

int query(int l, int r)
{
    int lg = log[r - l + 1];
    return min(table[lg][l], table[lg][r - (1 << lg) + 1]);
}

int main()
{
    cin >> size;
    for (int index = 0; index < size; ++index)
        cin >> table[0][index];
    buildSpT();
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}