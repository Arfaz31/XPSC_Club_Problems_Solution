#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;

        int cnt0 = count(S.begin(), S.end(), '0');

        vector<int> bucketSizes(K, 0);

        for (int i = 0; i < N; i++)
        {
            bucketSizes[i % K]++;
        }

        int totalMin = 0, totalMax = 0;

        for (int L : bucketSizes)
        {
            int mn = L / 2;
            int mx = (L + 1) / 2;
            totalMin += mn;
            totalMax += mx;
        }

        if (cnt0 >= totalMin && cnt0 <= totalMax)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

// ✔ Step 2 — bucket size হিসাব করা
// i % K কি দেয় দেখি:
// i : 0 1 2 3 4 5 6 7
// i%3:0 1 2 0 1 2 0 1
// সুতরাং:

// bucket 0 → indices → 0,3,6 → size = 3
// bucket 1 → indices → 1,4,7 → size = 3
// bucket 2 → indices → 2,5 → size = 2

// bucketSizes = [3, 3, 2]

// Step 3 — প্রতিটি bucket-এর minimum এবং maximum possible zeros
// minZero = L / 2
// maxZero = (L + 1) / 2

// Example:

// L = 3
// → sequence হতে পারে 010 বা 101
// → zeros হতে পারে 1 বা 2
// → min=1, max=2

// L = 2
// → sequence হতে পারে 01 বা 10
// → zeros হতে পারে 1
// → min=1, max=1

// চলো এবার হিসাব করি:

// Bucket sizes → 3, 3, 2

// Bucket 0 (size = 3)

// min = 1
// max = 2

// Bucket 1 (size = 3)

// min = 1
// max = 2

// Bucket 2 (size = 2)

// min = 1
// max = 1

// 🔥 এখন মূল কথা: totalMin এবং totalMax কেন বের করা হয়?

// কারণ পুরো string-এ তুমি যতগুলো 0 পেয়েছো, ধরো cnt0

// সে cnt0 কে distribute করতে হবে সকল bucket-এর মধ্যে
// এভাবে যেন:

// প্রতিটি bucket-এর ভিতরে alternate pattern থাকে

// সংখ্যা কম বা বেশি না হয়ে যায়

// এখন:

// প্রতিটি bucket–এর জন্য minimum zero required (তুমি কম দিতে পারবে না)।
// আর maximum zero possible আছে (তুমি বেশি দিতে পারবে না)।