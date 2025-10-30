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
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < m; j++)
            cin >> b[j];

        vector<int> ans;
        int i = 0, j = 0;
        bool possible = true;

        while (i < n || j < m)
        {
            bool moved = false;

            if (i < n && a[i] == 0)
            {
                ans.push_back(0);
                k++;
                i++;
                moved = true;
            }
            else if (j < m && b[j] == 0)
            {
                ans.push_back(0);
                k++;
                j++;
                moved = true;
            }
            else if (i < n && a[i] <= k)
            {
                ans.push_back(a[i]);
                i++;
                moved = true;
            }
            else if (j < m && b[j] <= k)
            {
                ans.push_back(b[j]);
                j++;
                moved = true;
            }

            if (!moved)
            {
                possible = false;
                break;
            }
        }

        if (!possible)
            cout << -1 << "\n";
        else
        {
            for (int x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
