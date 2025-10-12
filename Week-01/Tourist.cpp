#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int min_dist = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            int dist = abs(a - x) + abs(b - y);
            min_dist = min(min_dist, dist);
        }
        cout << min_dist << endl;
    }
    return 0;
}