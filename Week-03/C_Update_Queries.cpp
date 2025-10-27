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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        set<int> idx;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            idx.insert(x - 1); // 0-based index
        }

        string c;
        cin >> c;
        sort(c.begin(), c.end());

        int i = 0;
        for (int pos : idx)
        {
            s[pos] = c[i++]; // replace with smallest available letter
        }

        cout << s << "\n";
    }

    return 0;
}
