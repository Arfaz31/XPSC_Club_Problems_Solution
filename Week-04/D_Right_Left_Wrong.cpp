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

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        string s;
        cin >> s;
        s = "#" + s; // 1-based indexing সহজ করার জন্য

        // prefix sum (যাতে দ্রুত range sum পাওয়া যায়)
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i];

        long long ans = 0;
        int l = 1, r = n;

        while (l < r)
        {
            // find first L from left
            while (l <= n && s[l] != 'L')
                l++;
            // find first R from right
            while (r >= 1 && s[r] != 'R')
                r--;

            if (l < r)
            {
                // আমরা একটা valid pair পেলাম (L...R)
                ans += pref[r] - pref[l - 1]; // range sum- prefix sum শুরু থেকে সব যোগ করছে — তাই l-এর আগের সব বাদ দিতে হলে l - 1 পর্যন্ত অংশটা subtract করতে হয়।
                l++;
                r--;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}

// 🔹 সংক্ষেপে বলতে গেলে:

// তুমি যত বেশি সম্ভব 'L' এর বামে এবং 'R' এর ডানে জোড়া বানাতে পারো,
// আর প্রতিবার তাদের মাঝে থাকা সব সংখ্যার যোগফল স্কোরে যোগ করবে।

// লক্ষ্য — এই যোগফলটাকে maximized করা।