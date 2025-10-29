#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            long long sum = (long long)a[l].first + a[r].first + a[i].first;
            if (sum == x)
            {
                cout << a[l].second << " " << a[r].second << " " << a[i].second << '\n';

                return 0;
            }
            else if (sum < x)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
