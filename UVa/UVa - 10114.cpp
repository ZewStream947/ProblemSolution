#include <cstdio>

using namespace std;

int main()
{
    int months, n, index;
    double downPayment, loan, carFee;

    while (scanf("%d", &months), months >= 0)
    {
        scanf("%lf %lf %d", &downPayment, &loan, &n);

        double arr[months + 1] = {0};

        while (n--)
        {
            scanf("%d", &index);
            scanf("%lf", arr + index);
        }

        int result = 0;

        carFee = (downPayment + loan) * (1 - arr[0]);

        downPayment = loan / months;

        while (loan > carFee)
        {
            ++result;
            if (arr[result] == 0)
                arr[result] = arr[result - 1];
            carFee -= carFee * arr[result];
            loan -= downPayment;
        }

        printf("%d month", result);
        if (result != 1)
            printf("s");
        printf("\n");
    }

    return 0;
}