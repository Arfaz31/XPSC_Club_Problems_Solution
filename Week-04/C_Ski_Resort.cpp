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
        long long n, k, q;
        cin >> n >> k >> q;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long ans = 0; // total valid vacation ways
        long long len = 0; // current segment length

        for (int i = 0; i < n; i++)
        {
            if (a[i] <= q)
            {
                len++; // extend current valid segment
            }
            else
            {
                // segment break → calculate valid subarrays if possible
                if (len >= k)
                {
                    long long x = len - k + 1;
                    ans += (x * (x + 1)) / 2;
                }
                len = 0; // reset segment
            }
        }

        if (len >= k)
        {
            long long x = len - k + 1;
            ans += (x * (x + 1)) / 2;
        }

        cout << ans << "\n";
    }

    return 0;
}

// 🧩 আমরা জানি:

// Dima minimum k দিন ski resort-এ যেতে চায়।
// মানে সে k বা তার বেশি consecutive দিন বেছে নিতে পারে,
// কিন্তু k-র চেয়ে ছোট segment valid না।

// a = [2, 1, 3, 8, 1, 1, 1]
// q = 3, k = 2

// তাহলে প্রথম 3 দিন: [2,1,3] সব ≤ 3
// → len = 3

// ৪র্থ দিনে 8 এসেছে (temperature > q)
// 👉 segment break হয়েছে!

// এখন পর্যন্ত আমাদের segment [2,1,3]
// এর length = 3, k = 2
// তাহলে vacation নেওয়ার সম্ভাব্য subarrays:
// [2,1], [1,3], [2,1,3]
// → মোট 3 টা
// এই সংখ্যাটাই formula দিয়ে পাই:
// x = len - k + 1 = 3 - 2 + 1 = 2
// ans += (x * (x + 1)) / 2 = (2 * 3)/2 = 3 ✅

// এরপর len = 0 করা হয়,
// কারণ ৮ এসেছে — নতুন segment শুরু হবে এখান থেকে।

// 💡 তাই condition if (len >= k) মানে হলো:

// যদি segment এর length অন্তত k হয়, তাহলে সেখান থেকে কিছু valid vacation নেওয়া সম্ভব।

// আর যদি len < k হয় → ওই segment থেকে একটাও valid vacation সম্ভব নয়, তাই কিছু যোগ করা লাগবে না।

// 🧩 কেন +1 দরকার?

// ধরো তুমি len = k নাও।
// তাহলে valid subarray হবে ঠিক একটাই (পুরো segment টা)।

// যদি আমরা formula টা লিখি len - k,
// তাহলে পাব x = len - k = 0,
// ফলাফল হবে 0, কিন্তু আসলে তো ১টা valid আছে!

// তাই আমাদের +1 যোগ করতে হয়,
// যাতে এমন case-এও count সঠিক থাকে।