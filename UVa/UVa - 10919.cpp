#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
    int k, m, r, c, cnt, tmp;
    unordered_map<int, bool> course;

    int code;

    while (scanf("%d", &k), k)
    {
        course.clear();
        scanf("%d", &m);
        while (k--)
            scanf("%d", &code), course[code] = 1;

        bool isOk = 1;
        while (m--)
        {
            cnt = 0;
            scanf("%d %d", &c, &r);
            while (c--)
            {
                scanf("%d", &tmp);
                cnt += course[tmp];
            }
            if (cnt < r)
                isOk = 0;
        }
        if (isOk)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}