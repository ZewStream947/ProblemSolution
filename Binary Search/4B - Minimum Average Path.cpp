#include <cstdio>
#include <vector>

#define fi first
#define se second
#define v(x) vector<x>
#define mp(a, b) make_pair(a, b)
#define MAXN int(1e5 + 1)
#define INF 1e5 + 1

using namespace std;

typedef pair<int, int> ii;

v(v(ii)) graph;
int n, m;

//tmp var
int idx[MAXN];
double currSum[MAXN];
ii val;

bool good(double x)
{
    for (int index = 1; index < n; ++index)
    {
        currSum[index] = INF;
        for (ii val : graph[index])
            if (currSum[val.fi] + val.se - x < currSum[index])
            {
                currSum[index] = currSum[val.fi] + val.se - x;
                idx[index] = val.fi;
            }
    }
    return currSum[n - 1] <= 0;
}

int main()
{
    scanf("%d %d", &n, &m);

    graph.assign(n, v(ii)());

    for (int a, b, c; m; --m)
    {
        scanf("%d %d %d", &a, &b, &c), --a, --b;
        graph[b].push_back(mp(a, c));
    }

    double mid, l = 0, r = 100;

    for (m = 30; m; --m)
    {
        mid = (l + r) / 2;
        good(mid) ? r = mid : l = mid;
    }

    v(int) result;

    int index = n - 1;
    while (index != idx[index])
    {
        result.push_back(index + 1);
        index = idx[index];
    }

    printf("%d\n1 ", result.size());
    for (int index = result.size() - 1; index >= 0; printf("%d ", result[index--]))
        ;
    return 0;
}