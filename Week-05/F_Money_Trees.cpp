#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n), h(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> h[i];

        long long sum = 0;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++)
        {
            // যদি divisibility chain break হয়
            if (r > 0 && h[r - 1] % h[r] != 0)
            {
                // window reset
                l = r;
                sum = 0;
            }

            sum += a[r];

            // sum > k হলে sliding window shrink
            while (sum > k)
            {
                sum -= a[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        cout << ans << "\n";
    }
    return 0;
}
