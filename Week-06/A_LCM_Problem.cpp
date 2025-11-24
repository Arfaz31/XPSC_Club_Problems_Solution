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
        long long l, r;
        cin >> l >> r;
        if (2 * l <= r)
        {
            cout << l << " " << 2 * l << "\n";
        }
        else
        {
            cout << -1 << " " << -1 << "\n";
        }
    }
    return 0;
}
