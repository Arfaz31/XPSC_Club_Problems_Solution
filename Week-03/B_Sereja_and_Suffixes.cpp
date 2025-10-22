

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> distinctSuffix(n + 1, 0);
    unordered_map<int, bool> seen;

    int distinctCount = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (!seen[a[i]])
        { // new number found
            distinctCount++;
            seen[a[i]] = true;
        }
        distinctSuffix[i] = distinctCount;
    }

    while (m--)
    {
        int l;
        cin >> l;
        cout << distinctSuffix[l - 1] << "\n"; // 0-based indexed
    }

    return 0;
}

// solution with set
//  #include <bits/stdc++.h>
//  using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) cin >> a[i];

//     vector<int> distinctCount(n + 2);
//     set<int> s;

//     for (int i = n; i >= 1; i--) {
//         s.insert(a[i]);
//         distinctCount[i] = s.size();
//     }

//     while (m--) {
//         int l;
//         cin >> l;
//         cout << distinctCount[l] << "\n";
//     }

//     return 0;
// }

// Hashing trick:

// প্রতিটি key (যেমন 5, 10) এর জন্য একটি hash function ব্যবহার করা হয়।

// উদাহরণ: hash(key) = key % 7 (ধরো table size 7)

// hash value = table-এর index।

// 5 % 7 = 5 → store key 5 in index 5

// 10 % 7 = 3 → store key 10 in index 3

// এখন যেকোনো key-এর জন্য hash calculate করলে আমরা direct table index-এ যেতে পারি।

// 2️⃣ Lookup process

// ধরো আমরা check করতে চাই: if (!seen[5]) { ... }
// Step by step:

// Compute hash: 5 % 7 = 5

// Directly go to table[5]

// Check if key stored there matches 5

// যদি match → value read করো (true/false)

// Time complexity: O(1) — কারণ sequential search করতে হয় না, সরাসরি index এ চলে যাই।

// 4️⃣ Why !seen[a[i]] works

// প্রথমবার a[i] এসেছে → hash করা হয়েছে → value এখনও default false

// তাই !false → true → first time number দেখা

// আমরা set করে দিই true → future lookups !true → false

// Efficiency:

// set এর তুলনায় unordered_map average O(1) lookup

// set তে insert ও find O(log n)

// তাই বড় n এর জন্য unordered_map দ্রুত
