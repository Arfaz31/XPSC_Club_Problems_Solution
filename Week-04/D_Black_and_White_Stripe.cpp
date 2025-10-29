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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> ans;
        int l = 0, r = 0, cnt = 0;
        while (r < n)
        {
            if (s[r] == 'W')
            {
                cnt++;
            }
            if (r - l + 1 == k)
            {
                ans.push_back(cnt);
                if (s[l] == 'W')
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        int mn = *min_element(ans.begin(), ans.end());
        cout << mn << endl;
    }
    return 0;
}
