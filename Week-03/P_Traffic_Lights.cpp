#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> lights = {0, x};     // শুরুতে দুই প্রান্তে light
    multiset<int> segments = {x}; // শুরু segment = পুরো রাস্তা

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        // নতুন light বসাও
        auto it = lights.upper_bound(p); // next light
        int right = *it;
        int left = *prev(it);

        // পুরনো segment মুছে ফেল
        segments.erase(segments.find(right - left));

        // দুইটা নতুন segment add কর
        segments.insert(p - left);
        segments.insert(right - p);

        lights.insert(p);

        // এখন সবচেয়ে বড় segment প্রিন্ট কর
        cout << *segments.rbegin() << " ";
    }

    return 0;
}

// প্রাথমিক অবস্থা:

// lights = {0, 8} (প্রান্তে দুইটি light ধরে নিলে কাজ সহজ)

// segments = {8} (শুরুতে একটাই segment, দৈর্ঘ্য = 8)

// (Longest = 8 কিন্তু আমরা প্রথম output তখন দিই না; প্রতি insertion-এর পরে দিতে হবে)

// 1) Insert p = 3

// it = lights.upper_bound(3) → points to 8 (next light)

// right = *it = 8

// left = *prev(it) = 0

// Old segment to remove = right - left = 8 - 0 = 8

// segments.erase(segments.find(8)) → segments becomes {} (empty)

// Add new segments:

// p - left = 3 - 0 = 3

// right - p = 8 - 3 = 5

// segments.insert(3), segments.insert(5) → segments = {3, 5}

// Insert light: lights.insert(3) → lights = {0, 3, 8}

// Longest segment = max(segments) = 5

// Output after step 1: 5
// State now:
// lights = {0,3,8}
// segments = {3,5}

// 2) Insert p = 6

// it = lights.upper_bound(6) → points to 8

// right = 8, left = *prev(it) = 3

// Old segment to remove = right - left = 8 - 3 = 5

// segments.erase(segments.find(5)) → segments becomes {3}

// Add new segments:

// p - left = 6 - 3 = 3

// right - p = 8 - 6 = 2

// segments.insert(3), segments.insert(2) → segments = {3,3,2} (multiset keeps duplicates)

// Insert light: lights.insert(6) → lights = {0,3,6,8}

// Longest segment = max(segments) = 3

// Output after step 2: 3
// State now:
// lights = {0,3,6,8}
// segments = {3,3,2}

// 3) Insert p = 2

// it = lights.upper_bound(2) → points to 3

// right = 3, left = *prev(it) = 0

// Old segment to remove = right - left = 3 - 0 = 3

// segments.erase(segments.find(3)) → removes one 3, so segments becomes {3,2}

// Add new segments:

// p - left = 2 - 0 = 2

// right - p = 3 - 2 = 1

// segments.insert(2), segments.insert(1) → segments = {3,2,2,1}

// Insert light: lights.insert(2) → lights = {0,2,3,6,8}

// Longest segment = max(segments) = 3

// Output after step 3: 3