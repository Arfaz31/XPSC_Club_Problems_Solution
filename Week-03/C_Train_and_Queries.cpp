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
        int n, q;
        cin >> n >> q;

        map<int, int> first, last;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (first.find(x) == first.end())
                first[x] = i; // first occurrence
            last[x] = i;      // always update last occurrence
        }

        while (q--)
        {
            int a, b;
            cin >> a >> b;
            if (!first.count(a) || !first.count(b))
            {
                cout << "NO\n";
            }
            else if (first[a] <= last[b])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

// | i (index) | station (x) | first map                   | last map      |
// | --------- | ----------- | -------------------------   | ------------- |
// | 0         | 3           | first[3] = 0                | last[3] = 0   |
// | 1         | 7           | first[7] = 1                | last[7] = 1   |
// | 2         | 1           | first[1] = 2                | last[1] = 2   |
// | 3         | 5           | first[5] = 3                | last[5] = 3   |
// | 4         | 1           | ❌ first[1] already exists | ✅last[1] = 4 | update
// | 5         | 4           | first[4] = 5                | last[4] = 5   |

// first[x] শুধুমাত্র প্রথমবার যখন x দেখা যায় তখন সেট হয়।
// তাই duplicate (যেমন 1) হলে আবার overwrite হয় না।

// last[x] প্রতিবারই update হয়।
// তাই 1 দুইবার আসায় তার last[1] = 4 (শেষবারের index) হয়েছে।

// first map:
// 3 → 0
// 7 → 1
// 1 → 2 //overwrite হয় না।
// 5 → 3
// 4 → 5

// last map:
// 3 → 0
// 7 → 1
// 1 → 4 //last update a key 1 er value 4 hye gese
// 5 → 3
// 4 → 5
