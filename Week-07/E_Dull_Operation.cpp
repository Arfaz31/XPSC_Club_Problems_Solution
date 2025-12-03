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
        long long N;
        cin >> N;

        long long x = N;
        long long y = N ^ 1;

        cout << x << " " << y << "\n";
    }
    return 0;
}

// ☑ product N হবে কেবল তখনই, যদি:

// OR part = N
// XOR part = 1

// x∣y=N
// x⊕y=1

// কারণ N odd → শেষ বিট (LSB) সবসময় 1
// N ^ 1 → শেষ বিট 1 → 0 হয়ে যায়

// যেমন:
// N = 21 = 10101
// N^1 = 20 = 10100
// এখন OR করলে: 10101 | 10100 = 10101 = 21 (= N)
// এবং XOR করলে: 10101 ^ 10100 = 00001 = 1
