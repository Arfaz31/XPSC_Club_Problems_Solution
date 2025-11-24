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

        vector<int> last(1001, 0);
        vector<int> present;

        // input & record last index for each value
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;

            if (last[x] == 0)
                present.push_back(x); // value first time seen
            last[x] = i;              // store max index
        }

        int ans = -1;

        // sort values descending order by max index (optional small optimization)
        sort(present.begin(), present.end(), [&](int a, int b)
             { return last[a] > last[b]; });

        // check only present values
        for (int i = 0; i < present.size(); i++)
        {
            for (int j = i; j < present.size(); j++)
            {

                int v1 = present[i];
                int v2 = present[j];

                if (__gcd(v1, v2) == 1)
                {
                    ans = max(ans, last[v1] + last[v2]);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
