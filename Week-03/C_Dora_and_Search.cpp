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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        set<int> s(a.begin(), a.end()); // store all elements
        int l = 0, r = n - 1;
        bool found = false;

        while (l < r && !s.empty())
        {
            int mn = *s.begin();  // current min
            int mx = *s.rbegin(); // current max

            if (a[l] != mn && a[l] != mx && a[r] != mn && a[r] != mx)
            {
                cout << l + 1 << " " << r + 1 << "\n";
                found = true;
                break;
            }

            // remove the extremes and move pointers
            if (a[l] == mn || a[l] == mx)
            {
                s.erase(a[l]);
                l++;
            }
            else if (a[r] == mn || a[r] == mx)
            {
                s.erase(a[r]);
                r--;
            }
        }

        if (!found)
            cout << -1 << "\n";
    }

    return 0;
}
