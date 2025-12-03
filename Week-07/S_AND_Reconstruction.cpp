#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

        vector<ll> b(n - 1), a(n);

        for (auto &x : b)
            cin >> x;

        // Construct a
        a[0] = b[0];
        for (int i = 1; i < n - 1; i++)
        {
            a[i] = b[i] | b[i - 1];
        }
        a[n - 1] = b[n - 2];

        // Validate
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if ((a[i] & a[i + 1]) != b[i])
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << "\n";
            continue;
        }

        // Print valid array
        for (ll x : a)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
