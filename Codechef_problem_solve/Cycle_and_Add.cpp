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
        ll n, c;
        cin >> n >> c;
        vector<ll> b(n), d(n);
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        for (ll i = 0; i < n; i++)
            cin >> d[i];

        ll minCost = LLONG_MAX;

        // Try all possible shifts
        for (ll shift = 0; shift < n; shift++)
        {
            ll cost = shift * c; // shift cost
            for (ll i = 0; i < n; i++)
            {
                ll idx = (i - shift + n) % n; // circular indexing
                cost += d[i] * b[idx];        // increment cost
            }
            minCost = min(minCost, cost);
        }

        cout << minCost << "\n";
    }

    return 0;
}
