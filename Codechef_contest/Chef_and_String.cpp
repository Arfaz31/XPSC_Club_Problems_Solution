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
        long long k;
        cin >> n >> k;
        string s;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
            {
                if (i > 0)
                    s[i] = s[i - 1];
                else if (i < n - 1)
                    s[i] = s[i + 1];
                else
                    s[i] = 'A';
            }
        }

        long long pairS = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                pairS++;
        }

        long long extra = 0;
        if (s[0] == s[n - 1])
            extra = 1;

        long long ans = pairS * k + extra * (k - 1);
        cout << ans << "\n";
    }

    return 0;
}
