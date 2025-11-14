#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        string s;
        cin >> s;
        char mn = '9';
        for (char c : s)
            if (c < mn)
                mn = c;
        cout << (mn - '0') << '\n';
    }
    return 0;
}
