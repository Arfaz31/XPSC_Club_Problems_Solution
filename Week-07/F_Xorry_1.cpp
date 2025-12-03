#include <bits/stdc++.h>
using namespace std;

// long long largestPowerOf2(long long x)
// {
//     return 1LL << (63 - __builtin_clzll(x));
// }
long long largestPowerOf2(long long x)
{
    // return 1LL << (int)log2(x);
    return 1LL << __lg(x); // __lg(x) gives highest set bit index 2^index
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        long long X;
        cin >> X;

        long long a = largestPowerOf2(X);
        long long b = X - a;

        cout << b << " " << a << "\n";
    }

    return 0;
}

// log2(X) → highest set bit এর index
// 1LL << index → সেই bit কে binary-তে 1 বসিয়ে 2^index তৈরি
// তাই সবসময় largest power of 2 ≤ X পাওয়া যায়
// b = X - a → automatically gives other number of the Xorry pair
// | X | A (largest power of 2 ≤ X) | B = X-A | Binary check | XOR |
// | - | -------------------------- | ------- | ------------ | --- |
// | 6 | 4                          | 2       | 100 ^ 010    | 110 |
// | 3 | 2                          | 1       | 10 ^ 01      | 11  |
// | 4 | 4                          | 0       | 100 ^ 000    | 100 |
