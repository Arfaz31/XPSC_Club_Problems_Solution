#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    long long ans = 0, sum = 0;
    // sliding window
    while (r < n)
    {
        sum += a[r];
        if (r - l + 1 == k)
        {
            ans = max(ans, sum);
            sum -= a[l];
            l++;
        }
        r++;
        }
    cout << ans << endl;
    return 0;
}
