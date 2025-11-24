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
