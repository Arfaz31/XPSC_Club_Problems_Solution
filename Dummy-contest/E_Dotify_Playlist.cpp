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
        int n, k, l;
        cin >> n >> k >> l;
        priority_queue<int> q;
        while (n--)
        {
            int m, li;
            cin >> m >> li;
            if (li == l)
            {
                q.push(m);
            }
        }
        if (q.size() < k)
        {
            cout << -1 << endl;
        }
        else
        {
            int sum = 0;
            while (k--)
            {
                sum += q.top();
                q.pop();
            }
            cout << sum << endl;
        }
    }
    return 0;
}
