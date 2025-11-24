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
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        sort(a.begin(), a.end());

        long long mn = a[0];

        long long g = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i] % mn == 0)
            {
                g = __gcd(g, a[i]);
            }
        }

        if (g == mn)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
