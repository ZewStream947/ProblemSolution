#include <cstdio>
#include <bitset>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bitset<10000> row, col;
int cnt = 1, rows, cols, n, r, c;

bool canEscaped(int r, int c)
{
    if (!row[r] && !col[c])
        return 1;
    for (int index = 0; index < 4; ++index)
        if (r + dx[index] >= 0 && r + dx[index] < rows && c + dy[index] >= 0 && c + dy[index] < cols)
            if (!row[r + dx[index]] && !col[c + dy[index]])
                return 1;
    return 0;
}

int main()
{
    while (scanf("%d %d %d", &rows, &cols, &n), n && rows && cols)
    {
        row.reset();
        col.reset();
        while (n--)
        {
            scanf("%d %d", &r, &c);
            row[r] = 1;
            col[c] = 1;
        }
        scanf("%d %d", &r, &c);
        printf("Case %d: ", cnt++);
        canEscaped(r, c) ? printf("Escaped again! More 2D grid problems!\n") : printf("Party time! Let's find a restaurant!\n");
    }

    return 0;
}
