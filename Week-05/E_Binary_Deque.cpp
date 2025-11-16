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
        int n, s;
        cin >> n >> s;
        vector<int> a(n);

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }

        if (total < s)
        {
            cout << -1 << "\n";
            continue;
        }

        if (total == s)
        {
            cout << 0 << "\n";
            continue;
        }

        int l = 0;
        long long curr = 0;
        int max_len = -1;

        for (int r = 0; r < n; r++)
        {
            curr += a[r];

            while (curr > s)
            {
                curr -= a[l];
                l++;
            }

            // if window sum equals s
            if (curr == s)
            {
                max_len = max(max_len, r - l + 1);
            }
        }

        // if no such window found
        if (max_len == -1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << n - max_len << "\n";
        }
    }
    return 0;
}

// 📌 একটি ছোট উদাহরণ দিয়ে crystal clear করি

// Array:
// [1,0,1,1,0]
// ধরো s = 2

// Valid windows যাদের sum = 2:

// [1,0,1] → length 3

// [0,1,1] → length 3
// (সর্বোচ্চ length = 3)

// Total size n = 5

// 👉 আমরা রাখবো length = 3 এর window
// 👉 Remove করবো বাকি 2টা element

// তাই answer: n - max_len = 5 - 3 = 2
