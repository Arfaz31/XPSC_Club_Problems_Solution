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
        long long A, B;
        cin >> A >> B;
        cout << A - __gcd(A, B) << "\n";
    }
    return 0;
}


// আমাদের minimize করতে হবে:

// lcm(A,X)−gcd(B,X)
// lcm(A,X)−gcd(B,X)

// X তুমি যা খুশি নিতে পারো।

// আমরা চাই:

// LCM → যত ছোট সম্ভব
// GCD → যত বড় সম্ভব

// কারণ ছোট − বড় = খুব ছোট = minimum value.