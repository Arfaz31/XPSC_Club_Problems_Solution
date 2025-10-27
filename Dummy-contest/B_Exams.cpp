#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        int total = x * y;
        if (z > total / 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
