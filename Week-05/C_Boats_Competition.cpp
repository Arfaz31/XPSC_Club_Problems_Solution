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

        vector<int> w(n);
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }

        sort(w.begin(), w.end());

        int answer = 0;

        // Team sum limit: min = 2, max = 100 (because wi <= 50)
        for (int s = 2; s <= 100; s++)
        {

            int l = 0, r = n - 1;
            int cnt = 0;

            while (l < r)
            {
                int sum = w[l] + w[r];

                if (sum == s)
                {
                    cnt++;
                    l++;
                    r--;
                }
                else if (sum < s)
                {
                    l++;
                }
                else
                { // sum > s
                    r--;
                }
            }

            answer = max(answer, cnt);
        }

        cout << answer << "\n";
    }

    return 0;
}
