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
        int n;
        cin >> n;
        priority_queue<int> q;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x != 0)
                q.push(x);
            else if (!q.empty())
            {
                ans += q.top();
                q.pop();
            }
        }
        cout << ans << "\n";
    }
}
