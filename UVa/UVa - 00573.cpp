#include <iostream>

using namespace std;

int main()
{
    double H, U, D, F;

    while (scanf("%lf %lf %lf %lf", &H, &U, &D, &F), H)
    {
        double climbed = 0;
        int day = 1;
        double fatigue = (F / 100) * U;
        while (true)
        {
            climbed += U;
            U = max(U - fatigue, 0.0);
            if (climbed > H)
                break;
            climbed -= D;
            if (climbed < 0.0)
                break;
            ++day;
        }

        if (climbed >= H)
            printf("success ");
        else
            printf("failure ");
        printf("on day %d\n", day);
    }

    return 0;
}