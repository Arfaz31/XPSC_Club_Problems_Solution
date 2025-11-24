#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long l, r;
    cin >> l >> r;

    // মোট সংখ্যা জোড় না হলে সমাধান নেই (যদিও শর্তে দেয়া আছে)
    if ((r - l + 1) % 2 == 1)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    // জোড়া: (l, l+1), (l+2, l+3), ...
    for (long long i = l; i <= r; i += 2)
    {
        cout << i << " " << i + 1 << "\n";
    }

    return 0;
}
