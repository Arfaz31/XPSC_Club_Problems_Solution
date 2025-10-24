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
        vector<string> strings(n);
        unordered_map<string, long long> freq;

        for (int i = 0; i < n; i++)
        {
            cin >> strings[i];
            freq[strings[i]]++;
        }

        long long ans = 0;

        for (auto &s : strings)
        {
            // First position fixed, second position different
            for (char c = 'a'; c <= 'k'; c++)
            {
                if (c == s[1])
                    continue;
                string t = "";
                t += s[0];
                t += c;
                if (freq.count(t))
                    ans += freq[t];
            }

            // Second position fixed, first position different
            for (char c = 'a'; c <= 'k'; c++)
            {
                if (c == s[0])
                    continue;
                string t = "";
                t += c;
                t += s[1];
                if (freq.count(t))
                    ans += freq[t];
            }
        }

        // Each pair counted twice (i<j and j<i), so divide by 2
        cout << ans / 2 << "\n";
    }

    return 0;
}
