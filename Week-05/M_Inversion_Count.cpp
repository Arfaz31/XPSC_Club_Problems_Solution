#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        pbds<int> p;
        long long int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = p.order_of_key(a[i]); // x = number of elements strictly less than a[i]
            ans += x;
            p.insert(a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
