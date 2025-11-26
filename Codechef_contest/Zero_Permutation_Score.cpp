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

        if (N <= 2)
        {
            cout << 0 << "\n";
        }
        else
        {
            long long x = N - 2;
            cout << (x * x) / 4 << "\n";
        }
    }
    return 0;
}
