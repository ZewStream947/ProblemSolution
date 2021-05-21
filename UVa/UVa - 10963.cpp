#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
    int TC;
    scanf("%d", &TC);
    int n, y1, y2;

    unordered_map<int, bool> cnt;

    bool isFirst = 1;
    while (TC--)
    {
        cnt.clear();
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d %d", &y1, &y2);
            cnt[y2 - y1] = 1;
        }

        if (!isFirst)
            printf("\n");
        else
            isFirst = 0;
        if (cnt.size() == 1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}