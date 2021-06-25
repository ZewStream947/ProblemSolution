#include <cstdio>
#include <vector>
#include <queue>

#define fi first
#define se second
#define v(x) vector<x>
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> ii;
int n, m, d;
v(v(ii)) graph;
v(ii) temp;
v(int) result;
queue<int> q;

bool BFS(int target)
{
    q = queue<int>();
    q.push(1);
    temp[1] = mp(1, 0);
    for (int index = 2; index <= n; ++index)
        temp[index] = mp(0, 0);

    ii val;
    while (!q.empty())
    {
        int vtx = q.front();
        q.pop();
        for (int index = 0; index < graph[vtx].size(); ++index)
        {
            val = graph[vtx][index];
            if (val.se <= target && !temp[val.fi].fi && temp[vtx].se < d)
            {
                temp[val.fi].fi = vtx;
                temp[val.fi].se = temp[vtx].se + 1;
                q.push(val.fi);
                if (val.fi == n)
                {
                    result.clear();
                    while (val.fi != temp[val.fi].fi)
                    {
                        result.push_back(val.fi);
                        val.fi = temp[val.fi].fi;
                    }
                    result.push_back(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d", &n, &m, &d);

    graph.assign(n, v(ii)(0));
    temp.resize(n + 1);

    int mid, l = 1e9 + 1, r = -1;

    for (int a, b, c; m; --m)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(mp(b, c));
        l = min(l, c);
        r = max(r, c);
    }

    --l, ++r;

    while (l + 1 < r)
    {
        mid = l + ((r - l) >> 1);
        BFS(mid) ? r = mid : l = mid;
    }

    printf("%d\n", result.size() - 1);
    for (int index = result.size() - 1; index >= 0; --index)
        printf("%d ", result[index]);
    return 0;
}