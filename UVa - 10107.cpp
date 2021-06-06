#include <cstdio>
#include <map>

using namespace std;

map<int, int> cnt;

int getMedian(int size)
{
    int mid = size / 2;
    int pos = 0;
    map<int, int>::iterator it = cnt.begin();

    if (!(size & 1))
        mid -= 1;
    while (pos < mid)
        pos += it->second, ++it;

    if (size & 1 || pos > mid)
        return it->first;

    return (it->first + (++it)->first) / 2;
}

int main()
{

    int number, size = 0;
    while (scanf("%d", &number) == 1)
    {
        ++cnt[number];
        printf("%d\n", getMedian(++size));
    }

    return 0;
}