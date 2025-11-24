#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        int g = N / K; // এই line ঠিক করছে maximum possible GCD যা আমরা subset থেকে পেতে পারি।

        for (int i = 1; i <= K; ++i)
        {
            if (i > 1)
                cout << ' '; // প্রথম number এর আগে space লাগবে না কিন্তু দ্বিতীয় number থেকে প্রতিটা number এর আগে একটি space দিব
            cout << (long long)i * g;
        }
        cout << '\n';
    }
    return 0;
}

// Example: N = 10, K = 3

// g = N / K = 10 / 3 = 3

// subset = {3*1, 3*2, 3*3} = {3, 6, 9}

// Check GCD:

// gcd(3,6,9) = 3 ✅

// Largest possible GCD, কারণ g > 3 → 3*4 = 12 > N → not allowed

// অন্য কোনো subset:

// {1,2,3} → gcd = 1

// {2,4,6} → gcd = 2

// {3,6,9} → gcd = 3 → Maximum ✅

// Step 4: সারসংক্ষেপ

// Subset GCD বড় করতে হলে সব element একই সংখ্যা g দ্বারা divisible হতে হবে।

// Largest possible g = N / K → যাতে K elements 1..N মধ্যে ফিট হয়

// Loop দিয়ে subset = i * g (i = 1..K) → সব element g দ্বারা divisible → GCD = g (maximum possible)