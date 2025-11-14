#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 0, ans = 0;
    ll sum = 0;
    while (r < n)
    {
        sum += a[r];
        if (sum <= k)
        {
            ans = max(ans, r - l + 1);
        }
        else
        {
            sum -= a[l];
            l++;
        }
        r++;
    }
    cout << ans << "\n";

    return 0;
}
