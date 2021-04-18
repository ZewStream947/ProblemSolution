#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class stk
{
private:
    stack<ll> s, sMin, sMax;

public:
    stk()
    {
        sMin.push(LLONG_MAX);
        sMax.push(LLONG_MIN);
    }

    void push(ll val)
    {
        s.push(val);
        sMin.push(::min(sMin.top(), val));
        sMax.push(::max(sMax.top(), val));
    }

    ll pop()
    {
        ll temp = s.top();
        s.pop();
        sMin.pop();
        sMax.pop();
        return temp;
    }

    bool empty()
    {
        return s.empty();
    }

    ll max()
    {
        return sMax.top();
    }

    ll min()
    {
        return sMin.top();
    }

    ~stk() {}
};

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int size;
    ll target;

    cin >> size >> target;

    ll result = 0, x;

    stk s1, s2;

    for (int l = 0, r = 0; r < size; ++r)
    {
        cin >> x;
        s1.push(x);
        while (max(s1.max(), s2.max()) - min(s1.min(), s2.min()) > target)
        {
            if (s2.empty())
                while (!s1.empty())
                    s2.push(s1.pop());
            s2.pop();
            ++l;
        }
        result += r - l + 1;
    }

    cout << result;
    return 0;
}