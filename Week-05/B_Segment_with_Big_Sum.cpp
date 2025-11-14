#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll sum = 0;
    int l = 0;
    ll ans = LLONG_MAX;

    for (ll r = 0; r < n; r++)
    {
        sum += a[r];

        while (sum >= s)
        {
            ans = min(ans, (r - l + 1));
            sum -= a[l];
            l++;
        }
    }

    if (ans == LLONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}
