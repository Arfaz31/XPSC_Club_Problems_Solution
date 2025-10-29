#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans;
    queue<int> q;
    int l = 0, r = 0;
    while (r < n)
    {
        if (a[r] < 0)
        {
            q.push(a[r]);
        }
        if (r - l + 1 == k)
        {
            if (!q.empty())
            {
                ans.push_back(q.front());
                if (a[l] == q.front())
                    q.pop();
            }
            else
            {
                ans.push_back(0);
            }
            l++;
        }
        r++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
