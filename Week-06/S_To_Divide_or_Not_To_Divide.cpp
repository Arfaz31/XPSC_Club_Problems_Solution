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
        long long A, B, N;
        cin >> A >> B >> N;

        // If every multiple of A is also a multiple of B → impossible
        if (A % B == 0)
        {
            cout << -1 << "\n";
            continue;
        }

        // Find first multiple of A >= N
        long long X = ((N + A - 1) / A) * A;

        if (X % B != 0)
        {
            cout << X << "\n";
        }
        else
        {
            // next multiple will not be divisible by B because A%B!=0
            cout << X + A << "\n";
        }
    }
    return 0;
}

// ✅ (N + A - 1) / A — এই লাইনটা শুধু মাত্র ceil(N / A) বের করার জন্য।