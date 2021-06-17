#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int cnt[4] = {0};
bool allChecked()
{
    return cnt[0] && cnt[1] && cnt[2] && cnt[3];
}

int main()
{

    int x, val;
    vector<ii> arr;
    for (int cnt = 0; cnt <= 3; ++cnt)
    {
        scanf("%d", &x);
        while (x--)
            scanf("%d", &val), arr.push_back(make_pair(val, cnt));
    }

    sort(arr.begin(), arr.end());

    vi result(4), res_temp(4, 0);
    int currMin = 100001;
    for (int r = 0, l = 0; r < arr.size(); ++r)
    {
        ++cnt[arr[r].second];
        res_temp[arr[r].second] = arr[r].first;
        if (allChecked())
        {
            while (!allChecked())
                --cnt[arr[l++].second];
            if (*max_element(res_temp.begin(), res_temp.end()) - *min_element(res_temp.begin(), res_temp.end()) < currMin)
            {
                currMin = *max_element(res_temp.begin(), res_temp.end()) - *min_element(res_temp.begin(), res_temp.end());
                result = res_temp;
            }
        }
    }

    for (int val : result)
        printf("%d ", val);
    return 0;
}