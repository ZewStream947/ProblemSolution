#include <iostream>

using namespace std;

int main()
{
    string str;
    int n, Mstart, Mend, Fstart, Fend;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        Mstart = Mend = Fstart = Fend = 0;
        getline(cin, str);
        bool isStart = 1;
        for (char c : str)
            if (isStart && c != ' ')
            {
                if (c == 'M')
                    ++Mstart;
                else if (c == 'F')
                    ++Fstart;
                isStart = 0;
            }
            else
            {
                if (c == 'M')
                    ++Mend;
                else if (c == 'F')
                    ++Fend;
                isStart = 1;
            }

        if ((Mstart == Fend && Fstart == Mend && str.length() > 3))
            cout
                << "LOOP\n";
        else
            cout << "NO LOOP\n";
    }

    return 0;
}