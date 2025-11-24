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

        string binary = "";

        int x = n;
        while (x > 0)
        {
            binary += char('0' + (x % 2));
            x /= 2;
        }

        int cnt = 0;
        for (char c : binary)
        {
            if (c == '1')
                cnt++;
        }

        if (cnt % 2 == 0)
            cout << "EVEN\n";
        else
            cout << "ODD\n";
    }

    return 0;
}
