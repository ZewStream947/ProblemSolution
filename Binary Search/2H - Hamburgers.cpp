#include <cstdio>

using namespace std;

struct Hambuger
{
    int need = 0, have = 0, price = 0;
};

Hambuger B, S, C;
long long money = 0;

bool good(long long x)
{
    long long needB = B.need * x - B.have, needS = S.need * x - S.have, needC = C.need * x - C.have;
    long long mn = money;
    if (needB > 0 && mn >= needB * B.price)
        mn -= needB * B.price, needB = 0;
    if (needS > 0 && mn >= needS * S.price)
        mn -= needS * S.price, needS = 0;
    if (needC > 0 && mn >= needC * C.price)
        mn -= needC * C.price, needC = 0;
    return needB <= 0 && needS <= 0 && needC <= 0;
}

int main()
{
    char str[101];

    gets(str);
    for (int index = 0; str[index] != '\0'; ++index)
    {
        B.need += str[index] == 'B';
        S.need += str[index] == 'S';
        C.need += str[index] == 'C';
    }

    scanf("%d %d %d\n%d %d %d\n%I64d", &B.have, &S.have, &C.have, &B.price, &S.price, &C.price, &money);

    long long mid, l = 0, r = 1e15;

    while (l + 1 < r)
    {
        mid = (l + r) >> 1;
        good(mid) ? l = mid : r = mid;
    }

    printf("%I64d", l);

    return 0;
}