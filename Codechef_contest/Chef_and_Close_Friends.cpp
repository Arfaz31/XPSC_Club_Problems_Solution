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
        int x, y, z;
        cin >> x >> y >> z;

        int L1 = x - y;
        int R1 = x + y;

        int L2 = x - z;
        int R2 = x + z;

        int L = max(L1, L2);
        int R = min(R1, R2);

        if (L > R)
        {
            cout << 0 << "\n";
            continue;
        }

        int ans = R - L + 1;

        if (L <= x && x <= R)
            ans--;

        cout << ans << "\n";
    }

    return 0;
}

// Example 1: 0 2 1

// Input:
// Chef position: x = 0
// Friend range: y = 2 → Friends live at [-2, -1, 1, 2] (exclude 0)
// Max travel distance: z = 1 → Chef can move [-1, 0, 1]

// Step 1: Friend interval & Chef interval
// Friends: [-2, 2] excluding 0 → positions: -2, -1, 1, 2
// Chef travel: [-1, 1] → positions: -1, 0, 1

// Step 2: Find intersection
// L = max(L1,L2) = max(-2,-1) = -1
// R = min(R1,R2) = min(2,1) = 1
// Intersection = [-1, 0, 1]

// Step 3: Count positions
// R - L + 1 = 1 - (-1) + 1 = 3
// Positions in overlap: -1, 0, 1 → total 3

// Step 4: Exclude Chef
// x = 0 is in overlap → subtract 1
// Answer = 3 - 1 = 2
