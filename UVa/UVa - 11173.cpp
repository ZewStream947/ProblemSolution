#include <cstdio>
#include <stack>

#define ToggleBit(S, j) (S ^= (1 << j))

using namespace std;

void printSet(int vS)
{ // in binary representation
    printf("S = %2d = ", vS);
    stack<int> st;
    while (vS)
        st.push(vS % 2), vS /= 2;
    while (!st.empty()) // to reverse the print order
        printf("%d", st.top()), st.pop();
    printf("\n");
}

int main()
{

    int TC, n, k;
    scanf("%d", &TC);

    while (TC--)
    {
        scanf("%d %d", &n, &k);
        printf("%d\n", k ^ (k >> 1));
    }

    return 0;
}