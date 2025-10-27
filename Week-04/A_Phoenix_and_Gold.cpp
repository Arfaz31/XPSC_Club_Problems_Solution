#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n, x, s, i;
    for (cin >> n; cin >> n >> x;)
    {
        int w[n];
        for (i = 0; i < n; cin >> w[i++])
            ;
        for (s = i = 0; s < x && i < n; s += w[i++])
            ;
        if (s == x && i == n)
            puts("NO");
        else
            for (swap(w[i - (s == x)], w[i]), puts("YES"), i = 0; i < n; i++)
                cout << w[i] << ' ';
    }
}