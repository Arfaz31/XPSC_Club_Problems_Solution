#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;

        int ax = 0, bx = 0;
        for (int i = 0; i < n; i++)
        {
            ax ^= a[i];
            bx ^= b[i];
        }

        if (ax == bx)
        {
            cout << "Tie\n";
            continue;
        }

        int o = 0, e = 0, last = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                last = i + 1;
                if ((i + 1) % 2 == 1)
                    o++;
                else
                    e++;
            }
        }

        if (o == 0 && e == 0)
        {
            cout << (ax > bx ? "Ajisai\n" : "Mai\n");
        }
        else if (o > 0 && e == 0)
        {
            cout << "Ajisai\n";
        }
        else if (o == 0 && e > 0)
        {
            cout << "Mai\n";
        }
        else
        {
            if (last % 2 == 1)
                cout << "Ajisai\n";
            else
                cout << "Mai\n";
        }
    }

    return 0;
}