#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Step 1: compute inv[j] = #k>j such that a[j]>a[k]
    vector<int> inv(n, 0);
    ordered_set s;
    for (int j = n - 1; j >= 0; j--)
    {
        inv[j] = s.order_of_key(a[j]);
        s.insert(a[j]);
    }

    // Step 2: forward pass to compute answer
    ll ans = 0;
    ordered_set p;
    for (int j = 0; j < n; j++)
    {
        ll big_value = p.size() - p.order_of_key(a[j]);
        ans += (ll)inv[j] * big_value;
        p.insert(a[j]);
    }

    cout << ans << "\n";
    return 0;
}
