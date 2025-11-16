#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
// multiset hisebe hole less_equal<T>
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    pbds<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int idx = k % n;
    while (n--)
    {
        auto it = s.find_by_order(idx);
        cout << *it << " ";
        s.erase(it);

        if (n)
        {
            idx = (idx + k) % n;
        }
    }
    cout << "\n";
    return 0;
}