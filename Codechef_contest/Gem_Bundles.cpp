#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int R, B, G;
        cin >> R >> B >> G;

        int bundles = min({R, B, G});
        int leftover = (R + B + G) - 3 * bundles;

        int coins = bundles * 10 + leftover * 3;

        cout << coins << endl;
    }
    return 0;
}
