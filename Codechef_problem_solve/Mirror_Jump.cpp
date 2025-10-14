
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        if (K == N)
            cout << 0 << "\n";
        else
            cout << min(N - K, K) << "\n";
    }
    return 0;
}

// 1️⃣ Mirror move এর formula

// Mirror করলে Chef-এর নতুন position হয়:

// mirror_position=N+1−K
// mirror_position=N+1−K

// K = Chef-এর current position

// N = শেষ position

// 2️⃣ Mirror করার পর N পর্যন্ত distance

// Mirror করার পরে Chef N পয়েন্টে যেতে চাইলে:

// distance=∣N−mirror_position∣=∣N−(N+1−K)∣
// distance=∣N−mirror_position∣=∣N−(N+1−K)∣

// এখানে একদম মনোযোগ দাও:

// N−(N+1−K)=N−N−1+K=K−1
// N−(N+1−K)=N−N−1+K=K−1

// প্রথমে N কে mirror formula-এর মধ্যে distribute করি → N - N -1 + K

// অবশেষে আমরা পাই K - 1

// অর্থাৎ Mirror করার পরে Chef N পর্যন্ত যেতে হবে K - 1 step

// 3️⃣ Mirror move নিজেই 1 move

// Mirror করা হয় একবার → 1 move

// তারপর K - 1 step → মোট move = 1 + (K-1) = K

// 4️⃣ সরাসরি move

// Mirror ছাড়া সরাসরি ডানে যাওয়ার distance = N - K

// 5️⃣ তুলনা

// Mirror ব্যবহার করলে move = K

// সরাসরি move = N - K

// Answer = min(N - K, K)

// 6️⃣ উদাহরণ: N = 10, K = 3

// Mirror করলে → Chef যাবে 10 + 1 - 3 = 8

// N এ যেতে লাগবে → 10 - 8 = 2

// Mirror move = 1 → total = 1 + 2 = 3 = K

// সরাসরি ডানে → 10 - 3 = 7

// কম move = 3 → answer