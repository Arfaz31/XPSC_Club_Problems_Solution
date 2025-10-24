#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        // প্রথম element যেটা t এর চেয়ে strictly বড়
        auto it = tickets.upper_bound(t);

        if (it == tickets.begin())
        {
            // কোনো ticket <= t নেই
            cout << -1 << "\n";
        }
        else
        {
            --it; // এখন *it ≤ t
            cout << *it << "\n";
            tickets.erase(it); // টিকিট বিক্রি হয়ে গেল
        }
    }
}

// 🔹 Step 2: if (it == tickets.begin())

// এখন চেক করা হচ্ছে —
// upper_bound(t) যেই জায়গায় গেছে, সেটার আগে কিছু আছে কিনা।

// যদি it == tickets.begin(),
// মানে multiset-এর একদম শুরুতেই চলে এসেছে,
// অর্থাৎ সব element-ই t এর চেয়ে বড়,
// তাহলে কোনো ticket ≤ t নেই।

// ✅ তাই -1 print হবে।

// t = 2
// tickets = {3, 5, 7, 8}

// upper_bound(2) → tickets.begin() pointing 3
// ==> সব দাম 2 এর চেয়ে বড়
// Output: -1

// Step 3: --it; // এখন *it ≤ t

// যদি it != tickets.begin(),
// তাহলে আমরা এক ধাপ পেছনে যাই (--it),
// কারণ upper_bound(t) এর আগের elementটাই হলো
// t এর সমান বা ছোট সবচেয়ে বড় দাম।

// উদাহরণ:
// t = 6
// tickets = {3, 5, 5, 7, 8}

// upper_bound(6) → points to 7
// --it → এখন points to 5
// => *it = 5
