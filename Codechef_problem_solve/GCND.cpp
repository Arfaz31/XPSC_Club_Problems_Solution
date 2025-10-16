#include <bits/stdc++.h>
using namespace std;

int gcnd(int x, int y)
{
    int mx = max(x, y);
    for (int z = mx - 1; z >= 1; z--)
    {
        if (x % z != 0 && y % z != 0)
        {
            return z;
        }
    }
    return 1;
}

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
            cin >> a[i];

        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, gcnd(a[i], a[i - 1]));
        }
        cout << ans << "\n";
    }
    return 0;
}
