#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0, ans = -1;
    map<char, int> cnt;

    while (r < n)
    {
        cnt[s[r]]++;
        if (cnt.size() == k)
        {
            ans = max(ans, r - l + 1);
        }
        else
        {
            while (cnt.size() > k && l <= r)
            {
                cnt[s[l]]--;
                if (cnt[s[l]] == 0)
                {
                    cnt.erase(s[l]);
                }
                l++;
            }
        }
        r++;
    }

    cout << ans << "\n";
    return 0;
}
