#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        ll g = a[0];
        for (ll i = 1; i < n; i++)
            g = __gcd(g, a[i]);

        ll ans = -1;
        for (ll x = 2; x <= 100; x++)
        {
            if (__gcd(g, x) == 1)
            {
                ans = x;
                break;
            }
        }

        cout << ans << "\n";
    }
}
